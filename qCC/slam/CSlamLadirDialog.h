#ifndef CSLAMLADIRDIALOG_H
#define CSLAMLADIRDIALOG_H





#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <math.h>




//#define M_PI (3.141592653589793238462643383279)
//using namespace std;

//namespace lyg{
//typedef struct _trajectoryData {
//    std::string name;
//    long double time;
//    float x, y, z;
//    float roll, pitch, yaw;
//}trajectoryData, *trajectoryDataPtr;

//}



///** operator "<" for std::sort() */
//struct IndexDistLyg_Sorter {
//    /** std::pair<IndexType,DistanceType> */
//    template <typename PairType>
//    inline bool operator()(const PairType &p1, const PairType &p2) const {
//        return p1.second - p2.second<0.001f;
//    }
//};

//class CGYLCommon
//{
//public:
//    CGYLCommon();

//    template <class Type>
//    Type stringToNum(const string& str)
//    {
//        istringstream iss(str);
//        Type num;
//        iss >> num;
//        return num;
//    }
//    std::string setALL(std::string s1,int icount);
//    vector<string> splittoxian(const string &s, const string &seperator);
//    std::vector<lyg::trajectoryData> readTrajectoryToxian(string fileName, std::map<std::string,lyg::trajectoryData> &trajectorys);

//    static std::vector<double> WGS84toECEF(double latitude, double longitude, double height);



//};















#include "CGYLCommon.h"

#include <QDialog>
#include <QVector3D>

#include "ccOverlayDialog.h"
namespace Ui {
class CSlamLadirDialog;
}

class MainWindow;
class CSlamLadirDialog :public ccOverlayDialog
{
    Q_OBJECT

public:
    explicit CSlamLadirDialog(QWidget *parent = nullptr, MainWindow *_pMainWindow = nullptr);
    ~CSlamLadirDialog();

signals:
    void SignalsLoadPath(QList<QVector3D> _vec);
    void SignalsResample();

private slots:
    void on_load_path_clicked();

    void on_pushButton_resample_clicked();

private:
    Ui::CSlamLadirDialog *ui;


    MainWindow * m_pMainWindow = nullptr;
};

#endif // CSLAMLADIRDIALOG_H
