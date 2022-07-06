#ifndef CSLAMLADIRDIALOG_H
#define CSLAMLADIRDIALOG_H





#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <math.h>



#include <QDialog>
#include <QVector3D>


#include "ccOverlayDialog.h"


#include "ccGLMatrix.h"

//common
#include <ccPickingHub.h>
//common dialogs
#include <ccCameraParamEditDlg.h>
#include <ccDisplayOptionsDlg.h>
#include <ccPickOneElementDlg.h>
#include <ccStereoModeDlg.h>
#include <QFileDialog>
#include <QProgressDialog>
#include <ccPointCloud.h>
#include <mainwindow.h>
#include <QThread>
#include "ccHObject.h"

//QCC_glWindow
#include <ccGLWidget.h>
#include <ccRenderingTools.h>
#include "CGYLCommon.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/basic_file_sink.h"

//#include "CObjCCAlgorithm.h"

using namespace CCCoreLib;
using namespace lygs;
struct _MapMatch
{
    QString matched;
    QStringList matchedlist;  //big

    QString matching;
    QStringList matchinglist; //small

    QString name;

    bool isSame = false;

    int matchedid = 0;
    int matchedingid = 0;

};



namespace Ui {
class CSlamLadirDialog;
}

class ccPointCloud;
class MainWindow;
class ccHObject;
class ClidarCompute;
class CAppConfig;
class CBackOptimization;
class CSlamLadirDialog :public ccOverlayDialog
{
    Q_OBJECT

public:

    ///
    /// \brief CSlamLadirDialog
    /// \param parent
    /// \param _pMainWindow
    ///
    explicit
    CSlamLadirDialog(QWidget *parent = nullptr, MainWindow *_pMainWindow = nullptr);
    ~CSlamLadirDialog();


    ///
    /// \brief SetShowCloudPoint
    /// \param match
    ///
    void
    SetShowCloudPoint(std::vector<std::pair<unsigned, unsigned> > match,
                      std::function<_MapMatch(int,int,bool)> func, bool isSame = false);


    ///
    /// \brief changeMat
    /// \param obj
    /// \param strfilename
    /// \return
    ///
    ccPointCloud *
    changeMat(ccPointCloud *obj, std::string strfilename);


    ///
    /// \brief GetFileName
    /// \return
    ///
    std::string
    GetFileName(){return m_filename;}

    ///
    /// \brief GetFileNameTnt
    /// \return
    ///
    std::string
    GetFileNameTnt(){return m_filenametnt;}


    ///
    /// \brief GetGlobalOptimization
    /// \return
    ///
    std::shared_ptr<CBackOptimization>
    GetGlobalOptimization(){
        return  g_CDataChange ;
    }

    ///
    /// \brief GetLogger
    /// \return
    ///
    std::shared_ptr<spdlog::logger>
    GetLogger(){return  my_logger;}



    ///
    /// \brief m_IndextrajectoryMap
    ///
    std::map<int,ccGLMatrix> m_IndextrajectoryMap;


private:

    ///
    /// \brief loadpoint
    /// \param newGroups
    /// \param objname
    /// \param filenames
    /// \param dir
    /// \param fileFilter
    /// \param destWin
    ///
    void
    loadpoint(ccHObject* newGroups,const QString objname, const QStringList& filenames, QString dir = "",
                    QString fileFilter = QString(),
                   ccGLWindow* destWin = nullptr );

    ///
    /// \brief loadPointCloud
    /// \param objname
    /// \param filenames
    /// \param dir
    /// \param fileFilter
    /// \param destWin
    /// \return
    ///
    ccPointCloud *
    loadPointCloud(const QString objname,	const QStringList& filenames, QString dir,
                                     QString fileFilter/*=QString()*/,
                                     ccGLWindow* destWin/*=0*/ = nullptr );

    ////
    /// \brief loadpointPCD
    /// \param objname
    /// \param filenames
    ///
    void
    loadpointPCD(const QString objname, const QStringList &filenames);



    ///
    /// \brief DataSpit
    /// \param first
    /// \param second
    /// \return
    ///
    _MapMatch ReserveDirDataSpit(int first, int second,bool isSameDir = false);

    ///
    /// \brief SameDirDataSpit
    /// \param first
    /// \param second
    /// \return
    ///
    _MapMatch SameDirDataSpit(int first,int second);


    ///
    /// \brief ShowTrajectorydata
    ///
    void ShowTrajectorydata();



    ///
    /// \brief SetResampleGui
    /// \param cloud
    /// \return
    ///
    std::vector<ccPointCloud *>  SetResampleGui(ccPointCloud* cloud);



    ///
    /// \brief SetResample
    /// \param cloud
    /// \return
    ///
    std::vector<ccPointCloud *>  SetResample(ccPointCloud* cloud);

    ///
    bool GetResultRegister(ccGLMatrix finalTrans,int m_strfirstID,int m_strsecondID);

    double DistanceResultRegister(ccGLMatrix finalTrans,int m_strfirstID,int m_strsecondID  );
    

signals:
    void
    SignalsLoadPath(QList<QVector3D> _vec);
    void
    SignalsResample();
    void
    SignalsRegisterPoint();
    void
    SignalsTransFrom();
    void
    SignalsSavePath();

private slots:
    void
    on_load_path_clicked();
    void on_pushButton_test_clicked();

private:
    Ui::CSlamLadirDialog *ui;
    MainWindow * m_pMainWindow = nullptr;
    QString m_pointDir = nullptr;
    std::string m_filename = "0";
    std::string m_filenametnt = "0";
    std::vector<SensorTrajectoryData> m_vecs ;
    std::map<std::string,SensorTrajectoryData> g_trajectoryMap;
    QStringList m_selectedFiles;
    int m_currentOptimizationType = 0;


    std::shared_ptr<spdlog::logger> my_logger = nullptr;
    std::shared_ptr<CBackOptimization> g_CDataChange = nullptr;

    ccHObject* m_ladirnewGroup = nullptr;

private:
    ///
    /// \brief initForm
    ///
    void
    initForm();

    ///
    /// \brief DataClear
    ///
    void DataClear();


};

#endif // CSLAMLADIRDIALOG_H
