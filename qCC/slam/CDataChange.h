

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
  double latitude;
  double longitude;
  double altitude;
};

typedef PointXYZIRPYT PointTypePose;


class CDataChange
{

  private:
    gtsam::NonlinearFactorGraph gtSAMgraph;
    gtsam::Values initialEstimate;
    gtsam::Values optimizedEstimate;
    gtsam::ISAM2* isam;
    gtsam::Values isamCurrentEstimate;
    gtsam::ISAM2Params parameters;


    std::vector<PointTypePose> _cloudKeyPoses6D;
    PointTypePose _last_key_frame_pose;

  public:

    CDataChange(){
        parameters.relinearizeThreshold = 0.1;
        parameters.relinearizeSkip = 1;
        isam = new ISAM2(parameters);
    }
    ~CDataChange(){
        delete isam;

    }

    std::vector< std::string> split(const std::string& s, const std::string& delim)
    {
        std::vector< std::string> ret;
        size_t last = 0;
        size_t index=s.find_first_of(delim,last);
        while (index!=std::string::npos)
        {
            ret.push_back(s.substr(last,index-last));
            last=index+1;
            index=s.find_first_of(delim,last);
        }
        if (index-last>0)
        {
            ret.push_back(s.substr(last,index-last));
        }
        return ret;
    }

    void loadTrajectory(std::string name){

        std::ifstream infile;
        int id = 0;
        std::string line;
        PointTypePose pose;
        infile.open(name, std::ios::in);

        if(infile.is_open ()){
            while (!infile.eof()){


                infile >> line;
                std::vector<std::string> res = split(line, ",");
                if(res.size() < 7){
                    std::cout<<"loadTrajectory errot"<< std::endl;
                    return;
                }
                pose.id = id++;
                pose.time  = atof(res[0].c_str());
                pose.x     = atof(res[1].c_str());
                pose.y     = atof(res[2].c_str());
                pose.z     = atof(res[3].c_str());
                pose.roll  = atof(res[4].c_str());
                pose.pitch = atof(res[5].c_str());
                pose.yaw   = atof(res[6].c_str());
//                pose.latitude    = atof(res[7].c_str());
//                pose.longitude   = atof(res[8].c_str());
//                pose.altitude    = atof(res[9].c_str());

                addKeyFrameFactor(pose);

                _cloudKeyPoses6D.push_back(pose);
                std::cout<<_cloudKeyPoses6D.size()<< std::endl;


                infile.get();
                if(infile.peek() == '\n'){
                    break;
                }
            }
        }
    }



    void addKeyFrameFactor(PointTypePose key_frame_pose)
    {
        if (key_frame_pose.id == 0) {
            noiseModel::Diagonal::shared_ptr priorNoise = noiseModel::Diagonal::Variances((Vector(6) << 1.0, 1.0, M_PI*M_PI, 1e-8, 1e-8, 1e-8).finished()); // rad*rad, meter*meter

            gtSAMgraph.add(PriorFactor<Pose3>(key_frame_pose.id, Pose3(Rot3::RzRyRx(key_frame_pose.roll, key_frame_pose.pitch, key_frame_pose.yaw),
                    Point3(key_frame_pose.x, key_frame_pose.y, key_frame_pose.z)), priorNoise));

        }
        else {
            noiseModel::Diagonal::shared_ptr odometryNoise = noiseModel::Diagonal::Variances((Vector(6) <<  1e-6, 1e-6, 1e-6, 1e-4, 1e-4, 1e-4).finished());
            gtsam::Pose3 poseFrom = Pose3(Rot3::RzRyRx(_last_key_frame_pose.roll, _last_key_frame_pose.pitch, _last_key_frame_pose.yaw),
                                    Point3(_last_key_frame_pose.x, _last_key_frame_pose.y, _last_key_frame_pose.z));

            gtsam::Pose3 poseTo = Pose3(Rot3::RzRyRx(key_frame_pose.roll, key_frame_pose.pitch, key_frame_pose.yaw),
                                Point3(key_frame_pose.x, key_frame_pose.y, key_frame_pose.z));

            gtSAMgraph.add(BetweenFactor<Pose3>(key_frame_pose.id - 1, key_frame_pose.id, poseFrom.between(poseTo), odometryNoise));
        }

        initialEstimate.insert(key_frame_pose.id, Pose3(Rot3::RzRyRx(key_frame_pose.roll, key_frame_pose.pitch, key_frame_pose.yaw),
                                                Point3(key_frame_pose.x, key_frame_pose.y, key_frame_pose.z)));

        _last_key_frame_pose = key_frame_pose;

        isam->update(gtSAMgraph, initialEstimate);
        isam->update();

        gtSAMgraph.resize(0);
        initialEstimate.clear();
    }


    void addLoopClosureFactor(PointTypePose key_frame_pose, int closest_frame_id)
    {
        noiseModel::Diagonal::shared_ptr odometryNoise = noiseModel::Diagonal::Variances((Vector(6) <<  1e-6, 1e-6, 1e-6, 1e-4, 1e-4, 1e-4).finished());;

        gtsam::Pose3 poseFrom = Pose3(Rot3::RzRyRx(key_frame_pose.roll, key_frame_pose.pitch, key_frame_pose.yaw),
                                    Point3(key_frame_pose.x, key_frame_pose.y, key_frame_pose.z));

        PointTypePose history_frame_pose = _cloudKeyPoses6D[closest_frame_id];

        gtsam::Pose3 poseTo = Pose3(Rot3::RzRyRx(history_frame_pose.roll, history_frame_pose.pitch, history_frame_pose.yaw),
                                Point3(history_frame_pose.x, history_frame_pose.y, history_frame_pose.z));

        gtSAMgraph.add(BetweenFactor<Pose3>(key_frame_pose.id, closest_frame_id, poseFrom.between(poseTo), odometryNoise));

        isam->update(gtSAMgraph);
        isam->update();
        gtSAMgraph.resize(0);
    }


    void saveKeyPose(std::ofstream& ofs, const PointTypePose& pose)
    {
       ofs<< std::to_string(pose.time)<<","
          << std::to_string(pose.x) << "," << std::to_string(pose.y) << "," << std::to_string(pose.z) << ","
          << std::to_string(pose.roll) << ","<< std::to_string(pose.pitch) << "," <<std::to_string(pose.yaw) << ","
          << std::to_string(pose.latitude) << ","<< std::to_string(pose.longitude) << "," <<std::to_string(pose.altitude)
          <<std::endl;
    }


    void graphOptimizerAndSavePoses(std::string path)
    {
        //boost::filesystem::remove(path.c_str());
        std::ofstream optimized_pose_ofs;
        std::string path_file = path + "/opt_pose_path1.txt";
        optimized_pose_ofs.open(path_file.c_str(), std::ios::out);

        isamCurrentEstimate = isam->calculateEstimate();
        int numPoses = isamCurrentEstimate.size();

        PointTypePose pose;


        for (int i = 0; i < numPoses; ++i)
        {   pose.time = _cloudKeyPoses6D[i].time;
            pose.x     = isamCurrentEstimate.at<Pose3>(i).translation().x();
            pose.y     = isamCurrentEstimate.at<Pose3>(i).translation().y();
            pose.z     = isamCurrentEstimate.at<Pose3>(i).translation().z();
            pose.roll  = isamCurrentEstimate.at<Pose3>(i).rotation().roll();
            pose.pitch = isamCurrentEstimate.at<Pose3>(i).rotation().pitch();
            pose.yaw   = isamCurrentEstimate.at<Pose3>(i).rotation().yaw();
            pose.latitude  = _cloudKeyPoses6D[i].latitude;
            pose.longitude = _cloudKeyPoses6D[i].longitude;
            pose.altitude  = _cloudKeyPoses6D[i].altitude;

            saveKeyPose(optimized_pose_ofs, pose);
        }
        //pcl::io::savePCDFileBinary(path +"/cloudKeyPoses6D.pcd", *_cloudKeyPoses6D);
    }
};





