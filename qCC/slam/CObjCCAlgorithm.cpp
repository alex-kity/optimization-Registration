#include "CObjCCAlgorithm.h"


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
#include <KdTree.h>

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

#include "ccHObject.h"
#include "ccPointCloud.h"
#include "ccSubsamplingDlg.h" //Aurelien BEY"


#include <eigen3/Eigen/Eigen>
#include <map>
#include <string>
#include <qstring.h>


#include "ccRegistrationDlg.h"
//#include "ccHObjectContext.h"
#include "ccHObject.h"
#include "ccRegistrationTools.h"
#include "ccHObjectCaster.h"



#include <pcl/features/fpfh.h>
#include <pcl/features/fpfh_omp.h>

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/ndt.h>
// #include <pcl/filters/approximate_voxel_grid.h>
// #include <pcl/visualization/pcl_visualizer.h>
// #include <boost/thread/thread.hpp>


CObjCCAlgorithm::~CObjCCAlgorithm()
{
    pthread_mutex_destroy(&mutex); // 释放锁
}





///
/// \brief CSlamLadirDialog::getSampledCloud
/// \param value
/// \param samplingMethod
/// \param cloud
/// \param m_sfMin
/// \param m_sfMax
/// \return
///
template <typename Type>
CCCoreLib::ReferenceCloud* CObjCCAlgorithm::getSampledCloud(Type value,CC_SUBSAMPLING_METHOD samplingMethod ,ccGenericPointCloud* cloud, ScalarType m_sfMin,ScalarType m_sfMax)
{ 

    CCCoreLib::GenericProgressCallback* progressCb/*=0*/;
    ccProgressDialog pDlg(false, nullptr);
    pDlg.setAutoClose(false);

    pDlg.setMethodTitle(QString("Subsampling"));

    progressCb = &pDlg;


    if (!cloud || cloud->size() == 0)
    {
        ccLog::Warning("[ccSubsamplingDlg::getSampledCloud] Invalid input cloud!");
        return nullptr;
    }

    switch (samplingMethod)
    {
    case RANDOM:
    {
        assert(value >= 0);
        unsigned count = static_cast<unsigned>(value);
        return CCCoreLib::CloudSamplingTools::subsampleCloudRandomly(	cloud,
                                                                        count,
                                                                        progressCb);
    }
        break;

    case SPACE:
    {
        ccOctree::Shared octree = cloud->getOctree();
        if (!octree)
            octree = cloud->computeOctree(progressCb);
        if (octree)
        {
            PointCoordinateType minDist = static_cast<PointCoordinateType>(value);
            CCCoreLib::CloudSamplingTools::SFModulationParams modParams;
            modParams.enabled = true;
            if (modParams.enabled)
            {
                double deltaSF = static_cast<double>(m_sfMax) - m_sfMin;
                assert(deltaSF >= 0);
                if ( CCCoreLib::GreaterThanEpsilon( deltaSF ) )
                {
                    double sfMinSpacing = minDist;
                    double sfMaxSpacing = minDist;
                    modParams.a = (sfMaxSpacing - sfMinSpacing) / deltaSF;
                    modParams.b = sfMinSpacing - modParams.a * m_sfMin;
                }
                else
                {
                    modParams.a = 0.0;
                    modParams.b = m_sfMin;
                }
            }
            return CCCoreLib::CloudSamplingTools::resampleCloudSpatially(	cloud,
                                                                                minDist,
                                                                                modParams,
                                                                                octree.data(),
                                                                                progressCb);
        }
        else
        {
            ccLog::Warning(QString("[ccSubsamplingDlg::getSampledCloud] Failed to compute octree for cloud '%1'").arg(cloud->getName()));
        }
    }
        break;

    case OCTREE:
    {
        ccOctree::Shared octree = cloud->getOctree();
        if (!octree)
            octree = cloud->computeOctree(progressCb);
        if (octree)
        {
            assert(value >= 0);
            unsigned char level = static_cast<unsigned char>(value);
            return CCCoreLib::CloudSamplingTools::subsampleCloudWithOctreeAtLevel(	cloud,
                                                                                        level,
                                                                                        CCCoreLib::CloudSamplingTools::NEAREST_POINT_TO_CELL_CENTER,
                                                                                        progressCb,
                                                                                        octree.data());
        }
        else
        {
            ccLog::Warning(QString("[ccSubsamplingDlg::getSampledCloud] Failed to compute octree for cloud '%1'").arg(cloud->getName()));
        }
    }
        break;
    }

    //something went wrong!
    return nullptr;
}





std::vector<ccPointCloud *>  CObjCCAlgorithm::SetResample(ccPointCloud* cloud,float space_t )
{

    CC_SUBSAMPLING_METHOD samplingMethod =  CC_SUBSAMPLING_METHOD::SPACE;
    int random = 100.0;
    int octree_t = 1000000;

    std::vector<ccPointCloud *> resultingClouds;
    //find candidates
    std::vector<ccPointCloud*> clouds;
    unsigned maxPointCount = 0;
    double maxCloudRadius = 0;
    ScalarType sfMin = CCCoreLib::NAN_VALUE;
    ScalarType sfMax = CCCoreLib::NAN_VALUE;
    {
        clouds.push_back(cloud);

        maxPointCount = std::max<unsigned>(maxPointCount, cloud->size());
        maxCloudRadius = std::max<double>(maxCloudRadius, cloud->getOwnBB().getDiagNorm());

        //we also look for the min and max sf values
        ccScalarField* sf = cloud->getCurrentDisplayedScalarField();
        if (sf)
        {
            if (!ccScalarField::ValidValue(sfMin) || sfMin > sf->getMin())
                sfMin = sf->getMin();
            if (!ccScalarField::ValidValue(sfMax) || sfMax < sf->getMax())
                sfMax = sf->getMax();
        }



    }

    if (clouds.empty())
    {
        ccConsole::Error(QString("Select at least one point cloud!"));
        return resultingClouds;
    }


    //process clouds

    // ccHObject::Container resultingClouds;
    {

        bool errors = false;

        QElapsedTimer eTimer;
        eTimer.start();

        for (size_t i = 0; i < clouds.size(); ++i)
        {
            ccPointCloud* cloud = clouds[i];
            CCCoreLib::ReferenceCloud *sampledCloud = getSampledCloud<float>(space_t,samplingMethod,cloud,sfMin,sfMax);
            
            if (!sampledCloud)
            {
                ccConsole::Warning(QString("[Subsampling] Failed to subsample cloud '%1'!").arg(cloud->getName()));
                errors = true;
                continue;
            }

            int warnings = 0;
            ccPointCloud *newPointCloud = cloud->partialClone(sampledCloud,&warnings);

            delete sampledCloud;
            sampledCloud = nullptr;

            if (newPointCloud)
            {
                newPointCloud->setName(cloud->getName() + QString(".subsampled"));
                newPointCloud->copyGlobalShiftAndScale(*cloud);
                newPointCloud->setDisplay(cloud->getDisplay());
                newPointCloud->prepareDisplayForRefresh();
                if (cloud->getParent())
                    cloud->getParent()->addChild(newPointCloud);
                cloud->setEnabled(false);

                newPointCloud->prepareDisplayForRefresh();
                resultingClouds.push_back(newPointCloud);



                if (warnings)
                {
                    ccLog::Warning(QString("[Subsampling] Not enough memory: colors, normals or scalar fields may be missing!"));
                    errors = true;
                }
            }
            else
            {
                ccLog::Error(QString("Not enough memory!"));
                break;
            }
        }

        ccLog::Print("[Subsampling] Timing: %3.3f s.",eTimer.elapsed()/1000.0);

        if (errors)
        {
            ccLog::Error(QString("Errors occurred (see console)"));
        }
    }


    return resultingClouds;

}






double CObjCCAlgorithm::AutoICPRegister(ICPPERDATA _icpperdata_t,ccPointCloud* transcloud,ccPointCloud* dstcloud,ccGLMatrix& transMat)
{

    ccHObject* data = static_cast<ccHObject*>(transcloud);
    ccHObject* model = static_cast<ccHObject*>(dstcloud);
    // FPFHfeature(data,model)
    double minRMSDecrease             = _icpperdata_t.minRMSDecrease;
    unsigned maxIterationCount        = _icpperdata_t.maxIterationCount;
    unsigned randomSamplingLimit      = _icpperdata_t.randomSamplingLimit;
    bool removeFarthestPoints         = _icpperdata_t.removeFarthestPoints;
    bool useDataSFAsWeights           = _icpperdata_t.useDataSFAsWeights;
    bool useModelSFAsWeights          = _icpperdata_t.useModelSFAsWeights;
    bool adjustScale                  = _icpperdata_t.adjustScale;
    int transformationFilters	      = _icpperdata_t.transformationFilters;
    unsigned finalOverlap             = _icpperdata_t.finalOverlap;
    CCCoreLib::ICPRegistrationTools::CONVERGENCE_TYPE method;

    if(_icpperdata_t.method == 0)
    {
        method = CCCoreLib::ICPRegistrationTools::CONVERGENCE_TYPE::MAX_ERROR_CONVERGENCE ;
    }
    else{
        method = CCCoreLib::ICPRegistrationTools::CONVERGENCE_TYPE::MAX_ITER_CONVERGENCE;
    }

    int maxThreadCount  = _icpperdata_t.maxThreadCount;


    //   double minRMSDecrease = rDlg.getMinRMSDecrease();
    if (std::isnan(minRMSDecrease))
    {
        ccLog::Error(QString("Invalid minimum RMS decrease value"));
        return 0.0f;
    }
    if (minRMSDecrease < ccRegistrationDlg::GetAbsoluteMinRMSDecrease())
    {
        minRMSDecrease = ccRegistrationDlg::GetAbsoluteMinRMSDecrease();
        ccLog::Error(QString("Minimum RMS decrease value is too small.\n%1 will be used instead (numerical accuracy limit).").arg(minRMSDecrease, 0, 'E', 1));
        // rDlg.setMinRMSDecrease(minRMSDecrease);
    }


    double finalError = 0.0;
    double finalScale = 1.0;
    unsigned finalPointCount = 0;

    if (ccRegistrationTools::ICP(	data,
                                        model,
                                        transMat,
                                        finalScale,
                                        finalError,
                                        finalPointCount,
                                        minRMSDecrease,
                                        maxIterationCount,
                                        randomSamplingLimit,
                                        removeFarthestPoints,
                                        method,
                                        adjustScale,
                                        finalOverlap / 100.0,
                                        useDataSFAsWeights,
                                        useModelSFAsWeights,
                                        transformationFilters,
                                        maxThreadCount,
                                        nullptr))
    {
        QString rmsString = QString("Final RMS: %1 (computed on %2 points)").arg(finalError).arg(finalPointCount);
        ccLog::Print(QString("[Register] ") + rmsString);

        QStringList summary;
        summary << rmsString;
        summary << "----------------";
        std::cout<<"rmsString: "<<rmsString.toStdString()<<std::endl;

        //transformation matrix
        {
            summary << "Transformation matrix";
            summary << transMat.toString(3, '\t'); //low precision, just for display
            summary << "----------------";

            ccLog::Print(QString("[Register] Applied transformation matrix:"));
            ccLog::Print(transMat.toString(12, ' ')); //full precision
            ccLog::Print(QString("Hint: copy it (CTRL+C) and apply it - or its inverse - on any entity with the 'Edit > Apply transformation' tool"));
        }

        if (adjustScale)
        {
            QString scaleString = QString("Scale: %1 (already integrated in above matrix!)").arg(finalScale);
            ccLog::Warning(QString("[Register] ") + scaleString);
            summary << scaleString;
        }
        else
        {
            ccLog::Print(QString("[Register] Scale: fixed (1.0)"));
            summary << QString("Scale: fixed (1.0)");
        }

        //overlap
        summary << "----------------";
        QString overlapString = QString("Theoretical overlap: %1%").arg(finalOverlap);
        ccLog::Print(QString("[Register] ") + overlapString);
        summary << overlapString;

        summary << "----------------";
        summary << QString("This report has been output to Console (F8)");

        //cloud to move
        ccGenericPointCloud* pc = nullptr;

        if (data->isKindOf(CC_TYPES::POINT_CLOUD))
        {
            pc = ccHObjectCaster::ToGenericPointCloud(data);
        }
        else if (data->isKindOf(CC_TYPES::MESH))
        {
            ccGenericMesh* mesh = ccHObjectCaster::ToGenericMesh(data);
            pc = mesh->getAssociatedCloud();

            //warning: point cloud is locked!
            if (pc->isLocked())
            {
                pc = nullptr;
                //we ask the user about cloning the 'data' mesh
                QMessageBox::StandardButton result = QMessageBox::question(	nullptr,
                                                                                QString("Registration"),
                                                                                QString("Data mesh vertices are locked (they may be shared with other meshes): Do you wish to clone this mesh to apply transformation?"),
                                                                                QMessageBox::Ok | QMessageBox::Cancel,
                                                                                QMessageBox::Ok);

                //continue process?
                if (result == QMessageBox::Ok)
                {
                    ccGenericMesh* newMesh = nullptr;
                    if (mesh->isA(CC_TYPES::MESH))
                        newMesh = static_cast<ccMesh*>(mesh)->cloneMesh();
                    else
                    {
                        //FIXME TODO
                        ccLog::Error(QString("Doesn't work on sub-meshes yet!"));
                    }

                    if (newMesh)
                    {
                        newMesh->setDisplay(data->getDisplay());
                        // addToDB(newMesh);
                        data = newMesh;
                        pc = newMesh->getAssociatedCloud();
                    }
                    else
                    {
                        ccLog::Error(QString("Failed to clone 'data' mesh! (not enough memory?)"));
                    }
                }
            }
        }

        //if we managed to get a point cloud to move!
        if (pc)
        {
            //            //we temporarily detach cloud, as it may undergo
            //            //'severe' modifications (octree deletion, etc.) --> see ccPointCloud::applyRigidTransformation
            //            ccHObjectContext objContext = removeObjectTemporarilyFromDBTree(pc);
            //            pc->applyRigidTransformation(transMat);
            //            putObjectBackIntoDBTree(pc,objContext);

            pc->applyRigidTransformation(transMat);

            //don't forget to update mesh bounding box also!
            if (data->isKindOf(CC_TYPES::MESH))
                ccHObjectCaster::ToGenericMesh(data)->refreshBB();

            //don't forget global shift
            ccGenericPointCloud* refPc = ccHObjectCaster::ToGenericPointCloud(model);
            if (refPc)
            {
                if (refPc->isShifted())
                {
                    const CCVector3d& Pshift = refPc->getGlobalShift();
                    const double& scale = refPc->getGlobalScale();
                    pc->setGlobalShift(Pshift);
                    pc->setGlobalScale(scale);
                    ccLog::Warning(QString("[ICP] Aligned entity global shift has been updated to match the reference: (%1,%2,%3) [x%4]").arg(Pshift.x).arg(Pshift.y).arg(Pshift.z).arg(scale));
                }
                else if (pc->isShifted()) //we'll ask the user first before dropping the shift information on the aligned cloud
                {
                    if (QMessageBox::question(nullptr, QString("Drop shift information?"), QString("Aligned entity is shifted but reference cloud is not: drop global shift information?"), QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes)
                    {
                        pc->setGlobalShift(0, 0, 0);
                        pc->setGlobalScale(1.0);
                        ccLog::Warning(QString("[ICP] Aligned entity global shift has been reset to match the reference!"));
                    }
                }
            }

            data->prepareDisplayForRefresh_recursive();
            if(_icpperdata_t.bisREname)
            {
                data->setName(data->getName() + QString(".registered"));

            }
            else
            {
                data->setName(data->getName());
            }
            // zoomOn(data);

        }
        // rmsString
        //pop-up summary
        //QMessageBox::information(nullptr, QString("Registration info"), summary.join("\n"));
        // forceConsoleDisplay();
    }


    return finalError;
}




//由旋转平移矩阵计算旋转角度
void matrix2angle(Eigen::Matrix4f &result_trans, Eigen::Vector3f &result_angle)
{
    double ax, ay, az;
    if (result_trans(2, 0) == 1 || result_trans(2, 0) == -1)
    {
        az = 0;
        double dlta;
        dlta = atan2(result_trans(0, 1), result_trans(0, 2));
        if (result_trans(2, 0) == -1)
        {
            ay = M_PI / 2;
            ax = az + dlta;
        }
        else
        {
            ay = -M_PI / 2;
            ax = -az + dlta;
        }
    }
    else
    {
        ay = -asin(result_trans(2, 0));
        ax = atan2(result_trans(2, 1) / cos(ay), result_trans(2, 2) / cos(ay));
        az = atan2(result_trans(1, 0) / cos(ay), result_trans(0, 0) / cos(ay));
    }
    result_angle << ax, ay, az;

    cout << "x轴旋转角度：" << ax << endl;
    cout << "y轴旋转角度：" << ay << endl;
    cout << "z轴旋转角度：" << az << endl;
}




//点云可视化
void visualize_pcd(pcl::PointCloud<pcl::PointXYZ>::Ptr pcd_src, pcl::PointCloud<pcl::PointXYZ>::Ptr pcd_tgt, pcl::PointCloud<pcl::PointXYZ>::Ptr pcd_final)
{

    //创建初始化目标
    pcl::visualization::PCLVisualizer viewer("registration Viewer");


    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> src_h(pcd_src, 0, 255, 0);
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> tgt_h(pcd_tgt, 255, 0, 0);
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> final_h(pcd_final, 0, 0, 255);
    viewer.setBackgroundColor(255, 255, 255);
    viewer.addPointCloud(pcd_src, src_h, "source cloud");
    viewer.addPointCloud(pcd_tgt, tgt_h, "tgt cloud");
    viewer.addPointCloud(pcd_final, final_h, "final cloud");

    while (!viewer.wasStopped())
    {
        viewer.spinOnce(100);
        // boost::this_thread::sleep(boost::posix_time::microseconds(100000));
    }
}





pcl::PointCloud<pcl::FPFHSignature33> ::Ptr compute_fpfh_feature(pcl::PointCloud<pcl::PointXYZ>::Ptr input_cloud,pcl::search::KdTree<pcl::PointXYZ>::Ptr tree)
{
    //法向量
    pcl::PointCloud<pcl::Normal>::Ptr point_normal (new pcl::PointCloud<pcl::Normal>);
    pcl::NormalEstimation<pcl::PointXYZ,pcl::Normal> est_normal;
    est_normal.setInputCloud(input_cloud);
    est_normal.setSearchMethod(tree);
    // est_normal.setKSearch(10);
    est_normal.setRadiusSearch (0.1);
    est_normal.compute(*point_normal);
    std::cout << "compute *cloud_src fpfh3" << endl;
    //fpfh 估计
    pcl::PointCloud<pcl::FPFHSignature33>::Ptr fpfh (new pcl::PointCloud<pcl::FPFHSignature33> );
    //pcl::FPFHEstimation<pcl::PointXYZ,pcl::Normal,pcl::FPFHSignature33> est_target_fpfh;
    pcl::FPFHEstimationOMP<pcl::PointXYZ,pcl::Normal,pcl::FPFHSignature33> est_fpfh;
    est_fpfh.setNumberOfThreads(4); //指定4核计算
    // pcl::search::KdTree<pcl::PointXYZ>::Ptr tree4 (new pcl::search::KdTree<pcl::PointXYZ> ());
    est_fpfh.setInputCloud(input_cloud);
    est_fpfh.setInputNormals(point_normal);
    est_fpfh.setSearchMethod(tree);
    // est_fpfh.setKSearch(100);
    est_fpfh.setRadiusSearch (0.5);
    std::cout << "compute *cloud_src fpfh4" << endl;
    est_fpfh.compute(*fpfh);
    std::cout << "compute *cloud_src fpfh5" << endl;

    return fpfh;

}






double CObjCCAlgorithm::FPFHfeature(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_src_o, pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_tgt_o)
{

    clock_t start = clock();
    //去除NAN点
    std::vector<int> indices_src; //保存去除的点的索引
    pcl::removeNaNFromPointCloud(*cloud_src_o, *cloud_src_o, indices_src);
    std::cout << "remove *cloud_src_o nan" << endl;

    std::vector<int> indices_tgt;
    pcl::removeNaNFromPointCloud(*cloud_tgt_o, *cloud_tgt_o, indices_tgt);
    std::cout << "remove *cloud_tgt_o nan" << endl;

    //下采样滤波
    pcl::VoxelGrid<pcl::PointXYZ> voxel_grid;
    voxel_grid.setLeafSize(0.1, 0.1, 0.1);
    voxel_grid.setInputCloud(cloud_src_o);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_src(new pcl::PointCloud<pcl::PointXYZ>);
    voxel_grid.filter(*cloud_src);
    std::cout << "down size *cloud_src_o from " << cloud_src_o->size() << "to" << cloud_src->size() << endl;

    pcl::VoxelGrid<pcl::PointXYZ> voxel_grid_2;
    voxel_grid_2.setLeafSize(0.1, 0.1, 0.1);
    voxel_grid_2.setInputCloud(cloud_tgt_o);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_tgt(new pcl::PointCloud<pcl::PointXYZ>);
    voxel_grid_2.filter(*cloud_tgt);
    std::cout << "down size *cloud_tgt_o.pcd from " << cloud_tgt_o->size() << "to" << cloud_tgt->size() << endl;



    //计算表面法线
    pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne_src;
    ne_src.setInputCloud(cloud_src);
    pcl::search::KdTree< pcl::PointXYZ>::Ptr tree_src(new pcl::search::KdTree< pcl::PointXYZ>());
    ne_src.setSearchMethod(tree_src);
    pcl::PointCloud<pcl::Normal>::Ptr cloud_src_normals(new pcl::PointCloud< pcl::Normal>);
    ne_src.setRadiusSearch(0.1);
    ne_src.compute(*cloud_src_normals);
    std::cout << "cloud_src_normals " << "to" << cloud_tgt->size() << endl;

    pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne_tgt;
    ne_tgt.setInputCloud(cloud_tgt);
    pcl::search::KdTree< pcl::PointXYZ>::Ptr tree_tgt(new pcl::search::KdTree< pcl::PointXYZ>());
    ne_tgt.setSearchMethod(tree_tgt);
    pcl::PointCloud<pcl::Normal>::Ptr cloud_tgt_normals(new pcl::PointCloud< pcl::Normal>);
    //ne_tgt.setKSearch(20);
    ne_tgt.setRadiusSearch(0.1);
    ne_tgt.compute(*cloud_tgt_normals);
    std::cout << "cloud_tgt_normals " << "to" << cloud_tgt->size() << endl;


    //  //计算FPFH
    // pcl::search::KdTree<pcl::PointXYZ>::Ptr tree_src_fpfh(new pcl::search::KdTree<pcl::PointXYZ>);//KDTree方式搜索
    // pcl::PointCloud<pcl::FPFHSignature33>::Ptr fpfhs_src = compute_fpfh_feature(cloud_src,tree_src_fpfh);
    // pcl::search::KdTree<pcl::PointXYZ>::Ptr tree_tgt_fpfh(new pcl::search::KdTree<pcl::PointXYZ>);//KDTree方式搜索
    // pcl::PointCloud<pcl::FPFHSignature33>::Ptr fpfhs_tgt = compute_fpfh_feature(cloud_src,tree_src_fpfh);
    // std::cout << "compute *cloud_src fpfh0" << endl;
    


    //计算FPFH
    pcl::FPFHEstimation<pcl::PointXYZ, pcl::Normal, pcl::FPFHSignature33> fpfh_src;
    fpfh_src.setInputCloud(cloud_src);
    fpfh_src.setInputNormals(cloud_src_normals);
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree_src_fpfh(new pcl::search::KdTree<pcl::PointXYZ>);
    fpfh_src.setSearchMethod(tree_src_fpfh);
    pcl::PointCloud<pcl::FPFHSignature33>::Ptr fpfhs_src(new pcl::PointCloud<pcl::FPFHSignature33>());
    fpfh_src.setRadiusSearch(0.5);
    fpfh_src.compute(*fpfhs_src);
    std::cout << "compute *cloud_src fpfh" << endl;

    pcl::FPFHEstimation<pcl::PointXYZ, pcl::Normal, pcl::FPFHSignature33> fpfh_tgt;
    fpfh_tgt.setInputCloud(cloud_tgt);
    fpfh_tgt.setInputNormals(cloud_tgt_normals);
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree_tgt_fpfh(new pcl::search::KdTree<pcl::PointXYZ>);
    fpfh_tgt.setSearchMethod(tree_tgt_fpfh);
    pcl::PointCloud<pcl::FPFHSignature33>::Ptr fpfhs_tgt(new pcl::PointCloud<pcl::FPFHSignature33>());
    fpfh_tgt.setRadiusSearch(0.5);
    fpfh_tgt.compute(*fpfhs_tgt);
    std::cout << "compute *cloud_tgt fpfh" << endl;



    //SAC配准
    pcl::SampleConsensusInitialAlignment<pcl::PointXYZ, pcl::PointXYZ, pcl::FPFHSignature33> scia;
    scia.setInputSource(cloud_src);
    scia.setInputTarget(cloud_tgt);
    scia.setSourceFeatures(fpfhs_src);
    scia.setTargetFeatures(fpfhs_tgt);

    //  sac_ia.setNumberOfSamples(20);  //设置每次迭代计算中使用的样本数量（可省）,可节省时间
    // scia.setCorrespondenceRandomness(6); //设置计算协方差时选择多少近邻点，该值越大，协防差越精确，但是计算效率越低.(可省)

    //scia.setMinSampleDistance(1);
    //scia.setNumberOfSamples(2);
    //scia.setCorrespondenceRandomness(20);
    pcl::PointCloud<pcl::PointXYZ>::Ptr sac_result(new pcl::PointCloud<pcl::PointXYZ>);
    scia.align(*sac_result);
    std::cout << "sac has converged:" << scia.hasConverged() << "  score: " << scia.getFitnessScore() << endl;
    Eigen::Matrix4f sac_trans;
    sac_trans = scia.getFinalTransformation();
    std::cout << sac_trans << endl;
    //pcl::io::savePCDFileASCII("bunny_transformed_sac.pcd", *sac_result);
    clock_t sac_time = clock();
    // visualize_pcd(cloud_src_o, cloud_tgt_o, sac_result);

    // //icp配准
    // pcl::PointCloud<pcl::PointXYZ>::Ptr icp_result(new pcl::PointCloud<pcl::PointXYZ>);
    // pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
    // icp.setInputSource(cloud_src);
    // icp.setInputTarget(cloud_tgt_o);
    // //Set the max correspondence distance to 4cm (e.g., correspondences with higher distances will be ignored)
    // icp.setMaxCorrespondenceDistance(1);
    // // 最大迭代次数
    // icp.setMaximumIterations(35);
    // // 两次变化矩阵之间的差值
    // icp.setTransformationEpsilon(1e-10);
    // // 均方误差
    // icp.setEuclideanFitnessEpsilon(0.01);
    // icp.align(*icp_result, sac_trans);

    // clock_t end = clock();
    // cout << "total time: " << (double)(end - start) / (double)CLOCKS_PER_SEC << " s" << endl;
    // cout << "sac time: " << (double)(sac_time - start) / (double)CLOCKS_PER_SEC << " s" << endl;
    // cout << "icp time: " << (double)(end - sac_time) / (double)CLOCKS_PER_SEC << " s" << endl;

    // std::cout << "ICP has converged:" << icp.hasConverged()
    // 	<< " score: " << icp.getFitnessScore() << std::endl;
    // Eigen::Matrix4f icp_trans;
    // icp_trans = icp.getFinalTransformation();
    // //cout<<"ransformationProbability"<<icp.getTransformationProbability()<<endl;
    // std::cout << icp_trans << endl;
    // //使用创建的变换对未过滤的输入点云进行变换
    // pcl::transformPointCloud(*cloud_src_o, *icp_result, icp_trans);
    // //保存转换的输入点云
    // //pcl::io::savePCDFileASCII("_transformed_sac_ndt.pcd", *icp_result);

    // //计算误差
    // Eigen::Vector3f ANGLE_origin;
    // Eigen::Vector3f TRANS_origin;
    // ANGLE_origin << 0, 0, M_PI / 4;
    // TRANS_origin << 0, 0.3, 0.2;
    // double a_error_x, a_error_y, a_error_z;
    // double t_error_x, t_error_y, t_error_z;
    // Eigen::Vector3f ANGLE_result;
    // matrix2angle(icp_trans, ANGLE_result);
    // a_error_x = fabs(ANGLE_result(0)) - fabs(ANGLE_origin(0));
    // a_error_y = fabs(ANGLE_result(1)) - fabs(ANGLE_origin(1));
    // a_error_z = fabs(ANGLE_result(2)) - fabs(ANGLE_origin(2));
    // cout << "点云实际旋转角度:\n" << ANGLE_origin << endl;
    // cout << "x轴旋转误差 : " << a_error_x << "  y轴旋转误差 : " << a_error_y << "  z轴旋转误差 : " << a_error_z << endl;

    // cout << "点云实际平移距离:\n" << TRANS_origin << endl;
    // t_error_x = fabs(icp_trans(0, 3)) - fabs(TRANS_origin(0));
    // t_error_y = fabs(icp_trans(1, 3)) - fabs(TRANS_origin(1));
    // t_error_z = fabs(icp_trans(2, 3)) - fabs(TRANS_origin(2));
    // cout << "计算得到的平移距离" << endl << "x轴平移" << icp_trans(0, 3) << endl << "y轴平移" << icp_trans(1, 3) << endl << "z轴平移" << icp_trans(2, 3) << endl;
    // cout << "x轴平移误差 : " << t_error_x << "  y轴平移误差 : " << t_error_y << "  z轴平移误差 : " << t_error_z << endl;
    // //可视化
    // // visualize_pcd(cloud_src_o, cloud_tgt_o, icp_result);

    return scia.getFitnessScore();

}


double
NDTPerform (pcl::PointCloud<pcl::PointXYZ>::Ptr input_cloud,pcl::PointCloud<pcl::PointXYZ>::Ptr target_cloud,Eigen::Matrix4f &transend)
{
    //将输入的扫描过滤到原始尺寸的大概 10% 以提高匹配的速度。
    pcl::PointCloud<pcl::PointXYZ>::Ptr filtered_cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::VoxelGrid<pcl::PointXYZ> voxel_grid;
    voxel_grid.setLeafSize(0.1, 0.1, 0.1);
    voxel_grid.setInputCloud(input_cloud);
    voxel_grid.filter(*filtered_cloud);
    std::cout << "Filtered cloud contains " << filtered_cloud->size ()
              << " data points from room_scan2.pcd" << std::endl;
    //初始化正态分布变换（NDT）
    pcl::NormalDistributionsTransform<pcl::PointXYZ, pcl::PointXYZ> ndt;
    //设置依赖尺度NDT参数
    //为终止条件设置最小转换差异
    ndt.setTransformationEpsilon (0.01);
    //为More-Thuente线搜索设置最大步长
    ndt.setStepSize (0.15);
    //设置NDT网格结构的分辨率（VoxelGridCovariance）
    ndt.setResolution (1.0);
    //设置匹配迭代的最大次数
    ndt.setMaximumIterations (40);
    // 设置要配准的点云
    ndt.setInputCloud (filtered_cloud);
    //设置点云配准目标
    ndt.setInputTarget (target_cloud);
    //   设置使用机器人测距法得到的初始对准估计结果
    //   Eigen::AngleAxisf init_rotation (0.6931, Eigen::Vector3f::UnitZ ());
    //   Eigen::Translation3f init_translation (1.79387, 0, 0);
    //   Eigen::Matrix4f init_guess = (init_translation * init_rotation).matrix ();
    //计算需要的刚体变换以便将输入的点云匹配到目标点云
    pcl::PointCloud<pcl::PointXYZ>::Ptr output_cloud (new pcl::PointCloud<pcl::PointXYZ>);
    //   ndt.align (*output_cloud, init_guess);
    ndt.align(*output_cloud);

    // 收敛函数
    std::cout << "Normal Distributions Transform has converged:" << ndt.hasConverged ()
              << " score: " << ndt.getFitnessScore () << std::endl;

    std::cout << "score ======== :" << ndt.getFitnessScore () << std::endl;
    //使用创建的变换对未过滤的输入点云进行变换
    pcl::transformPointCloud (*input_cloud, *output_cloud, ndt.getFinalTransformation ());
    transend = ndt.getFinalTransformation ();
    //保存转换的输入点云
    //   pcl::io::savePCDFileASCII ("/home/liyonggang/FILE/1832/room_scan2_transformed.pcd", *output_cloud);
    return ndt.getFitnessScore ();
}

void 
CObjCCAlgorithm::testPerform()
{
    //加载点云文件

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_src_o(new pcl::PointCloud<pcl::PointXYZ>);//原点云，待配准
    // pcl::io::loadPCDFile("/home/liyonggang/FILE/1832/Matched3031Reserve-2830-3031.pcd", *cloud_src_o);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_tgt_o(new pcl::PointCloud<pcl::PointXYZ>);//目标点云
    // pcl::io::loadPCDFile("/home/liyonggang/FILE/1832/Matching2830Reserve-2830-3031.pcd", *cloud_tgt_o);

    if (pcl::io::loadPCDFile<pcl::PointXYZ> ("/home/liyonggang/FILE/1832/Matched3031Reserve-2830-3031.pcd", *cloud_src_o) == -1)
    {
        PCL_ERROR ("Couldn't read file room_scan1.pcd \n");
        return ;
    }
    std::cout << "Loaded -- " << cloud_src_o->size () << " --cloud_src_o" << std::endl;
    //加载从新视角得到的房间的第二次扫描
    if (pcl::io::loadPCDFile<pcl::PointXYZ> ("/home/liyonggang/FILE/1832/Matching2830Reserve-2830-3031.pcd", *cloud_tgt_o) == -1)
    {
        PCL_ERROR ("Couldn't read file room_scan2.pcd \n");
        return ;
    }
    std::cout << "Loaded --" << cloud_tgt_o->size () << " --cloud_tgt_o" << std::endl;


    Eigen::Matrix4f transend;
    // FPFHfeature(cloud_src_o,cloud_tgt_o);
    NDTPerform(cloud_src_o,cloud_tgt_o,transend);
}





//cccloud转换成pcl的pointcloud --- rgbget
using namespace pcl;
#include <ccPointCloud.h>

void CCcloudToPCLcloud(ccPointCloud* m_cloud, pcl::PointCloud<pcl::PointXYZRGB>::Ptr pclCloud)
{

    int num = m_cloud->size();

    for (int i = 0; i < num; i++)

    {

        pcl::PointXYZRGB pointT;

        pointT.x = (m_cloud->getPoint(i))->x;

        pointT.y = (m_cloud->getPoint(i))->y;

        pointT.z = (m_cloud->getPoint(i))->z;


        ccColor::Rgb rgb = m_cloud->getPointColor(i);//定义一个颜色
        if (rgb.r != NULL)

        {

            pointT.r = rgb.r;

            pointT.g = rgb.g;

            pointT.b = rgb.b;

        }

        pclCloud->push_back(pointT);

    }

}

//cccloud转换成pcl的pointcloud no rgb--重载一下这个函数

void CCcloudToPCLcloud(ccPointCloud* m_cloud, pcl::PointCloud<pcl::PointXYZ>::Ptr pclCloud)

{

    int num = m_cloud->size();

    for (int i = 0; i < num; i++)

    {

        PointXYZ pointT;

        pointT.x = (m_cloud->getPoint(i))->x;

        pointT.y = (m_cloud->getPoint(i))->y;

        pointT.z = (m_cloud->getPoint(i))->z;

        pclCloud->push_back(pointT);

    }

}



//----------------------pointCloud转ccCloud---------------------

void PCLcloudToCCcloud(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pclCloud, ccPointCloud* m_cloud)

{

    int num = pclCloud->points.size();

    m_cloud->reserve(static_cast<unsigned>(num));

    for (int i = 0; i < num; i++)

    {

        CCVector3 P11(pclCloud->points[i].x, pclCloud->points[i].y, pclCloud->points[i].z);

        m_cloud->addPoint(P11);



        ccColor::Rgb rgb;//定义一个颜色

        if (pclCloud->points[0].r <= 1 && pclCloud->points[0].g <= 1)

        {

            rgb = ccColor::Rgb(pclCloud->points[i].r*255, pclCloud->points[i].g*255, pclCloud->points[i].b*255);

        }

        else

        {

            rgb = ccColor::Rgb(pclCloud->points[i].r, pclCloud->points[i].g, pclCloud->points[i].b);

        }

        m_cloud->resizeTheRGBTable(true);
        // unsigned pointIndex, const ccColor::Rgb& col
        m_cloud->setPointColor(i, rgb);
        //   m_cloud->setPointColor()

    }



}

//无色的cccloud ---重载一下这个函数

void PCLcloudToCCcloud(pcl::PointCloud<pcl::PointXYZ>::Ptr pclCloud, ccPointCloud* m_cloud)

{

    int num = pclCloud->points.size();

    m_cloud->reserve(static_cast<unsigned>(num));

    for (int i = 0; i < num; i++)

    {

        CCVector3 P11(pclCloud->points[i].x, pclCloud->points[i].y, pclCloud->points[i].z);

        m_cloud->addPoint(P11);

    }

}

// void CCPointToPCL(ccPointCloud* m_cloud)
// {

//     ccHObject* ent = selectedEntities[0];
//     assert(ent);
//     ccPointCloud* m_cloud = static_cast<ccPointCloud*>(ent);
//     pcl::PointCloud<pcl::PointXYZ>::Ptr clouds(new pcl::PointCloud<pcl::PointXYZ>);
//     CCcloudToPCLcloud(m_cloud,clouds);
//     pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ground(new pcl::PointCloud<pcl::PointXYZ>);
//     pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ground_remove(new pcl::PointCloud<pcl::PointXYZ>);
//     pcl::PointIndicesPtr ground(new pcl::PointIndices);
// // // 创建形态学滤波器对象
// //     pcl::ProgressiveMorphologicalFilter<pcl::PointXYZ> pmf;
// //     pmf.setInputCloud(clouds);
// // // 设置过滤点最⼤的窗⼝尺⼨
// //     pmf.setMaxWindowSize(10);
// // // 设置计算⾼度阈值的斜率值--就是坡度
// //     pmf.setSlope(1.0f);
// // // 设置初始⾼度参数被认为是地⾯点
// //     pmf.setInitialDistance(0.5f);
// // // 设置被认为是地⾯点的最⼤⾼度
// //     pmf.setMaxDistance(3.0f);
// //     pmf.extract(ground->indices);
// // // Create the filtering object
// //     pcl::ExtractIndices<pcl::PointXYZ> extract;
// //     extract.setInputCloud(clouds);
// //     extract.setIndices(ground);

// }


ccGLMatrix FromEigenMat(const Eigen::Matrix4f &ovrMat)
{
    ccGLMatrix ccMat;
    float* data = ccMat.data();

    data[0] = ovrMat(0,0); data[4] = ovrMat(0,1);   data[8] = ovrMat(0,2); data[12] = ovrMat(0,3);
    data[1] = ovrMat(1,0); data[5] = ovrMat(1,1);	data[9] = ovrMat(1,2); data[13] = ovrMat(1,3);
    data[2] = ovrMat(2,0); data[6] = ovrMat(2,1);	data[10] = ovrMat(2,2); data[14] = ovrMat(2,3);
    data[3] = ovrMat(3,0); data[7] = ovrMat(3,1);	data[11] = ovrMat(3,2); data[15] = ovrMat(3,3);


    return ccMat;
}

double CObjCCAlgorithm::AutoFPFHRegister(NDTPERDATA _icpperdata_t,ccPointCloud* transcloud,ccPointCloud* dstcloud,ccGLMatrix& transMat)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_src_o(new pcl::PointCloud<pcl::PointXYZ>);//原点云，待配准
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_tgt_o(new pcl::PointCloud<pcl::PointXYZ>);//目标点云

    CCcloudToPCLcloud(transcloud, cloud_src_o);
    CCcloudToPCLcloud(dstcloud, cloud_tgt_o);
    return FPFHfeature(cloud_src_o,cloud_tgt_o);
}

double CObjCCAlgorithm::AutoNDTRegister(NDTPERDATA _icpperdata_t,ccPointCloud* transcloud,ccPointCloud* dstcloud,ccGLMatrix& transMat)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_src_o(new pcl::PointCloud<pcl::PointXYZ>);//原点云，待配准
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_tgt_o(new pcl::PointCloud<pcl::PointXYZ>);//目标点云

    CCcloudToPCLcloud(transcloud, cloud_src_o);
    CCcloudToPCLcloud(dstcloud, cloud_tgt_o);
    
    Eigen::Matrix4f transend = Eigen::Matrix4f::Identity();
    double score = NDTPerform(cloud_src_o,cloud_tgt_o,transend);
    transMat = FromEigenMat(transend);    
    return score;
}
