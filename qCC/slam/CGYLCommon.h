


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




#define M_PI (3.141592653589793238462643383279)
using namespace std;

namespace lygs{
typedef struct _trajectoryData {
    std::string name;
    long double time;
    float x, y, z;
    float roll, pitch, yaw;
}trajectoryData, *trajectoryDataPtr;





/** operator "<" for std::sort() */
struct IndexDistLyg_Sorter {
    /** std::pair<IndexType,DistanceType> */
    template <typename PairType>
    inline bool operator()(const PairType &p1, const PairType &p2) const {
//        return p1.second - p2.second<0.001f;
        return p1.second < p2.second;
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
        double COSLAT = cos(latitude * M_PI / 180);
        double SINLAT = sin(latitude * M_PI / 180);
        double COSLONG = cos(longitude * M_PI / 180);
        double SINLONG = sin(longitude * M_PI / 180);
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

    std::vector<trajectoryData>  readTrajectoryToxian(string fileName, std::map<string, trajectoryData> &trajectorys)
    {
        ifstream myfile(fileName);

        std::vector<trajectoryData> _trajectoryDatav;
        if (!myfile.is_open())
        {
            std::cout << "can not open this file:" << fileName << endl;
            return _trajectoryDatav;
        }

        //float temp;
        string temp;
        while (!myfile.eof())
        {
            myfile >> temp;
            vector<string> res = splittoxian(temp, ",");
            int i = 0;
            trajectoryData para;
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
            _trajectoryDatav.push_back(para);
            //        std::cout<<para.name <<std::endl;


        }

        return _trajectoryDatav;
    }





};



}



