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

#include "CGYLCommon.h"

#include "ccGLMatrix.h"

//#include "CDataChange.h"
//#include "CDataChange.h"


namespace Ui {
class CSlamLadirDialog;
}

class ccPointCloud;
class MainWindow;
class CSlamLadirDialog :public ccOverlayDialog
{
    Q_OBJECT

public:
    std::map<int,ccGLMatrix> m_IndextrajectoryMap;

    explicit CSlamLadirDialog(QWidget *parent = nullptr, MainWindow *_pMainWindow = nullptr);
    ~CSlamLadirDialog();

    void SetShowCloudPoint(std::vector<std::pair<unsigned, unsigned> > match);
    void loadpoint(const QString objname, const QStringList& filenames, QString dir = "",
                    QString fileFilter = QString(),
                   ccGLWindow* destWin = nullptr );
    void loadpointPCD(const QString objname, const QStringList &filenames);

    ccPointCloud *changeMat(ccPointCloud *obj, std::string strfilename);

    std::string GetFileName(){return m_filename;}
    std::string GetFileNameTnt(){return m_filenametnt;}


signals:
    void SignalsLoadPath(QList<QVector3D> _vec);
    void SignalsTestLoadPath(QList<QVector3D> _vec);
    void SignalsResample();
    void SignalsRegisterPoint();
    void SignalsTransFrom();
    void SignalsSavePath();

private slots:
    void on_load_path_clicked();

    void on_pushButton_resample_clicked();

    void on_setpointfile_clicked();

    void on_getcurrentpath_clicked();

    void on_pushButtonpointresi_clicked();

    void on_btnclose_clicked();

    void on_btnAuto_clicked();

    void on_pushButton_clicked();

    void on_m_btnTransFrom_clicked();

    void on_SavePath_clicked();

    void on_btn_TestPath_clicked();

private:
    Ui::CSlamLadirDialog *ui;


    MainWindow * m_pMainWindow = nullptr;
    QString m_pointDir = nullptr;
    std::string m_filename = "0";
    std::string m_filenametnt = "0";


    std::vector<lygs::trajectoryData> m_vecs ;
    std::map<std::string,lygs::trajectoryData> g_trajectoryMap;



    QString m_currentOpenDlgFilter;
    QStringList m_selectedFiles;
};

#endif // CSLAMLADIRDIALOG_H
