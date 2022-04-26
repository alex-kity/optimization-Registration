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



CSlamLadirDialog::CSlamLadirDialog(QWidget *parent, MainWindow* _pMainWindow ) :
    ccOverlayDialog(parent),
    ui(new Ui::CSlamLadirDialog)
{
    ui->setupUi(this);
    m_pMainWindow = _pMainWindow;
}

CSlamLadirDialog::~CSlamLadirDialog()
{
    delete ui;
}





void CSlamLadirDialog::on_load_path_clicked()
{
    //get trajectory data
    CGYLCommon _CGYLCommon;
    QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("trajectory！"),"F:",QStringLiteral("file(*txt)"));
    std::map<std::string,lyg::trajectoryData> trajectorys;
    std::vector<lyg::trajectoryData> _vecs = _CGYLCommon.readTrajectoryToxian(fileName.toStdString(),trajectorys);


    //show trajectorydata
    QList<QVector3D> _vec3d;
    QVector3D vec;
    for (int i = 0;i<_vecs.size();i++) {
        vec.setX(_vecs[i].x);
        vec.setY(_vecs[i].y);
        vec.setZ(_vecs[i].z);

        _vec3d.push_back(vec);
    }
    emit SignalsLoadPath(_vec3d);


    //perform
    std::vector<std::pair<unsigned,unsigned>> match;
    GetPointData(_vecs,match);

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


}

void CSlamLadirDialog::SetShowCloudPoint(std::vector<std::pair<unsigned,unsigned>> match)
{
    //load pointcloud
    QString currentOpenDlgFilter = "Point Cloud Library cloud (*.pcd)";
    //file choosing dialog
    QStringList selectedFiles {
        "/home/alexkity/file/0425/1648706385.825838.pcd"
    };
    if (selectedFiles.isEmpty())
        return;

    if(m_pointDir != nullptr)
    {
        //load files
        m_pMainWindow->addToDB(selectedFiles, currentOpenDlgFilter);
    }

}


void CSlamLadirDialog::on_getcurrentpath_clicked()
{

}
