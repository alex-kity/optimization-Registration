

//#include <eigen3/Eigen/Eigen>


//#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include <gtsam/geometry/Pose3.h>
#include <gtsam/geometry/Rot3.h>
#include <gtsam/nonlinear/LevenbergMarquardtOptimizer.h>
#include <gtsam/nonlinear/Marginals.h>
#include <gtsam/nonlinear/NonlinearFactorGraph.h>
#include <gtsam/nonlinear/Values.h>
#include <gtsam/slam/BetweenFactor.h>
#include <gtsam/slam/PriorFactor.h>
#include <gtsam/navigation/GPSFactor.h>
#include <gtsam/navigation/ImuFactor.h>
#include <gtsam/nonlinear/ISAM2.h>




using namespace gtsam;


struct PointXYZIRPYT
{
  int id;
  double time;
  float x;
  float y;
  float z;
  float roll;
  float pitch;
  float yaw;
  float score;
};

struct GpsTTLCOVS{
  int id;
  double x;
  double y;
  double z;
  double cov_x;
  double cov_y;
  double cov_z;
  int status;
};

typedef PointXYZIRPYT PointTypePose;
typedef GpsTTLCOVS GpsTTLCovS;




struct SensorTrajectoryData;
class CBackOptimization
{
public:

    CBackOptimization();
    ~CBackOptimization();


    /// 开始的时候调用一次
    /// \brief loadTrajectory
    /// \param name
    ///
    void loadTrajectory(std::string name);

    /// 加载完轨迹调用一次获取轨迹
    /// \brief GetTrajectOptData
    /// \param _vecs
    /// \param map_trajectorys
    ///
    void GetTrajectOptData(std::vector<SensorTrajectoryData>  & _vecs,std::map<std::string, SensorTrajectoryData> &map_trajectorys);


    /// 每次配准完调用一次 LoopClosure
    /// \brief addLoopClosureFactor
    /// \param key_frame_pose
    ///
    void addLoopClosureFactor(PointTypePose key_frame_pose, int closest_frame_id);


    /// 结束之后调用一次
    /// \brief graphOptimizerAndSavePoses
    /// \param path
    ///
    void graphOptimizerAndSavePoses(std::string path);

private:

    std::vector< std::string> split(const std::string& s, const std::string& delim);


    void saveKeyPose(std::ofstream& ofs, const PointTypePose& pose);


    void addKeyFrameFactor(PointTypePose key_frame_pose);


    void addGpsFactor(GpsTTLCovS ttl);

private:
    gtsam::NonlinearFactorGraph gtSAMgraph;
    gtsam::Values initialEstimate;
    gtsam::Values optimizedEstimate;
    gtsam::ISAM2* isam;
    gtsam::Values isamCurrentEstimate;
    gtsam::ISAM2Params parameters;


    std::vector<PointTypePose> _cloudKeyPoses6D;
    std::vector<GpsTTLCovS> _cloudKeyTTL3D;
    PointTypePose _last_key_frame_pose;
    int last_gps_id;


};





