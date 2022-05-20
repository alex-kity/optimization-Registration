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

#include <eigen3/Eigen/Eigen>

using namespace CCCoreLib;

void GetPointData(std::vector<lygs::trajectoryData> _vecs, std::vector<std::pair<unsigned,unsigned>> &match)
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
            std::sort(IndicesDists.begin(), IndicesDists.end(), lygs::IndexDistLyg_Sorter());

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

void GetPointDataSelf(std::vector<lygs::trajectoryData> _vecs, std::vector<std::pair<unsigned,unsigned>> &match)
{
    float dis = 10.0f;
    int frontToBackfram = 200;
    int jumpfram = 200;

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
                //                std::cout<<iter->first<<" sort twopointdistance: "<<iter->second<<std::endl;

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

    ui->widget_option->hide();
    this->resize(150,30);
}

CSlamLadirDialog::~CSlamLadirDialog()
{
    delete ui;
}



//if(trajectoryMap.count(ins[i].substr(0,ins[i].length()-4)) == 1)
//           {
//               lygs::trajectoryData lidarSe3 = trajectoryMap[ins[i].substr(0, ins[i].size() - 4)];
//               Eigen::Matrix4f Roi2w = getSE3Mat(lidarSe3.yaw*(180.0/M_PI), lidarSe3.pitch*(180.0/M_PI), lidarSe3.roll*(180.0/M_PI), lidarSe3.x, lidarSe3.y, lidarSe3.z, "ypr");
//               pcl::PointCloud<pcl::PointXYZI>::Ptr cloudRGBAllreult = transform<pcl::PointXYZI>(transformed_cloud, Roi2w);
//               transformed_cloud->points.clear();
//               transformed_cloud = cloudRGBAllreult;

//           }




void SqereTrajectory(std::string outfileName,std::vector<string> _vec)
{
    //写入
    ofstream outfile(outfileName);
    if (!outfile.is_open())
    {
        cout << "can not open this file SqereTrajectory:" << outfileName << endl;
        return ;
    }

    for(int i = 0;i<_vec.size();i++)
    {
        outfile << _vec[i]<<"/n";
    }

    outfile.close();
}


//Clockwise is positive
Eigen::Matrix4f getSE3Mat(float yaw, float pitch, float roll, float x , float y, float z, string order)
{

    Eigen::Matrix3f R;
    if(order =="rpy")  //default
        R = Eigen::AngleAxisf(roll * M_PI / 180, Eigen::Vector3f::UnitX()) *
                Eigen::AngleAxisf(pitch * M_PI / 180, Eigen::Vector3f::UnitY()) *
                Eigen::AngleAxisf(yaw * M_PI / 180, Eigen::Vector3f::UnitZ());
    else
        R = Eigen::AngleAxisf(yaw * M_PI / 180, Eigen::Vector3f::UnitZ()) *
                Eigen::AngleAxisf(pitch * M_PI / 180, Eigen::Vector3f::UnitY()) *
                Eigen::AngleAxisf(roll * M_PI / 180, Eigen::Vector3f::UnitX());

    Eigen::Affine3f transform_2 = Eigen::Affine3f::Identity();
    transform_2.translation() << x, y, z;
    transform_2.rotate(R);

    Eigen::Matrix4f camera_pose(transform_2.matrix());
    //std::cout << "camera_pose: " << endl << camera_pose << std::endl;
    return camera_pose;
}


static ccGLMatrix FromEigenMat(const Eigen::Matrix4f& ovrMat)
{
    ccGLMatrix ccMat;
    float* data = ccMat.data();

    data[0] = ovrMat(0,0); data[4] = ovrMat(0,1);   data[8] = ovrMat(0,2); data[12] = ovrMat(0,3);
    data[1] = ovrMat(1,0); data[5] = ovrMat(1,1);	data[9] = ovrMat(1,2); data[13] = ovrMat(1,3);
    data[2] = ovrMat(2,0); data[6] = ovrMat(2,1);	data[10] = ovrMat(2,2); data[14] = ovrMat(2,3);
    data[3] = ovrMat(3,0); data[7] = ovrMat(3,1);	data[11] = ovrMat(3,2); data[15] = ovrMat(3,3);


    return ccMat;
}

void CSlamLadirDialog::on_load_path_clicked()
{
    //get trajectory data
    lygs::CGYLCommon _CGYLCommon;
    //    background-color: rgb(115, 210, 22);
    QFileDialog _FileDialog;
    //    _FileDialog.setStyleSheet("background-color: rgb(200, 200, 200)");
    _FileDialog.setStyleSheet("color: rgb(241, 241, 241);");
    QString fileName = _FileDialog.getOpenFileName(nullptr,QStringLiteral("trajectory！"),"F:",QStringLiteral("file(*txt)"));



    if(!fileName.isEmpty())
    {
        m_filename = fileName.toStdString();
        //        m_recentFiles->addFilePath( fileName );

        m_vecs.clear();
        g_trajectoryMap.clear();
        m_selectedFiles.clear();
        m_IndextrajectoryMap.clear();

        std::map<std::string,lygs::trajectoryData> trajectorys;
        m_vecs = _CGYLCommon.readTrajectoryToxian1(m_filename,g_trajectoryMap);



        for (int i = 0;i<m_vecs.size();i++) {
            lygs::trajectoryData lidarSe3 = m_vecs[i];
            Eigen::Matrix4f Roi2w = getSE3Mat(lidarSe3.yaw*(180.0/M_PI), lidarSe3.pitch*(180.0/M_PI), lidarSe3.roll*(180.0/M_PI), lidarSe3.x, lidarSe3.y, lidarSe3.z, "ypr");
            ccGLMatrix transTemp = FromEigenMat(Roi2w);
            m_IndextrajectoryMap[i] = transTemp;
        }


        //    m_pMainWindow->ADDRecently(fileName);
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

        ui->widget_option->show();

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
                nullptr, "choose src Directory",
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

#include <ccPointCloud.h>


ccPointCloud* MeragePoint(ccHObject* newGroups)
{
    qDebug()<<" start  ";
    qDebug()<<newGroups->getName();
    ccHObject* newGroup = nullptr;
    ccPointCloud* firstCloud = new ccPointCloud(newGroups->getName());

    //    ccConsole::Error("currentOpenDlgFilter =====: ");


    for (unsigned i = 0; i < newGroups->getChildrenNumber(); ++i)
    {
        newGroup = newGroups->getChild(i);
        //        ccConsole::Error(newGroups->getName().toLatin1().data());
        //qstr.toLatin1().data();

        ccPointCloud* pc = static_cast<ccPointCloud*>(newGroup);
        //        pc->point()
        //        ccPointCloud* pc = ccHObjectCaster::ToPointCloud(newGroup);
        ccConsole::Error((QString::number(pc->size())+"---"+pc->getName()).toLatin1().data());
        //        ccConsole::Error("===================================");
        //        assert(pc);
        //        *firstCloud += pc;

        for (int i = 0; i < pc->size(); i++)
        {

            CCVector3 P11(pc->getPoint(i)->x, pc->getPoint(i)->y, pc->getPoint(i)->z);
            firstCloud->addPoint(P11);

        }

        ccConsole::Error((QString::number(firstCloud->size())+"---"+pc->getName()).toLatin1().data());

        //        ccConsole::Error(firstCloud->getName().toLatin1().data());
    }


    if(firstCloud != nullptr)
        firstCloud->setName(newGroups->getName());



    return firstCloud;

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
}





// this pointcloud transform form origin to world
ccPointCloud*  CSlamLadirDialog::changeMat(ccPointCloud* obj,std::string strfilename)
{
    std::string  str = strfilename.substr(0,strfilename.length()-4);

    if(g_trajectoryMap.count(str) == 1)
    {

        lygs::trajectoryData lidarSe3 = g_trajectoryMap[strfilename.substr(0, strfilename.size() - 4)];
        Eigen::Matrix4f Roi2w = getSE3Mat(lidarSe3.yaw*(180.0/M_PI), lidarSe3.pitch*(180.0/M_PI), lidarSe3.roll*(180.0/M_PI), lidarSe3.x, lidarSe3.y, lidarSe3.z, "ypr");

        ccGLMatrix transTemp = FromEigenMat(Roi2w);

        obj->applyRigidTransformation(transTemp);

        //        pcl::PointCloud<pcl::PointXYZI>::Ptr cloudRGBAllreult = transform<pcl::PointXYZI>(cloudA, Roi2w);

    }

    return obj;
}



//// this pointcloud transform form origin to world
//ccPointCloud*  CSlamLadirDialog::GetOrignMat(int index,ccGLMatrix &transTemp)
//{

//    if(g_trajectoryMap.count(str) == 1)
//    {

//        lygs::trajectoryData lidarSe3 = g_trajectoryMap[strfilename.substr(0, strfilename.size() - 4)];
//        Eigen::Matrix4f Roi2w = getSE3Mat(lidarSe3.yaw*(180.0/M_PI), lidarSe3.pitch*(180.0/M_PI), lidarSe3.roll*(180.0/M_PI), lidarSe3.x, lidarSe3.y, lidarSe3.z, "ypr");

//        ccGLMatrix transTemp = FromEigenMat(Roi2w);

//        obj->applyRigidTransformation(transTemp);

//        //        pcl::PointCloud<pcl::PointXYZI>::Ptr cloudRGBAllreult = transform<pcl::PointXYZI>(cloudA, Roi2w);

//    }
//}








void CSlamLadirDialog::loadpoint(const QString objname,	const QStringList& filenames,QString dir,
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
        ccHObject* newGroup = FileIOFilter::LoadFromFile(dir +filename, parameters, result, fileFilter);

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


            for (unsigned i = 0; i < newGroup->getChildrenNumber(); ++i)
            {

                ccHObject* cloud = newGroup->getChild(i);

                //获取选中的点云对象

                if (!cloud || !cloud->isA(CC_TYPES::POINT_CLOUD)) {

                    ccConsole::Error((QString::number(cloud->getClassID())+"---"+cloud->getName()).toLatin1().data());
                    //                    continue;
                }
                else
                {


                    //                    ccPointCloud *pc = ccHObjectCaster::ToPointCloud(cloud);

                    ccPointCloud *pc =changeMat(ccHObjectCaster::ToPointCloud(cloud),filename.toStdString());

                    //                    ccScalarField *sf = pc->getCurrentDisplayedScalarField();
                    _vecpointcloud.push_back(pc);
                    //                    ccConsole::Error((QString::number(pc->size())+"---"+pc->getName()).toLatin1().data());
                }



            }
            //分类，继承关系，类型转换
        }

        if (result == CC_FERR_CANCELED_BY_USER)
        {
            //stop importing the file if the user has cancelled the current process!
            break;
        }
    }
    //    baseMesh->addChild(baseVertices);





    if(!_vecpointcloud.empty())
    {
        ccPointCloud* firstCloud = new ccPointCloud(objname);

        for(int i = 0;i<_vecpointcloud.size();i++)
        {
            *firstCloud += _vecpointcloud[i];
        }

        m_pMainWindow->addToDB(firstCloud, true, true, false);
    }


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
    QFont font("compute Registration.....",12);
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
            //1
            int index = iter->first - 5;
            for (int i = index;i<index+20;i++) {

                int icurrent = i;
                if(icurrent>=0 && icurrent<m_vecs.size())
                {
                    //                    selectedFilesMatched.push_back(m_pointDir+m_vecs[icurrent].name.data() + strtype);
                    selectedFilesMatched.push_back(m_vecs[icurrent].name.data() + strtype);

                    m_selectedFiles.push_back(m_vecs[icurrent].name.data() + strtype);
                }

            }


            //2
            index = iter->second - 15;
            for (int i = index;i<index+20;i++) {

                int icurrent = i;
                if(icurrent>=0 && icurrent<m_vecs.size())
                {
                    //                    selectedFilesMatching.push_back(m_pointDir+m_vecs[icurrent].name.data() + strtype);
                    selectedFilesMatching.push_back(m_vecs[icurrent].name.data() + strtype);
                    m_selectedFiles.push_back(m_vecs[i].name.data() + strtype);
                }

            }


            std::string flagname = "N-" +std::to_string(iter->second)+"-"+std::to_string(iter->first);
            _showpointlist["Matched" + QString::number(iter->second) +QString(QString::fromLocal8Bit(flagname.c_str()))] = selectedFilesMatched;
            _showpointlist["Matching" + QString::number(iter->first) + QString(QString::fromLocal8Bit(flagname.c_str()))] = selectedFilesMatching;

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
            loadpoint( iter1->first,iter1->second, m_pointDir,m_currentOpenDlgFilter);
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

void CSlamLadirDialog::on_btnclose_clicked()
{
    this->close();
}

void CSlamLadirDialog::on_btnAuto_clicked()
{

}

void CSlamLadirDialog::on_pushButton_clicked()
{

}






//#include <ccPointCloud.h>
//#include <pcl/io/pcd_io.h>
//#include <pcl/io/ply_io.h>
//#include <pcl/point_types.h>
//#include <pcl/point_cloud.h>


//////cccloud转换成pcl的pointcloud no rgb--重载一下这个函数


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

////----------------------pointCloud转ccCloud---------------------

//void PCLcloudToCCcloudRGB(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pclCloud, ccPointCloud* m_cloud)

//{

//    int num = pclCloud->points.size();

//    m_cloud->reserve(static_cast<unsigned>(num));

//    for (int i = 0; i < num; i++)

//    {

//        CCVector3 P11(pclCloud->points[i].x, pclCloud->points[i].y, pclCloud->points[i].z);

//        m_cloud->addPoint(P11);



//        ccColor::Rgb rgb;//定义一个颜色

//        if (pclCloud->points[0].r <= 1 && pclCloud->points[0].g <= 1)

//        {

//            rgb = ccColor::Rgb(pclCloud->points[i].r*255, pclCloud->points[i].g*255, pclCloud->points[i].b*255);

//        }

//        else

//        {

//            rgb = ccColor::Rgb(pclCloud->points[i].r, pclCloud->points[i].g, pclCloud->points[i].b);

//        }

//        m_cloud->resizeTheRGBTable(true);

//        m_cloud->setPointColor(i, rgb);

//    }

//}


//void PCLcloudToCCcloudI(pcl::PointCloud<pcl::PointXYZI>::Ptr pclCloud, ccPointCloud* m_cloud)

//{

//    //    int num = pclCloud->points.size();

//    //    m_cloud->reserve(static_cast<unsigned>(num));


//    //    for (int i = 0; i < num; i++)

//    //    {

//    //        CCVector3 P11(pclCloud->points[i].x, pclCloud->points[i].y, pclCloud->points[i].z);
//    //        m_cloud->addPoint(P11);


//    //        static const int lodIconSize = 32;
//    //        static const int margin = 6;
//    //        static const unsigned lodIconParts = 12;
//    //        static const float lodPartsRadius = 3.0f;


//    //        static const float radius = lodIconSize / 2.0f - lodPartsRadius;
//    //        static const float alpha = static_cast<float>((2 * M_PI) / lodIconParts);



//    //            float intensity = pclCloud->intensity;
//    //            intensity /= ccColor::MAX;


//    //            float col[3] = {	textCol.rgb[0] * intensity,
//    //                                textCol.rgb[1] * intensity,
//    //                                textCol.rgb[2] * intensity };

//    //        //current intensity (x3)
//    //        int I = static_cast<int>(R) + static_cast<int>(G) + static_cast<int>(B);
//    //        if (I == 0)
//    //        {
//    //            continue; //black remains black!
//    //        }


//    //    }



//    //    int R = 0;
//    //    int G = 0;
//    //    int B = 0;

//    //    int num = pclCloud->points.size();

//    //    m_cloud->reserve(static_cast<unsigned>(num));

//    //    for (int i = 0; i < num; i++)

//    //    {

//    //         CCVector3 P11(pclCloud->points[i].x, pclCloud->points[i].y, pclCloud->points[i].z);

//    //         m_cloud->addPoint(P11);


//    //        float intensity = pclCloud->intensity;
//    //         ccColor::Rgb rgb;//定义一个颜色

//    //         rgb = ccColor::Rgb(intensity, pclCloud->points[i].g, pclCloud->points[i].b);

//    ////         if (pclCloud->points[0].r <= 1 && pclCloud->points[0].g <= 1)

//    ////         {

//    ////              rgb = ccColor::Rgb(pclCloud->points[i].r*255, pclCloud->points[i].g*255, pclCloud->points[i].b*255);

//    ////         }

//    ////         else

//    ////         {

//    ////              rgb = ccColor::Rgb(pclCloud->points[i].r, pclCloud->points[i].g, pclCloud->points[i].b);

//    ////         }

//    //         m_cloud->resizeTheRGBTable(true);

//    //         m_cloud->setPointColor(i, rgb.rgb);

//    //    }



//}




//void CSlamLadirDialog::loadpointPCD(const QString objname,	const QStringList& filenames)
//{

//    //    pcl::PointCloud<pcl::PointXYZ>::Ptr pclCloudALL(new pcl::PointCloud<pcl::PointXYZ>);
//    //    ccPointCloud* newGroups = new ccPointCloud(objname);


//    //    for ( const QString &filename : filenames )
//    //    {
//    //        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
//    //        if (pcl::io::loadPCDFile<pcl::PointXYZ>(filename.toStdString(), *cloud) < 0)
//    //        {
//    //            PCL_ERROR("Could not read file\n");
//    //            continue;
//    //        }
//    //        *pclCloudALL = * pclCloudALL + *cloud;



//    //    }

//    //    PCLcloudToCCcloud(pclCloudALL, newGroups);

//    //    ccHObject* newGroupname = new ccHObject(objname);
//    //    newGroupname->addChild(newGroupname);
//    //    m_pMainWindow->addToDB(newGroupname, true, true, false);


//}


void CSlamLadirDialog::on_m_btnTransFrom_clicked()
{
    emit SignalsTransFrom();
}

void CSlamLadirDialog::on_SavePath_clicked()
{
    emit SignalsSavePath();
}

void CSlamLadirDialog::on_btn_TestPath_clicked()
{
    //get trajectory data
    lygs::CGYLCommon _CGYLCommon;
    //    background-color: rgb(115, 210, 22);
    QFileDialog _FileDialog;
    //    _FileDialog.setStyleSheet("background-color: rgb(200, 200, 200)");
    _FileDialog.setStyleSheet("color: rgb(241, 241, 241);");
    QString fileName = _FileDialog.getOpenFileName(nullptr,QStringLiteral("trajectory！"),"F:",QStringLiteral("file(*txt)"));

    if(!fileName.isEmpty())
    {
        m_filenametnt = fileName.toStdString();
        std::map<std::string,lygs::trajectoryData> trajectorys;
        std::vector<lygs::trajectoryData>  m_vecs = _CGYLCommon.readTrajectoryToxian1(fileName.toStdString(),trajectorys);


        //    m_pMainWindow->ADDRecently(fileName);
        //show trajectorydata
        QList<QVector3D> _vec3d;
        QVector3D vec;
        for (int i = 0;i<m_vecs.size();i++) {
            vec.setX(m_vecs[i].x);
            vec.setY(m_vecs[i].y);
            vec.setZ(m_vecs[i].z);

            _vec3d.push_back(vec);
        }
        emit SignalsTestLoadPath(_vec3d);

    }

}
