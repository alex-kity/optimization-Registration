#include "CDataChange.h"
#include "CGYLCommon.h"
#include "spdlog/spdlog.h"
#include <QApplication>

CBackOptimization::CBackOptimization(){
    parameters.relinearizeThreshold = 0.1;
    parameters.relinearizeSkip = 1;
    isam = new ISAM2(parameters);
    last_gps_id = -100;
}

CBackOptimization::~CBackOptimization(){
    delete isam;
    // ROS_INFO("~LoopClosure");
}

std::vector<std::string> CBackOptimization::split(const std::string &s, const std::string &delim)
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

void CBackOptimization::loadTrajectory(std::string name){

    _cloudKeyPoses6D.clear();
    _cloudKeyTTL3D.clear();
    std::ifstream infile;
    int id = 0;
    std::string line;
    PointTypePose pose;
    GpsTTLCovS ttl;
    infile.open(name, std::ios::in);

    if(infile.is_open ()){
        while (!infile.eof()){


            infile >> line;
            std::vector<std::string> res = split(line, ",");
            if(res.size() < 15){
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
            pose.score = atof(res[7].c_str());

            ttl.id = pose.id;
            ttl.x  = atof(res[8].c_str());
            ttl.y  = atof(res[9].c_str());
            ttl.z  = atof(res[10].c_str());
            ttl.cov_x   = atof(res[11].c_str());
            ttl.cov_y   = atof(res[12].c_str());
            ttl.cov_z   = atof(res[13].c_str());
            ttl.status  = atof(res[14].c_str());
            // ROS_INFO("ttlcov= %f, %f",ttl.cov_x, ttl.cov_y);

            addKeyFrameFactor(pose);
            addGpsFactor(ttl);
            //isam->calculateEstimate();

            _cloudKeyPoses6D.push_back(pose);
            _cloudKeyTTL3D.push_back(ttl);

            infile.get();
            if(infile.peek() == '\n'){
                std::cout<<"id"<< pose.id <<std::endl;
                break;
            }

            qApp->processEvents();
        }
        // ROS_INFO("_cloudKeyPoses6D.size=%lu",_cloudKeyPoses6D.size());
        spdlog::info("cloudKeyPoses6D.size= : {}",_cloudKeyPoses6D.size());
    }
    // graphOptimizerAndSavePoses("/home/alexlyg/file/0624/1558");
}

void CBackOptimization::GetTrajectOptData(std::vector<SensorTrajectoryData> &_vecs, std::map<std::string, SensorTrajectoryData> &map_trajectorys)
{
    isamCurrentEstimate = isam->calculateEstimate();

    SensorTrajectoryData pose;

    for (int i = 0; i < isamCurrentEstimate.size(); ++i)
    {   

        pose.time  = _cloudKeyPoses6D[i].time;
        pose.x     = isamCurrentEstimate.at<Pose3>(i).translation().x();
        pose.y     = isamCurrentEstimate.at<Pose3>(i).translation().y();
        pose.z     = isamCurrentEstimate.at<Pose3>(i).translation().z();
        pose.roll  = isamCurrentEstimate.at<Pose3>(i).rotation().roll();
        pose.pitch = isamCurrentEstimate.at<Pose3>(i).rotation().pitch();
        pose.yaw   = isamCurrentEstimate.at<Pose3>(i).rotation().yaw();


        _cloudKeyPoses6D[i].x = pose.x;
        _cloudKeyPoses6D[i].y = pose.y;
        _cloudKeyPoses6D[i].z = pose.z;
        _cloudKeyPoses6D[i].roll  = pose.roll;
        _cloudKeyPoses6D[i].pitch = pose.pitch;
        _cloudKeyPoses6D[i].yaw   = pose.yaw;


        std::string timeStr = std::to_string(pose.time );
        pose.name = timeStr;
        map_trajectorys[timeStr] = pose;
        _vecs.push_back(pose);
    }
}

void CBackOptimization::addKeyFrameFactor(PointTypePose key_frame_pose)
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
    // qApp->processEvents();
}

void CBackOptimization::addGpsFactor(GpsTTLCovS ttl)
{
    if(ttl.cov_x > 0.2 || ttl.cov_y > 0.2 || (ttl.id - last_gps_id) < 50){
        return;
    }

    //return;
    gtsam::Vector Vector3(3);
    Vector3 << std::max(ttl.cov_x, 0.3), std::max(ttl.cov_y, 0.3), std::max(ttl.cov_z, 0.5);
    noiseModel::Diagonal::shared_ptr gps_noise = noiseModel::Diagonal::Variances(Vector3);
    gtsam::GPSFactor gps_factor(ttl.id, gtsam::Point3(ttl.x, ttl.y, ttl.z), gps_noise);
    gtSAMgraph.add(gps_factor);
    isam->update(gtSAMgraph);
    isam->update();
    //isam->update();
    gtSAMgraph.resize(0);
    last_gps_id = ttl.id;
    // qApp->processEvents();
}

void CBackOptimization::addLoopClosureFactor(PointTypePose key_frame_pose, int closest_frame_id)
{

    PointTypePose history_frame_pose = _cloudKeyPoses6D[closest_frame_id];
    // if(std::abs(history_frame_pose.x-key_frame_pose.x)>0.01&&
    // std::abs(history_frame_pose.y-key_frame_pose.y)>0.01&&
    // std::abs(history_frame_pose.y-key_frame_pose.y))



    noiseModel::Diagonal::shared_ptr odometryNoise = noiseModel::Diagonal::Variances((Vector(6) <<  0.01, 0.01, 0.01, 1e-2, 1e-2, 1e-2).finished());;

    gtsam::Pose3 poseFrom = Pose3(Rot3::RzRyRx(key_frame_pose.roll, key_frame_pose.pitch, key_frame_pose.yaw),
                                  Point3(key_frame_pose.x, key_frame_pose.y, key_frame_pose.z));

    gtsam::Pose3 poseTo = Pose3(Rot3::RzRyRx(history_frame_pose.roll, history_frame_pose.pitch, history_frame_pose.yaw),
                                Point3(history_frame_pose.x, history_frame_pose.y, history_frame_pose.z));

    gtSAMgraph.add(BetweenFactor<Pose3>(key_frame_pose.id, closest_frame_id, poseFrom.between(poseTo), odometryNoise));

    isam->update(gtSAMgraph);
    isam->update();
    gtSAMgraph.resize(0);

}

void CBackOptimization::saveKeyPose(std::ofstream &ofs, const PointTypePose &pose)
{
    ofs<< std::to_string(pose.time)<<","
       << std::to_string(pose.x) << "," << std::to_string(pose.y) << "," << std::to_string(pose.z) << ","
       << std::to_string(pose.roll) << ","<< std::to_string(pose.pitch) << "," <<std::to_string(pose.yaw) //<< ","
          //<< std::to_string(pose.latitude) << ","<< std::to_string(pose.longitude) << "," <<std::to_string(pose.altitude)
       <<std::endl;
}

void CBackOptimization::graphOptimizerAndSavePoses(std::string path)
{
    //boost::filesystem::remove(path.c_str());
    std::ofstream optimized_pose_ofs;
    std::string path_file = path + "/opt_pose_path_s.txt";
    optimized_pose_ofs.open(path_file.c_str(), std::ios::out);

    isamCurrentEstimate = isam->calculateEstimate();
    int numPoses = isamCurrentEstimate.size();

    PointTypePose pose;


    for (int i = 0; i < numPoses; ++i)
    {   pose.time  = _cloudKeyPoses6D[i].time;
        pose.x     = isamCurrentEstimate.at<Pose3>(i).translation().x();
        pose.y     = isamCurrentEstimate.at<Pose3>(i).translation().y();
        pose.z     = isamCurrentEstimate.at<Pose3>(i).translation().z();
        pose.roll  = isamCurrentEstimate.at<Pose3>(i).rotation().roll();
        pose.pitch = isamCurrentEstimate.at<Pose3>(i).rotation().pitch();
        pose.yaw   = isamCurrentEstimate.at<Pose3>(i).rotation().yaw();
        // pose.latitude  = _cloudKeyPoses6D[i].latitude;
        // pose.longitude = _cloudKeyPoses6D[i].longitude;
        // pose.altitude  = _cloudKeyPoses6D[i].altitude;

        saveKeyPose(optimized_pose_ofs, pose);
    }
}
