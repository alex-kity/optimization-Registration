#include "CSlamLadirDialog.h"
#include "ui_CSlamLadirDialog.h"

#include <KdTree.h>



//CCCoreLib Includes
#include <CloudSamplingTools.h>
#include <Delaunay2dMesh.h>
#include <Jacobi.h>
#include <MeshSamplingTools.h>
#include <NormalDistribution.h>
#include <ParallelSort.h>
#include <PointCloud.h>
#include <ScalarFieldTools.h>
#include <StatisticalTestingTools.h>
#include <WeibullDistribution.h>

//for tests
#include <ChamferDistanceTransform.h>
#include <SaitoSquaredDistanceTransform.h>

//qCC_db
#include <cc2DLabel.h>
#include <cc2DViewportObject.h>
#include <ccCameraSensor.h>
#include <ccColorScalesManager.h>
#include <ccFacet.h>
#include <ccFileUtils.h>
#include <ccGBLSensor.h>
#include <ccImage.h>
#include <ccKdTree.h>
#include <ccPlane.h>
#include <ccProgressDialog.h>
#include <ccQuadric.h>
#include <ccSphere.h>
#include <ccCylinder.h>
#include <ccSubMesh.h>

//qCC_io
#include <ccShiftAndScaleCloudDlg.h>
#include <BinFilter.h>
#include <AsciiFilter.h>
#include <DepthMapFileFilter.h>

//QCC_glWindow
#include <ccGLWidget.h>
#include <ccRenderingTools.h>

//local includes
#include "ccConsole.h"
#include "ccEntityAction.h"
#include "ccHistogramWindow.h"
#include "ccInnerRect2DFinder.h"

//common
#include <ccPickingHub.h>
//common dialogs
#include <ccCameraParamEditDlg.h>
#include <ccDisplayOptionsDlg.h>
#include <ccPickOneElementDlg.h>
#include <ccStereoModeDlg.h>


#include <mainwindow.h>
#include <QFileDialog>

#include "clygnanoflann.hpp"
#include "utils.h"


#include <map>
#include <QProgressDialog>
#include<Eigen/Eigen>

using namespace CCCoreLib;

void GetPointData(std::vector<lyg::trajectoryData> _vecs, std::vector<std::pair<unsigned,unsigned>> &match)
{
    float dis = 10.0f;
    int frontToBackfram = 200;
    int jumpfram = 50;


    PointCloud tmpCloud1;
    {
        unsigned count = static_cast<unsigned>(_vecs.size());
        if (!tmpCloud1.reserve(count * 2)) //not enough memory
            return ;
        for (unsigned i = 0; i < count; i++)
        {
            tmpCloud1.addPoint(CCVector3f(_vecs[i].x, _vecs[i].y, _vecs[i].z));

        }
    }



    //build kdtree for nearest neighbour fast research
    KDTree intermediateTree;
    if (!intermediateTree.buildFromCloud(&tmpCloud1))
        return ;


    for (unsigned i = 0; i < tmpCloud1.size(); i++)
    {
        //    int i = tmpCloud1.size()-1;
        const CCVector3 *q0 = tmpCloud1.getPoint(i);

        std::vector<unsigned> points;
        if (intermediateTree.findPointsLyingToDistance(q0->u, dis,dis,points))
        {

            //get distance is smallst point and index , and compute distance point to point
            std::vector<std::pair<int, double>> IndicesDists;
            for(int j = 0;j<points.size();j++)
            {
                std::cout<<"==points[j]== "<<points[j]<<std::endl;
                const CCVector3 *qcurrentpoint = tmpCloud1.getPoint(points[j]);

                double twopointdistance = std::sqrt((qcurrentpoint->x-q0->x)*(qcurrentpoint->x-q0->x) +
                                                    (qcurrentpoint->y-q0->y)*(qcurrentpoint->y-q0->y) +
                                                    (qcurrentpoint->z-q0->z)*(qcurrentpoint->z-q0->z) );

                IndicesDists.push_back(std::make_pair(points[j], twopointdistance));

            }


            // in order to sort to distance
            std::sort(IndicesDists.begin(), IndicesDists.end(), IndexDistLyg_Sorter());

            // perform
            std::vector<std::pair<int, double>>::iterator iter;
            for(iter = IndicesDists.begin(); iter!=IndicesDists.end(); iter++)
            {
                std::cout<<iter->first<<" sort twopointdistance: "<<iter->second<<std::endl;

                if((int)(i-iter->first)>frontToBackfram)
                {
                    //perform
                    std::cout<<i<<"perform ===+++++=== "<<iter->first<<std::endl;

                    match.push_back(std::make_pair(i, iter->first));

                    i = i+jumpfram;
                    break;
                }

            }


        }

    }

}

void GetPointDataSelf(std::vector<lyg::trajectoryData> _vecs, std::vector<std::pair<unsigned,unsigned>> &match)
{
    float dis = 10.0f;
    int frontToBackfram = 200;
    int jumpfram = 15;

    lyg::PointCloud<double> tmpCloud1;
    {

        tmpCloud1.pts.resize(_vecs.size());
        for (size_t i = 0; i < _vecs.size(); i++)
        {
            tmpCloud1.pts[i].x = _vecs[i].x;
            tmpCloud1.pts[i].y = _vecs[i].y;
            tmpCloud1.pts[i].z = _vecs[i].z;
        }

    }


    // construct a kd-tree index:
    using my_kd_tree_t =  clygnanoflann::KDTreeSingleIndexAdaptor<
    clygnanoflann::L2_Simple_Adaptor<double, lyg::PointCloud<double>>,
    lyg::PointCloud<double>, 3 /* dim */
    >;

    my_kd_tree_t index_kdtree(3 /*dim*/, tmpCloud1, {10 /* max leaf */});


    for (unsigned i = 0; i < tmpCloud1.pts.size(); i++)
    {

        const double query_pt[3] = {tmpCloud1.pts[i].x, tmpCloud1.pts[i].y, tmpCloud1.pts[i].z};
        std::vector<std::pair<uint32_t, double>> ret_matches;
        clygnanoflann::SearchParams params;
        params.sorted = true;

        const size_t nMatches = index_kdtree.radiusSearch(
                    &query_pt[0], dis, ret_matches, params);

        if(nMatches>1)
        {
            // perform
            std::vector<std::pair<uint32_t, double>>::iterator iter;
            for(iter = ret_matches.begin(); iter!=ret_matches.end(); iter++)
            {
                std::cout<<iter->first<<" sort twopointdistance: "<<iter->second<<std::endl;

                if((int)(i-iter->first)>frontToBackfram)
                {
                    //perform
                    std::cout<<i<<"perform ===+++++=== "<<iter->first<<std::endl;

                    //get result
                    match.push_back(std::make_pair(i, iter->first));

                    i = i+jumpfram;
                    break;
                }

            }

        }
        ret_matches.clear();

    }

}

CSlamLadirDialog::CSlamLadirDialog(QWidget *parent, MainWindow* _pMainWindow ) :
    ccOverlayDialog(parent),
    ui(new Ui::CSlamLadirDialog)
{
    ui->setupUi(this);
    m_pMainWindow = _pMainWindow;
    m_currentOpenDlgFilter = "Point Cloud Library cloud (*.pcd)";
    //    connect(ui->pushButtonpointresi,QPushButton::clicked,this,[=]{ emit SignalsRegisterPoint(); });

    //    ui->load_path->setEnabled(false);
}

CSlamLadirDialog::~CSlamLadirDialog()
{
    delete ui;
}



//if(trajectoryMap.count(ins[i].substr(0,ins[i].length()-4)) == 1)
//           {
//               lyg::trajectoryData lidarSe3 = trajectoryMap[ins[i].substr(0, ins[i].size() - 4)];
//               Eigen::Matrix4f Roi2w = getSE3Mat(lidarSe3.yaw*(180.0/M_PI), lidarSe3.pitch*(180.0/M_PI), lidarSe3.roll*(180.0/M_PI), lidarSe3.x, lidarSe3.y, lidarSe3.z, "ypr");
//               pcl::PointCloud<pcl::PointXYZI>::Ptr cloudRGBAllreult = transform<pcl::PointXYZI>(transformed_cloud, Roi2w);
//               transformed_cloud->points.clear();
//               transformed_cloud = cloudRGBAllreult;

//           }

void CSlamLadirDialog::on_load_path_clicked()
{
    //get trajectory data
    CGYLCommon _CGYLCommon;
    QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("trajectory！"),"F:",QStringLiteral("file(*txt)"));
    //            m_recentFiles->addFilePath( fileName );
    std::map<std::string,lyg::trajectoryData> trajectorys;
    m_vecs = _CGYLCommon.readTrajectoryToxian(fileName.toStdString(),trajectorys);


    //show trajectorydata
    QList<QVector3D> _vec3d;
    QVector3D vec;
    for (int i = 0;i<m_vecs.size();i++) {
        vec.setX(m_vecs[i].x);
        vec.setY(m_vecs[i].y);
        vec.setZ(m_vecs[i].z);

        _vec3d.push_back(vec);
    }
    emit SignalsLoadPath(_vec3d);


    //perform
    std::vector<std::pair<unsigned,unsigned>> match;
    GetPointDataSelf(m_vecs,match);

    if(!match.empty())
    {
        SetShowCloudPoint(match);
    }

}




void CSlamLadirDialog::on_pushButton_resample_clicked()
{
    emit SignalsResample();
}

void CSlamLadirDialog::on_setpointfile_clicked()
{
    //    ui->load_path->setEnabled(true);
    //文件夹路径
    m_pointDir = QFileDialog::getExistingDirectory(
                this, "choose src Directory",
                "/");



    if (m_pointDir.isEmpty())
    {
        m_pointDir = nullptr;
        return;
    }
    else
    {
        qDebug() << "srcDirPath=" << m_pointDir;
        m_pointDir += "/";
    }


    if (m_selectedFiles.isEmpty())
        return;

    //    QStringList selectedFiles;

    //    for (int i = 0;i<m_selectedFiles.size();i++) {
    //        selectedFiles.push_back(m_pointDir+m_selectedFiles.at(i));
    //        qDebug()<<m_selectedFiles.at(i);
    //    }

    //    //load files

    ////    loadpoint("obj",selectedFiles, m_currentOpenDlgFilter);
    //    //    m_pMainWindow->addToDB(selectedFiles, m_currentOpenDlgFilter);


}

//#include <ccPointCloud.h>
//#include <pcl/io/pcd_io.h>
//#include <pcl/io/ply_io.h>
//#include <pcl/point_types.h>
//#include <pcl/point_cloud.h>

////cccloud转换成pcl的pointcloud no rgb--重载一下这个函数


////无色的cccloud ---重载一下这个函数

//void PCLcloudToCCcloud(pcl::PointCloud<pcl::PointXYZ>::Ptr pclCloud, ccPointCloud* m_cloud)

//{

//    int num = pclCloud->points.size();

//    m_cloud->reserve(static_cast<unsigned>(num));

//    for (int i = 0; i < num; i++)

//    {

//        CCVector3 P11(pclCloud->points[i].x, pclCloud->points[i].y, pclCloud->points[i].z);
//        m_cloud->addPoint(P11);

//    }

//}


void CSlamLadirDialog::loadpointPCD(const QString objname,	const QStringList& filenames)
{

    //    pcl::PointCloud<pcl::PointXYZ>::Ptr pclCloudALL(new pcl::PointCloud<pcl::PointXYZ>);
    //    ccPointCloud* newGroups = new ccPointCloud(objname);


    //    for ( const QString &filename : filenames )
    //    {
    //        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    //        if (pcl::io::loadPCDFile<pcl::PointXYZ>(filename.toStdString(), *cloud) < 0)
    //        {
    //            PCL_ERROR("Could not read file\n");
    //            continue;
    //        }
    //        *pclCloudALL = * pclCloudALL + *cloud;



    //    }

    //    PCLcloudToCCcloud(pclCloudALL, newGroups);

    //    ccHObject* newGroupname = new ccHObject(objname);
    //    newGroupname->addChild(newGroupname);
    //    m_pMainWindow->addToDB(newGroupname, true, true, false);


}



void CSlamLadirDialog::loadpoint(const QString objname,	const QStringList& filenames,
                                 QString fileFilter/*=QString()*/,
                                 ccGLWindow* destWin/*=0*/)
{

    ccHObject* newGroups = new ccHObject(objname);
    std::vector<ccPointCloud*> _vecpointcloud;

    //to use the same 'global shift' for multiple files
    CCVector3d loadCoordinatesShift(0, 0, 0);
    bool loadCoordinatesTransEnabled = false;

    FileIOFilter::LoadParameters parameters;
    {
        parameters.alwaysDisplayLoadDialog = true;
        parameters.shiftHandlingMode = ccGlobalShiftManager::DIALOG_IF_NECESSARY;
        parameters.coordinatesShift = &loadCoordinatesShift;
        parameters.coordinatesShiftEnabled = &loadCoordinatesTransEnabled;
        parameters.parentWidget = this;
    }

    bool normalsDisplayedByDefault = ccOptions::Instance().normalsDisplayedByDefault;
    FileIOFilter::ResetSesionCounter();

    for ( const QString &filename : filenames )
    {
        CC_FILE_ERROR result = CC_FERR_NO_ERROR;
        ccHObject* newGroup = FileIOFilter::LoadFromFile(filename, parameters, result, fileFilter);

        if (newGroup)
        {
            if (!normalsDisplayedByDefault)
            {
                //disable the normals on all loaded clouds!
                ccHObject::Container clouds;
                newGroup->filterChildren(clouds, true, CC_TYPES::POINT_CLOUD);
                for (ccHObject* cloud : clouds)
                {
                    if (cloud)
                    {
                        static_cast<ccGenericPointCloud*>(cloud)->showNormals(false);
                    }
                }
            }

            if (destWin)
            {
                newGroup->setDisplay_recursive(destWin);
            }


            newGroups->addChild(newGroup);
            //            ccPointCloud* firstCloud = new ccPointCloud()
            //            ccPointCloud* firstCloud = ccHObjectCaster::ToPointCloud(newGroup);
            //            _vecpointcloud.push_back(firstCloud);

        }

        if (result == CC_FERR_CANCELED_BY_USER)
        {
            //stop importing the file if the user has cancelled the current process!
            break;
        }
    }
    //    baseMesh->addChild(baseVertices);




    qDebug()<<"firstCloud";
    //    ccPointCloud* firstCloud = new ccPointCloud(objname);
    //    for (unsigned i = 0; i < _vecpointcloud.size(); ++i)
    //    {
    //        if(_vecpointcloud[i])
    //        {
    //            qDebug()<<"_vecpointcloud is null";

    //            *firstCloud += _vecpointcloud[i];
    //        }
    //    }
    //    if(firstCloud!=nullptr)
    //        newGroups->addChild(firstCloud);


    //    ccHObject* newGroup = nullptr;
    //    ccPointCloud* firstCloud = nullptr;
    //    for (unsigned i = 0; i < newGroups->getChildrenNumber(); ++i)
    //    {
    //        newGroup = newGroups->getChild(i);
    //        ccPointCloud* pc = ccHObjectCaster::ToPointCloud(newGroup);
    //        assert(pc);
    //        *firstCloud += pc;
    //    }

    //qDebug()<<"newGroups";

    //    zoomOn(newDataCloud);
    //    addToDB(newDataCloud);

    m_pMainWindow->addToDB(newGroups, true, true, false);
    //    qDebug()<<"addToDB";

}


void CSlamLadirDialog::SetShowCloudPoint(std::vector<std::pair<unsigned,unsigned>> match)
{
    if (m_pointDir == nullptr || m_pointDir.isEmpty())
    {
        m_pointDir = nullptr;
        QMessageBox message_box( QMessageBox::Question,
                                 tr("warn"),
                                 tr("please setting the point cloud path"),
                                 QMessageBox::Yes | QMessageBox::No,
                                 nullptr );

        if (message_box.exec() == QMessageBox::Yes)
        {
            on_setpointfile_clicked();
        }
    }


    if (m_pointDir.isEmpty())
    {
        m_pointDir = nullptr;
        return;
    }



    //创建一个进度对话框
    QProgressDialog *progressDialog=new QProgressDialog();
    QFont font("cloudpoint",12);
    progressDialog->setFont(font);
    //设置进度对话框采用模态方式进行，即显示进度的同时，其他窗口将不响应输入信号
    progressDialog->setWindowModality(Qt::WindowModal);
    //设置进度对话框出现需等待的时间，默认为4s
    progressDialog->setMinimumDuration(2);
    //设置进度对话框的窗体标题
    progressDialog->setWindowTitle(tr("Please Wait"));
    //设置进度对话框的显示文字信息
    progressDialog->setLabelText(tr("Compute..."));
    //设置进度对话框的“取消”按钮的显示文字
    progressDialog->setCancelButtonText(tr("Cancel"));
    progressDialog->show();


    QString strtype = ".pcd";
    // perform

    std::map<QString,QStringList> _showpointlist;
    std::vector<std::pair<unsigned,unsigned>>::iterator iter;
    for(iter = match.begin(); iter!= match.end(); iter++)
    {

        QStringList selectedFilesMatching;
        QStringList selectedFilesMatched;

        if(!m_vecs.empty())
        {

            // perform front and back of fream pointcloud
            //front
            int index = iter->first - 10;
            for (int i = index;i<index+20;i++) {

                int icurrent = i;
                if(icurrent>=0 && icurrent<m_vecs.size())
                {
                    selectedFilesMatched.push_back(m_pointDir+m_vecs[icurrent].name.data() + strtype);
                    m_selectedFiles.push_back(m_vecs[icurrent].name.data() + strtype);
                }

            }

            //back
            index = iter->second - 10;
            for (int i = index;i<index+20;i++) {

                int icurrent = i;
                if(icurrent>=0 && icurrent<m_vecs.size())
                {
                    selectedFilesMatching.push_back(m_pointDir+m_vecs[icurrent].name.data() + strtype);
                    m_selectedFiles.push_back(m_vecs[i].name.data() + strtype);
                }

            }

            _showpointlist["Matching" + QString(QString::fromLocal8Bit(std::to_string(index).c_str()))] = selectedFilesMatching;
            _showpointlist["Matched" + QString(QString::fromLocal8Bit(std::to_string(index).c_str()))] = selectedFilesMatched;

        }

    }


    if (m_selectedFiles.isEmpty())
        return;

    else
    {
        int num = _showpointlist.size()+1;
        progressDialog->setRange(0,num); //设置进度对话框的步进范围


        int i = 0;
        std::map<QString,QStringList>::iterator iter1;
        for (iter1 = _showpointlist.begin();iter1 != _showpointlist.end();iter1++)
        {
            loadpoint( iter1->first,iter1->second, m_currentOpenDlgFilter);
            //            loadpointPCD(iter1->first,iter1->second);
            progressDialog->setValue(i);
            if(progressDialog->wasCanceled())
                return;
            i++;
        }


        //        loadpoint("Matched",selectedFilesMatched, m_currentOpenDlgFilter);
        //        loadpoint("Matching",selectedFilesMatching, m_currentOpenDlgFilter);
    }


    progressDialog->close();
    delete progressDialog;

}


void CSlamLadirDialog::on_getcurrentpath_clicked()
{

}



void CSlamLadirDialog::on_pushButtonpointresi_clicked()
{
    emit SignalsRegisterPoint();

}
