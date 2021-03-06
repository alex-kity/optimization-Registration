
#ifndef COJBCCALGORITHM_H
#define COJBCCALGORITHM_H



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


//local includes
#include "ccConsole.h"
#include "ccEntityAction.h"
#include "ccHistogramWindow.h"
#include "ccInnerRect2DFinder.h"
#include "ccGLWindow.h"


#include <eigen3/Eigen/Eigen>
#include <map>
#include <string>
#include <mutex>
#include "RegistrationTools.h"






// pcl
#pragma warning(disable:4996)
#include <pcl/registration/ia_ransac.h>//采样一致性
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/features/normal_3d.h>
#include <pcl/features/fpfh.h>
#include <pcl/search/kdtree.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/filters/voxel_grid.h>//
#include <pcl/filters/filter.h>//
#include <pcl/registration/icp.h>//icp配准
#include <pcl/visualization/pcl_visualizer.h>//可视化
#include <time.h>//时间
using pcl::NormalEstimation;
using pcl::search::KdTree;







enum CC_SUBSAMPLING_METHOD
{
    RANDOM  = 0,
    SPACE   = 1,
    OCTREE  = 2,
};


typedef struct _ICPPERDATA
{
    double minRMSDecrease ;
    unsigned maxIterationCount;
    unsigned randomSamplingLimit;
    bool removeFarthestPoints ;
    bool useDataSFAsWeights ;
    bool useModelSFAsWeights ;
    bool adjustScale  ;
    int transformationFilters	;
    unsigned finalOverlap ;
    int method;
    int maxThreadCount ;
    bool bisREname = true; 

}ICPPERDATA;

typedef struct _NDTPERDATA
{

}NDTPERDATA;


using namespace CCCoreLib;

// namespace lygs {
// struct SensorTrajectoryData;
// }

// version 1.1
class ccGLMatrix;
struct SensorTrajectoryData;



//线程安全模式
class CObjCCAlgorithm
{
public:
    static CObjCCAlgorithm* getInstance()
    {
        //  std::mutex _mutex;
            //    _mutex.lock();
        pthread_mutex_lock(&mutex);
        if (nullptr == single)
        {
            single = new CObjCCAlgorithm();
        }
            //    _mutex.unlock();
        // pthread_mutex_unlock(&mutex);
        return single;
    }
private:
    static CObjCCAlgorithm *single;
    CObjCCAlgorithm() = default;
    CObjCCAlgorithm(const CObjCCAlgorithm& s) = default;
    CObjCCAlgorithm& operator=(const CObjCCAlgorithm& s) = default;


    ~CObjCCAlgorithm();

    class CRelease
    {
    public:
        ~CRelease() { delete single; }
    };
    static CRelease release;


    static pthread_mutex_t mutex;

    static QWidget *m_pWidget;

public:

    ///
    /// \brief setParentWidget
    /// \param widget
    ///
    void setParentWidget(QWidget * widget){
        m_pWidget = widget;
    }


    ///
    /// \brief SetResample
    /// \param cloud
    /// \return
    ///
    std::vector<ccPointCloud *>  SetResample(ccPointCloud* cloud,float space_t = 0.1f);


    ///
    /// \brief getSampledCloud
    /// \param value
    /// \param samplingMethod
    /// \param cloud
    /// \param m_sfMin
    /// \param m_sfMax
    /// \return
    ///
    template <typename Type>
    CCCoreLib::ReferenceCloud* getSampledCloud(Type value,CC_SUBSAMPLING_METHOD samplingMethod ,
                                               ccGenericPointCloud* cloud, ScalarType m_sfMin,ScalarType m_sfMax);


    ///
    /// \brief AutoICPRegister
    /// \param transcloud
    /// \param dstcloud
    ///
    double AutoICPRegister(ICPPERDATA _icpperdata_t, ccPointCloud* transcloud, ccPointCloud* dstcloud, ccGLMatrix &transMat);


    double 
    FPFHfeature(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_src_o, pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_tgt_o);

    void 
    testPerform();

    double AutoNDTRegister(NDTPERDATA _icpperdata_t,ccPointCloud* transcloud,ccPointCloud* dstcloud,ccGLMatrix& transMat);
    double AutoFPFHRegister(NDTPERDATA _icpperdata_t,ccPointCloud* transcloud,ccPointCloud* dstcloud,ccGLMatrix& transMat);
};


// CObjCCAlgorithm* CObjCCAlgorithm::single = nullptr;
// CObjCCAlgorithm::CRelease CObjCCAlgorithm::release;
// // 互斥锁的初始化
// pthread_mutex_t CObjCCAlgorithm::mutex = PTHREAD_MUTEX_INITIALIZER;


#endif
