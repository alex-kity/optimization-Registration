#include "ClidarCompute.h"

#include <KdTree.h>
#include "clygnanoflann.hpp"
#include "utils.h"

#include "CGYLCommon.h"

static CAppConfig g_CAppConfig;

using namespace lygs;


///
/// \brief ClidarCompute::FromEigenMat
/// \param ovrMat
/// \return
///
ccGLMatrix ClidarCompute::FromEigenMat(const Eigen::Matrix4f &ovrMat)
{
    ccGLMatrix ccMat;
    float* data = ccMat.data();

    data[0] = ovrMat(0,0); data[4] = ovrMat(0,1);   data[8] = ovrMat(0,2); data[12] = ovrMat(0,3);
    data[1] = ovrMat(1,0); data[5] = ovrMat(1,1);	data[9] = ovrMat(1,2); data[13] = ovrMat(1,3);
    data[2] = ovrMat(2,0); data[6] = ovrMat(2,1);	data[10] = ovrMat(2,2); data[14] = ovrMat(2,3);
    data[3] = ovrMat(3,0); data[7] = ovrMat(3,1);	data[11] = ovrMat(3,2); data[15] = ovrMat(3,3);


    return ccMat;
}



///
/// \brief ClidarCompute::TrajectoryDataToPointCloud
/// \param _vecs
/// 
template <typename Type>
lyg::PointCloud<double> TrajectoryDataToPointCloud(typename std::vector<Type> _vecs)
{
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
    return  tmpCloud1;
}



///
/// \brief ClidarCompute::GetPointDataSelf
/// \param _vecs
/// \param match
/// \param func
void ClidarCompute::GetPointDataSelf1(std::vector<  lygs::SensorTrajectoryData> _vecs,
                                      std::vector<std::pair<unsigned,unsigned>> &match,
                                      std::function<int(int,std::vector<std::pair<uint32_t, double>> ,
                                                        std::vector<std::pair<unsigned,unsigned>> & )> func)
{
    lyg::PointCloud<double> tmpCloud1 = TrajectoryDataToPointCloud<lygs::SensorTrajectoryData>(_vecs);
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
                    &query_pt[0], g_CAppConfig.dis, ret_matches, params);

        if(nMatches>1)
        {
            i = func(i ,ret_matches,match);
        }
        ret_matches.clear();

    }

}


///
/// \brief ClidarCompute::Index_Iter
/// \param i
/// \param ret_matches
/// \param match
/// \return
///
int ClidarCompute::Index_Iter(int i,std::vector<std::pair<uint32_t, double>> ret_matches ,
                              std::vector<std::pair<unsigned,unsigned>> & match)
{
    // perform
    std::vector<std::pair<uint32_t, double>>::iterator iter;
    for(iter = ret_matches.begin(); iter!=ret_matches.end(); iter++)
    {
        if((int)(i-iter->first)>g_CAppConfig.frontToBackfram)
        {
            //perform
            std::cout<<i<<"perform = "<<iter->first<<std::endl;
            //get result
            match.push_back(std::make_pair(i, iter->first));

            i = i+g_CAppConfig.jumpfram;
            break;
        }

    }

}



///
/// \brief ClidarCompute::getSE3Mat
/// \param yaw
/// \param pitch
/// \param roll
/// \param x
/// \param y
/// \param z
/// \param order
/// \return
///
Eigen::Matrix4f ClidarCompute::getSE3Mat(float yaw, float pitch, float roll, float x, float y, float z, std::string order)
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



///
/// \brief ClidarCompute::GetPointDataSelf
/// \param _vecs
/// \param match
///
void ClidarCompute::GetPointDataSelf(std::vector<  lygs::SensorTrajectoryData> _vecs,
                                     std::vector<std::pair<unsigned,unsigned>> &match)
{
    lyg::PointCloud<double> tmpCloud1 = TrajectoryDataToPointCloud<lygs::SensorTrajectoryData>(_vecs);

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
                    &query_pt[0], g_CAppConfig.dis, ret_matches, params);

        if(nMatches>1)
        {
            // perform
            std::vector<std::pair<uint32_t, double>>::iterator iter;
            for(iter = ret_matches.begin(); iter!=ret_matches.end(); iter++)
            {
                if((int)(i-iter->first)>g_CAppConfig.frontToBackfram)
                {
                    //perform
                    std::cout<<i<<"perform = "<<iter->first<<std::endl;
                    //get result
                    match.push_back(std::make_pair(i, iter->first));

                    i = i+g_CAppConfig.jumpfram;
                    break;
                }

            }

        }
        ret_matches.clear();

    }

}
















///
/// \brief ClidarCompute::GetPointData
/// \param _vecs
/// \param match
///
void ClidarCompute::GetPointData(std::vector<  lygs::SensorTrajectoryData> _vecs, std::vector<std::pair<unsigned,unsigned>> &match)
{

    CCCoreLib::PointCloud tmpCloud1;
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
    CCCoreLib::KDTree intermediateTree;
    if (!intermediateTree.buildFromCloud(&tmpCloud1))
        return ;


    for (unsigned i = 0; i < tmpCloud1.size(); i++)
    {
        //    int i = tmpCloud1.size()-1;
        const CCVector3 *q0 = tmpCloud1.getPoint(i);

        std::vector<unsigned> points;
        if (intermediateTree.findPointsLyingToDistance(q0->u, g_CAppConfig.dis,g_CAppConfig.dis,points))
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
            std::sort(IndicesDists.begin(), IndicesDists.end(),  IndexDistLyg_Sorter());

            // perform
            std::vector<std::pair<int, double>>::iterator iter;
            for(iter = IndicesDists.begin(); iter!=IndicesDists.end(); iter++)
            {
                std::cout<<iter->first<<" sort twopointdistance: "<<iter->second<<std::endl;

                if((int)(i-iter->first)>g_CAppConfig.frontToBackfram)
                {
                    //perform
                    std::cout<<i<<"perform = "<<iter->first<<std::endl;

                    match.push_back(std::make_pair(i, iter->first));

                    i = i+g_CAppConfig.jumpfram;
                    break;
                }

            }


        }

    }

}


///
/// \brief ClidarCompute::SqereTrajectory
/// \param outfileName
/// \param _vec
///
void ClidarCompute::SqereTrajectory(std::string outfileName, std::vector<std::string> _vec)
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


