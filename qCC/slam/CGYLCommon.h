


#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <math.h>


#include <vector>

#include <fstream>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <malloc.h>
#include <algorithm>

#include <qstring.h>



using namespace std;



class CAppConfig
{
public:

    float dis = 20.0f;
    int frontToBackfram = 200;
    int jumpfram = 200;
    int firstsatrt = 10;
    int firststep = 30;
    int secondsatrt = -10;
    int secondstep = 30;
    std::string Matched = "Matched";
    std::string Matching = "Matching";
    QString MATCHName = "MATCH_";
    QString currentOpenDlgFilter = "Point Cloud Library cloud (*.pcd)";

};




namespace lygs{


//typedef struct _trajectoryData {
//    std::string name;
//    long double time;
//    float x, y, z;
//    float roll, pitch, yaw;
//    float latitude, longitude, altitude;

//}trajectoryData, *trajectoryDataPtr;
 struct SensorTrajectoryData {
    std::string name;
    long double time;
    float x, y, z;
    float roll, pitch, yaw;
    float latitude, longitude, altitude;

};




/** operator "<" for std::sort() */
struct IndexDistLyg_Sorter {
    /** std::pair<IndexType,DistanceType> */
    template <typename PairType>
    inline bool operator()(const PairType &p1, const PairType &p2) const {
        //        return p1.second - p2.second<0.001f;
        return p1.second < p2.second;
    }
};


class CConstPer {

    public:
    template <typename T>
    static T pi_const()
    {
        return static_cast<T>(3.14159265358979323846);
    }
    
};




class CGYLCommon
{
public:
    CGYLCommon(){}


 

    template <class Type>
    Type stringToNum(const string& str)
    {
        istringstream iss(str);
        Type num;
        iss >> num;
        return num;
    }


    std::vector<double>  WGS84toECEF(double latitude, double longitude, double height)
    {

        double X;
        double Y;
        double Z;
        double a = 6378137.0;
        double b = 6356752.31424518;
        double E = (a * a - b * b) / (a * a);
        double COSLAT = cos(latitude * CConstPer::pi_const<long double>() / 180);
        double SINLAT = sin(latitude * CConstPer::pi_const<long double>() / 180);
        double COSLONG = cos(longitude * CConstPer::pi_const<long double>() / 180);
        double SINLONG = sin(longitude * CConstPer::pi_const<long double>() / 180);
        double N = a / (sqrt(1 - E * SINLAT * SINLAT));
        double NH = N + height;
        X = NH * COSLAT * COSLONG;
        Y = NH * COSLAT * SINLONG;
        Z = (b * b * N / (a * a) + height) * SINLAT;


        return std::vector<double> {X,Y,Z};
    }
    string  setALL(string s1, int icount)
    {
        while (s1.size()<icount)
        {
            s1="0"+s1;
        }
        return s1;
    }

    vector<string>  splittoxian(const string &s, const string &seperator) {
        vector<string> result;
        typedef string::size_type string_size;
        string_size i = 0;

        while (i != s.size()) {
            int flag = 0;
            while (i != s.size() && flag == 0) {
                flag = 1;
                for (string_size x = 0; x < seperator.size(); ++x)
                    if (s[i] == seperator[x]) {
                        ++i;
                        flag = 0;
                        break;
                    }
            }

            flag = 0;
            string_size j = i;
            while (j != s.size() && flag == 0) {
                for (string_size x = 0; x < seperator.size(); ++x)
                    if (s[j] == seperator[x]) {
                        flag = 1;
                        break;
                    }
                if (flag == 0)
                    ++j;
            }
            if (i != j) {
                result.push_back(s.substr(i, j - i));
                i = j;
            }
        }
        return result;
    }

    std::vector<SensorTrajectoryData>  readTrajectoryToxian(string fileName, std::map<string, SensorTrajectoryData> &trajectorys)
    {
        ifstream myfile(fileName);

        std::vector<SensorTrajectoryData> _SensorTrajectoryDatav;
        if (!myfile.is_open())
        {
            std::cout << "can not open this file:" << fileName << endl;
            return _SensorTrajectoryDatav;
        }

        //float temp;
        string temp;
        while (!myfile.eof())
        {
            myfile >> temp;
            vector<string> res = splittoxian(temp, ",");
            int i = 0;
            SensorTrajectoryData para;
            string timeStr = res[0];

            std::string str = res[i++];
            str.erase(std::remove(str.begin(),str.end(),'.'),str.end());
            para.name = timeStr;
            para.time = stringToNum<long double>(str);
            para.x = atof(res[i++].c_str());
            para.y = atof(res[i++].c_str());
            para.z = atof(res[i++].c_str());
            para.roll = atof(res[i++].c_str());
            para.pitch = atof(res[i++].c_str());
            para.yaw = atof(res[i++].c_str());
            //        trajectorys.push_back(para);
            trajectorys[timeStr] = para;
            _SensorTrajectoryDatav.push_back(para);
            //        std::cout<<para.name <<std::endl;


        }

        return _SensorTrajectoryDatav;
    }


    std::vector<SensorTrajectoryData>  readTrajectoryToxian1(string fileName, std::map<string, SensorTrajectoryData> &trajectorys)
    {
        ifstream myfile(fileName);

        std::vector<SensorTrajectoryData> _SensorTrajectoryDatav;
        if (!myfile.is_open())
        {
            std::cout << "can not open this file:" << fileName << endl;
            return _SensorTrajectoryDatav;
        }

        //float temp;
        string temp;
        while (!myfile.eof())
        {
            myfile >> temp;
            vector<string> res = splittoxian(temp, ",");
            if(res.size() < 7){
                std::cout<<"loadTrajectory errot"<< std::endl;
                return _SensorTrajectoryDatav;
            }

            int i = 0;
            SensorTrajectoryData para;
            string timeStr = res[0];

            std::string str = res[i++];
            str.erase(std::remove(str.begin(),str.end(),'.'),str.end());
            para.name = timeStr;
            para.time = stringToNum<long double>(str);
            para.x = atof(res[i++].c_str());
            para.y = atof(res[i++].c_str());
            para.z = atof(res[i++].c_str());
            para.roll = atof(res[i++].c_str());
            para.pitch = atof(res[i++].c_str());
            para.yaw = atof(res[i++].c_str());
            para.latitude    = atof(res[i++].c_str());
            para.longitude   = atof(res[i++].c_str());
            para.altitude    = atof(res[i++].c_str());
            //        trajectorys.push_back(para);
            trajectorys[timeStr] = para;
            _SensorTrajectoryDatav.push_back(para);
            //        std::cout<<para.name <<std::endl;


        }

        return _SensorTrajectoryDatav;
    }


    //    void loadTrajectory(std::string name){

    //        std::ifstream infile;
    //        int id = 0;
    //        std::string line;
    //        _trajectoryData pose;
    //        infile.open(name, std::ios::in);

    //        if(infile.is_open ()){
    //            while (!infile.eof()){


    //                infile >> line;
    //                std::vector<std::string> res = split(line, ",");
    //                if(res.size() < 7){
    //                    std::cout<<"loadTrajectory errot"<< std::endl;
    //                    return;
    //                }
    //                pose.id = id++;
    //                pose.time  = atof(res[0].c_str());
    //                pose.x     = atof(res[1].c_str());
    //                pose.y     = atof(res[2].c_str());
    //                pose.z     = atof(res[3].c_str());
    //                pose.roll  = atof(res[4].c_str());
    //                pose.pitch = atof(res[5].c_str());
    //                pose.yaw   = atof(res[6].c_str());
    //                pose.latitude    = atof(res[7].c_str());
    //                pose.longitude   = atof(res[8].c_str());
    //                pose.altitude    = atof(res[9].c_str());



    //                infile.get();
    //                if(infile.peek() == '\n'){
    //                    break;
    //                }
    //            }
    //        }
    //    }


};



}







//    static  float dis;
//    static  int frontToBackfram ;
//    static  int jumpfram ;
//    static  int firstsatrt ;
//    static  int firststep;
//    static  int secondsatrt;
//    static  int secondstep;
//    static  std::string Matched;
//    static  std::string Matching;
//    static  QString MATCHName;
//    static  QString currentOpenDlgFilter;

//    constexpr static float dis = 20.0f;
//    const static int frontToBackfram = 200;
//    const static int jumpfram = 200;
//    const static int firstsatrt = 10;
//    const static int firststep = 30;
//    const static int secondsatrt = -10;
//    const static int secondstep = 30;
//    constexpr static std::string Matched = "Matched";
//    constexpr static std::string Matching = "Matching";
//    constexpr static QString MATCHName = "MATCH_";
//    constexpr static QString currentOpenDlgFilter = "Point Cloud Library cloud (*.pcd)";

//    static  float getdis(){
//        return dis;
//    };

//    static  int getfrontToBackfram(){
//        return frontToBackfram;
//    };
//    static  int getjumpfram(){
//        return jumpfram;
//    };
//    static  int getfirstsatrt(){
//        return firstsatrt;
//    };
//    static  int getfirststep(){
//        return firststep;
//    };
//    static  int getsecondsatrt(){
//        return secondsatrt;
//    };
//    static  int getsecondstep(){
//        return secondstep;
//    };
//    static  std::string getMatched(){
//        return Matched;
//    };
//    static  std::string getMatching(){
//        return Matching;
//    };
//    static  QString getMATCHName(){
//        return MATCHName;
//    };
//    static  QString getcurrentOpenDlgFilter(){
//        return currentOpenDlgFilter;
//    };
















//#include <ccPointCloud.h>
//#include <pcl/io/pcd_io.h>
//#include <pcl/io/ply_io.h>
//#include <pcl/point_types.h>
//#include <pcl/point_cloud.h>


//////cccloud转换成pcl的pointcloud no rgb--重载一下这个函数


////无色的cccloud ---重载一下这个函数

//void PCLcloudToCCcloud(pcl::PointCloud<pcl::PointXYZ>::Ptr pclCloud, ccPointCloud* m_cloud)

//{

//    int num = pclCloud->points.size();

//    m_cloud->reserve(static_cast<unsigned>(num));

//    for (int i = 0; i < num; i++)

//    {

//        CCVector3 P11(pclCloud->points[i].x, pclCloud->points[i].y, pclCloud->points[i].z);
//        m_cloud->addPoint(P11);

//    }

//}

////----------------------pointCloud转ccCloud---------------------

//void PCLcloudToCCcloudRGB(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pclCloud, ccPointCloud* m_cloud)

//{

//    int num = pclCloud->points.size();

//    m_cloud->reserve(static_cast<unsigned>(num));

//    for (int i = 0; i < num; i++)

//    {

//        CCVector3 P11(pclCloud->points[i].x, pclCloud->points[i].y, pclCloud->points[i].z);

//        m_cloud->addPoint(P11);



//        ccColor::Rgb rgb;//定义一个颜色

//        if (pclCloud->points[0].r <= 1 && pclCloud->points[0].g <= 1)

//        {

//            rgb = ccColor::Rgb(pclCloud->points[i].r*255, pclCloud->points[i].g*255, pclCloud->points[i].b*255);

//        }

//        else

//        {

//            rgb = ccColor::Rgb(pclCloud->points[i].r, pclCloud->points[i].g, pclCloud->points[i].b);

//        }

//        m_cloud->resizeTheRGBTable(true);

//        m_cloud->setPointColor(i, rgb);

//    }

//}


//void PCLcloudToCCcloudI(pcl::PointCloud<pcl::PointXYZI>::Ptr pclCloud, ccPointCloud* m_cloud)

//{

//    //    int num = pclCloud->points.size();

//    //    m_cloud->reserve(static_cast<unsigned>(num));


//    //    for (int i = 0; i < num; i++)

//    //    {

//    //        CCVector3 P11(pclCloud->points[i].x, pclCloud->points[i].y, pclCloud->points[i].z);
//    //        m_cloud->addPoint(P11);


//    //        static const int lodIconSize = 32;
//    //        static const int margin = 6;
//    //        static const unsigned lodIconParts = 12;
//    //        static const float lodPartsRadius = 3.0f;


//    //        static const float radius = lodIconSize / 2.0f - lodPartsRadius;
//    //        static const float alpha = static_cast<float>((2 * M_PI) / lodIconParts);



//    //            float intensity = pclCloud->intensity;
//    //            intensity /= ccColor::MAX;


//    //            float col[3] = {	textCol.rgb[0] * intensity,
//    //                                textCol.rgb[1] * intensity,
//    //                                textCol.rgb[2] * intensity };

//    //        //current intensity (x3)
//    //        int I = static_cast<int>(R) + static_cast<int>(G) + static_cast<int>(B);
//    //        if (I == 0)
//    //        {
//    //            continue; //black remains black!
//    //        }


//    //    }



//    //    int R = 0;
//    //    int G = 0;
//    //    int B = 0;

//    //    int num = pclCloud->points.size();

//    //    m_cloud->reserve(static_cast<unsigned>(num));

//    //    for (int i = 0; i < num; i++)

//    //    {

//    //         CCVector3 P11(pclCloud->points[i].x, pclCloud->points[i].y, pclCloud->points[i].z);

//    //         m_cloud->addPoint(P11);


//    //        float intensity = pclCloud->intensity;
//    //         ccColor::Rgb rgb;//定义一个颜色

//    //         rgb = ccColor::Rgb(intensity, pclCloud->points[i].g, pclCloud->points[i].b);

//    ////         if (pclCloud->points[0].r <= 1 && pclCloud->points[0].g <= 1)

//    ////         {

//    ////              rgb = ccColor::Rgb(pclCloud->points[i].r*255, pclCloud->points[i].g*255, pclCloud->points[i].b*255);

//    ////         }

//    ////         else

//    ////         {

//    ////              rgb = ccColor::Rgb(pclCloud->points[i].r, pclCloud->points[i].g, pclCloud->points[i].b);

//    ////         }

//    //         m_cloud->resizeTheRGBTable(true);

//    //         m_cloud->setPointColor(i, rgb.rgb);

//    //    }



//}




//void CSlamLadirDialog::loadpointPCD(const QString objname,	const QStringList& filenames)
//{

//    //    pcl::PointCloud<pcl::PointXYZ>::Ptr pclCloudALL(new pcl::PointCloud<pcl::PointXYZ>);
//    //    ccPointCloud* newGroups = new ccPointCloud(objname);


//    //    for ( const QString &filename : filenames )
//    //    {
//    //        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
//    //        if (pcl::io::loadPCDFile<pcl::PointXYZ>(filename.toStdString(), *cloud) < 0)
//    //        {
//    //            PCL_ERROR("Could not read file\n");
//    //            continue;
//    //        }
//    //        *pclCloudALL = * pclCloudALL + *cloud;



//    //    }

//    //    PCLcloudToCCcloud(pclCloudALL, newGroups);

//    //    ccHObject* newGroupname = new ccHObject(objname);
//    //    newGroupname->addChild(newGroupname);
//    //    m_pMainWindow->addToDB(newGroupname, true, true, false);


//}






