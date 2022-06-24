
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



#include <eigen3/Eigen/Eigen>
#include <map>
#include <string>


using namespace CCCoreLib;

// namespace lygs {
// struct SensorTrajectoryData;
// }

// version 1.1
class ccGLMatrix;
struct SensorTrajectoryData;
//class CAppConfig;
class ClidarCompute
{
private:
    static ClidarCompute* instance;
private:

    ///
    /// \brief ClidarCompute
    ///
    ClidarCompute() { };

    ~ClidarCompute() { };

    ///
    /// \brief ClidarCompute
    ///
    ClidarCompute(const ClidarCompute&);


    ///
    /// \brief operator =
    /// \return
    ///
    ClidarCompute& operator=(const ClidarCompute&);



    /** operator "<" for std::sort() */

    ///sorted
    /// \brief The IndexDistLyg_Sorter struct
    ///
    struct IndexDistLyg_Sorted {
        /** std::pair<IndexType,DistanceType> */
        template <typename PairType>
        inline bool operator()(const PairType &p1, const PairType &p2) const {
            //        return p1.second - p2.second<0.001f;
            return p1.second < p2.second;
        }
    };


private:

    class Deletor {
    public:
        ~Deletor() {
            if(ClidarCompute::instance != NULL)
                delete ClidarCompute::instance;
        }
    };
    static Deletor deletor;


public:

    ///
    /// \brief getInstance
    /// \return
    ///
    static ClidarCompute* getInstance() {
        if(instance == NULL) {
            instance = new ClidarCompute();
        }
        return instance;
    }



    ///
    /// \brief GetPointDataSelf1
    /// \param _vecs
    /// \param match
    /// \param func
    ///
    static void
    GetPointDataSelf1(std::vector<  SensorTrajectoryData> _vecs,
                      std::vector<std::pair<unsigned,unsigned>> &match,
                      std::function<int(int,std::vector<std::pair<uint32_t, double>> ,
                                        std::vector<std::pair<unsigned,unsigned>> & )> func);


    ///
    /// \brief GetPointDataSelf
    /// \param _vecs
    /// \param match
    ///
    static void
    GetPointDataSelf(std::vector<  SensorTrajectoryData> _vecs,
                    std::vector<std::pair<unsigned, unsigned>> samematch,
                     std::vector<std::pair<unsigned,unsigned>> &match);


    ///
    /// \brief GetPointData
    /// \param _vecs
    /// \param match
    ///
    static void
    GetPointData(std::vector<  SensorTrajectoryData> _vecs,
                 std::vector<std::pair<unsigned,unsigned>> &match);



    ///
    /// \brief SqereTrajectory
    /// \param outfileName
    /// \param _vec
    ///
    static void
    SqereTrajectory(std::string outfileName,std::vector<std::string> _vec);




    ///
    /// \brief FromEigenMat
    /// \param ovrMat
    /// \return
    ///
    static ccGLMatrix
    FromEigenMat(const Eigen::Matrix4f& ovrMat);



    ///
    /// \brief getSE3Mat
    /// \param yaw
    /// \param pitch
    /// \param roll
    /// \param x
    /// \param y
    /// \param z
    /// \param order
    /// \return
    ///
    static Eigen::Matrix4f
    getSE3Mat(float yaw, float pitch, float roll, float x , float y, float z, std::string order);





    ///
    /// \brief Index_Iter
    /// \param i
    /// \param ret_matches
    /// \param match
    /// \return
    ///
    static int
    Index_Iter(int i, std::vector<std::pair<uint32_t, double> > ret_matches,
               std::vector<std::pair<unsigned, unsigned> > &match);


};

// init static member
//ClidarCompute* ClidarCompute::instance = NULL;



