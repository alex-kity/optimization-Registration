

#include <eigen3/Eigen/Eigen>
#include <string>







//#include <gtsam/geometry/Pose3.h>
//#include <gtsam/geometry/Rot3.h>
//#include <gtsam/nonlinear/LevenbergMarquardtOptimizer.h>
//#include <gtsam/nonlinear/Marginals.h>
//#include <gtsam/nonlinear/NonlinearFactorGraph.h>
//#include <gtsam/nonlinear/Values.h>
//#include <gtsam/slam/BetweenFactor.h>
//#include <gtsam/slam/PriorFactor.h>
//#include <gtsam/navigation/GPSFactor.h>
//#include <gtsam/navigation/ImuFactor.h>
//#include <gtsam/nonlinear/ISAM2.h>



struct DATARegistration
{
    float phi_rad;
    float theta_rad;
    float psi_rad;
    float x;
    float y;
    float z;

    std::string ied = 0;
    std::string iing = 0;

};


class CDataChange
{
public:
    CDataChange(){}


    //interface
    void InitData(std::string filename);

    //! data once
    void SetData(DATARegistration);


    //! SetFinished
    void SetFinished(const bool finish);


private:



};
