#ifndef CSLAMLADIRDIALOG_H
#define CSLAMLADIRDIALOG_H





#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <math.h>


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

    void SetShowCloudPoint(std::vector<std::pair<unsigned, unsigned> > match);
signals:
    void SignalsLoadPath(QList<QVector3D> _vec);
    void SignalsResample();

private slots:
    void on_load_path_clicked();

    void on_pushButton_resample_clicked();

    void on_setpointfile_clicked();

    void on_getcurrentpath_clicked();

private:
    Ui::CSlamLadirDialog *ui;


    MainWindow * m_pMainWindow = nullptr;
    QString m_pointDir = nullptr;

    std::vector<lyg::trajectoryData> m_vecs ;


    QString m_currentOpenDlgFilter;
};

#endif // CSLAMLADIRDIALOG_H
