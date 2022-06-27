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


#include <iostream>


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





std::vector<ccPointCloud *>  CObjCCAlgorithm::SetResample(ccPointCloud* cloud)
{

    CC_SUBSAMPLING_METHOD samplingMethod =  CC_SUBSAMPLING_METHOD::SPACE;
    int random = 100.0;
    float space_t = 0.1f;
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






double CObjCCAlgorithm::AutoICPRegister(ICPPERDATA _icpperdata_t,ccPointCloud* transcloud,ccPointCloud* dstcloud,ccGLMatrix transMat)
{

    ccHObject* data = static_cast<ccHObject*>(transcloud);
    ccHObject* model = static_cast<ccHObject*>(dstcloud);

    double minRMSDecrease = _icpperdata_t.minRMSDecrease;
    unsigned maxIterationCount = _icpperdata_t.maxIterationCount;
    unsigned randomSamplingLimit = _icpperdata_t.randomSamplingLimit;
    bool removeFarthestPoints  = _icpperdata_t.removeFarthestPoints;
    bool useDataSFAsWeights  = _icpperdata_t.useDataSFAsWeights;
    bool useModelSFAsWeights  = _icpperdata_t.useModelSFAsWeights;
    bool adjustScale   = _icpperdata_t.adjustScale;
    int transformationFilters	 = _icpperdata_t.transformationFilters;
    unsigned finalOverlap  = _icpperdata_t.finalOverlap;
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
        //  QMessageBox::information(nullptr, QString("Registration info"), summary.join("\n"));
        // forceConsoleDisplay();
    }


    return finalError;
}


