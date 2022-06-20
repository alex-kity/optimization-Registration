//#ifndef FRMPLOTPANEL_H
//#define FRMPLOTPANEL_H

//#include <QWidget>

////#ifdef qcustomplot_v1
////#include "qcustomplot1.h"
////#elif qcustomplot_v2
////#include "qcustomplot2.h"
////#else
////#include "qcustomplot3.h"
////#endif

//namespace Ui {
//class frmPlotPanel;
//}

//class frmPlotPanel : public QWidget
//{
//    Q_OBJECT

//public:
//    explicit frmPlotPanel(QWidget *parent = 0);
//    ~frmPlotPanel();

//private:
//    Ui::frmPlotPanel *ui;
//    QString name;
//    QTimer *timer;
//    int maxX;
//    int maxY;
//    int scal;

////    QCustomPlot *customPlot;
//    QVector<double> keys;       //横坐标索引
//    QVector<double> values;     //横坐标数据
//    QVector<QString> labs;      //横坐标字符串

//private slots:
//    void initForm();
//    void initPlot();
//    void initData();
//    void loadData();

//private slots:
//    void on_btnSaveData_clicked();
//    void on_btnAdd_clicked();
////    void on_btnDec_clicked();
//    void on_btnAuto_clicked();
//    void on_btnFull_clicked();

//signals:
//    void plotPressed();

//public slots:
//    void setName(const QString &name);
//    void setMaxX(int maxX);
//    void setMaxY(int maxY);
//    void appendTempValue(double value);

//    //保存数据和图像
//    void saveData(const QString &fileName);
//    void setBtnHide(bool hide);

//};

//#endif // FRMPLOTPANEL_H
