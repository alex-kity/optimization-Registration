//#include "frmplotpanel.h"
//#include "ui_frmplotpanel.h"
//#include "quihelper.h"

//#define Text_Color QColor(255, 255, 255)
//#define TempDotColor QColor(5, 189, 251)
//#define TempLineColor QColor(41, 138, 220)

//#define TextWidth 0.3
//#define LineWidth 1.5
//#define DotWidth 5

//frmPlotPanel::frmPlotPanel(QWidget *parent) : QWidget(parent), ui(new Ui::frmPlotPanel)
//{
//    ui->setupUi(this);
//    this->initForm();
//    this->initPlot();
//    this->initData();
//    this->loadData();
//}

//frmPlotPanel::~frmPlotPanel()
//{
//    delete ui;
//}

//void frmPlotPanel::initForm()
//{
//    timer = new QTimer(this);
//    timer->setInterval(1000);
//    connect(timer, SIGNAL(timeout()), this, SLOT(loadData()));

//    //X轴数据个数
//    maxX = 20;
//    //Y轴最大值
//    maxY = 200;
//    //放大缩小倍数
//    scal = 20;

////    customPlot = new QCustomPlot;
////    ui->layout->addWidget(customPlot);

////    connect(customPlot, SIGNAL(mousePress(QMouseEvent *)), this, SIGNAL(plotPressed()));
////    connect(ui->btnReturn, SIGNAL(pressed()), this, SIGNAL(plotPressed()));

////    QFont font = this->font();
////    font.setBold(true);
////    font.setPixelSize(15);

////    QList<QPushButton *> btns = ui->widgetBtn->findChildren<QPushButton *>();
////    foreach (QPushButton *btn, btns) {
////        btn->setFont(font);
////        btn->setMinimumWidth(90);
////    }

////    ui->btnReturn->setFont(font);
////    ui->widgetBtn->setVisible(false);
//}

//void frmPlotPanel::initPlot()
//{
////    customPlot->addGraph();
////    customPlot->graph(0)->setName("温度");
////    customPlot->graph(0)->setPen(QPen(TempLineColor, LineWidth));
////    customPlot->graph(0)->setScatterStyle(
////        QCPScatterStyle(QCPScatterStyle::ssCircle,
////                        QPen(TempDotColor, LineWidth),
////                        QBrush(TempDotColor), DotWidth));

////    QFont font = QFont(qApp->font().family(), 8);
////    customPlot->legend->setFont(font);
////    customPlot->xAxis->setLabelFont(font);
////    customPlot->yAxis->setLabelFont(font);
////    customPlot->xAxis->setTickLabelFont(font);
////    customPlot->yAxis->setTickLabelFont(font);

////    //将对应的key用文本替代表示
////#ifdef qcustomplot_v1
////    customPlot->xAxis->setTickVector(keys);
////    customPlot->xAxis->setTickVectorLabels(labs);
////    customPlot->yAxis->setAutoTickCount(7);
////#else
////    //设置标尺为文本标尺
////    QSharedPointer<QCPAxisTickerText> ticker(new QCPAxisTickerText);
////    ticker->addTicks(keys, labs);
////    customPlot->xAxis->setTicker(ticker);
////    customPlot->yAxis->ticker()->setTickCount(7);
////#endif

////    customPlot->xAxis->setRange(-0.5, 5 - 0.5);
////    customPlot->yAxis->setRange(0, maxY);
////    customPlot->yAxis->setLabel(QString("%1 温度曲线").arg(name));

////    customPlot->yAxis->setLabelColor(Text_Color);
////    customPlot->xAxis->setTickLabelColor(Text_Color);
////    customPlot->yAxis->setTickLabelColor(Text_Color);
////    customPlot->xAxis->setBasePen(QPen(Text_Color, TextWidth));
////    customPlot->yAxis->setBasePen(QPen(Text_Color, TextWidth));
////    customPlot->xAxis->setTickPen(QPen(Text_Color, TextWidth));
////    customPlot->yAxis->setTickPen(QPen(Text_Color, TextWidth));
////    customPlot->xAxis->setSubTickPen(QPen(Text_Color, TextWidth));
////    customPlot->yAxis->setSubTickPen(QPen(Text_Color, TextWidth));

////    customPlot->setBackground(QColor(80, 80, 80));
////    customPlot->axisRect()->setBackground(QColor(50, 50, 50));
////    customPlot->replot();

//    //启动定时器模拟数据
//    //timer->start();
//}

//void frmPlotPanel::initData()
//{
//    keys.clear();
//    values.clear();
//    labs.clear();

//    for (int i = 0; i < maxX; i++) {
//        keys.append(i);
//        values.append((rand() % 10) + 80);
//        labs.append(QString::number(i + 1));
//    }
//}

//void frmPlotPanel::loadData()
//{
//    double value = (rand() % 10) + 80;
//    appendTempValue(value);
//}

//void frmPlotPanel::setName(const QString &name)
//{
//    this->name = name;
//}

//void frmPlotPanel::setMaxX(int maxX)
//{
////    if (this->maxX != maxX) {
////        this->maxX = maxX;
////        customPlot->xAxis->setRange(-0.5, maxX - 0.5);
////        customPlot->replot();
////    }
//}

//void frmPlotPanel::setMaxY(int maxY)
//{
////    if (this->maxY != maxY && (maxY / 20) > 0) {
////        this->maxY = maxY;
////        customPlot->yAxis->setRange(0, maxY);
////#ifdef qcustomplot_v1
////        customPlot->yAxis->setAutoTickCount(maxY / 20);
////#else
////        customPlot->yAxis->ticker()->setTickCount(maxY / 20);
////#endif
////        customPlot->replot();
////    }
//}

//void frmPlotPanel::appendTempValue(double value)
//{
////    //移除第一个数据,增加一个数据,保证每次集合数据一致
////    //labs.remove(0, 1);
////    //labs.append("1");
////    values.remove(0, 1);
////    values.append(value);

////    customPlot->graph(0)->setData(keys, values);
////#ifdef qcustomplot_v1
////    customPlot->xAxis->setTickVector(keys);
////    customPlot->xAxis->setTickVectorLabels(labs);
////#else
////    QSharedPointer<QCPAxisTickerText> ticker(new QCPAxisTickerText);
////    ticker->addTicks(keys, labs);
////    customPlot->xAxis->setTicker(ticker);
////#endif
////    customPlot->replot();
//}

//void frmPlotPanel::saveData(const QString &fileName)
//{
////    //保存数据文件
////    QFile file(fileName + ".csv");
////    if (file.open(QFile::WriteOnly)) {
////        QStringList data;
////        foreach (double value, values) {
////            data << QString::number(value);
////        }

////        file.write(data.join(",").toLatin1());
////    }

////    //保存图片文件
////    customPlot->saveJpg(fileName + ".jpg");
//}

//void frmPlotPanel::setBtnHide(bool hide)
//{
////    if (hide) {
////        //connect(customPlot, SIGNAL(mousePress(QMouseEvent *)), this, SIGNAL(plotPressed()));
////        customPlot->setInteractions(QCP::iSelectOther);
////        //customPlot->yAxis->setAutoTickCount(7);
////        customPlot->xAxis->setRange(-0.5, 5 - 0.5);
////    } else {
////        //disconnect(customPlot, SIGNAL(mousePress(QMouseEvent *)), this, SIGNAL(plotPressed()));
////        customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
////        //customPlot->yAxis->setAutoTickCount(maxY / 20);
////        customPlot->xAxis->setRange(-0.5, maxX - 0.5);
////    }

////    //customPlot->legend->setVisible(!hide);
////    ui->widgetBtn->setVisible(!hide);

////    initData();
////    loadData();
//}

//void frmPlotPanel::on_btnSaveData_clicked()
//{
//    //自动计数累加
//    static int index = 0;
//    saveData(QString("%1/%2").arg(qApp->applicationDirPath()).arg(index));
//    index++;
//}

//void frmPlotPanel::on_btnAdd_clicked()
//{
////#if (QT_VERSION < QT_VERSION_CHECK(6,0,0))
////    QWheelEvent wheelEvent(customPlot->rect().center(), scal, Qt::LeftButton, Qt::NoModifier);
////    QApplication::sendEvent(customPlot, &wheelEvent);
////#endif
////}

////void frmPlotPanel::on_btnDec_clicked()
////{
////#if (QT_VERSION < QT_VERSION_CHECK(6,0,0))
////    QWheelEvent wheelEvent(customPlot->rect().center(), -scal, Qt::LeftButton, Qt::NoModifier);
////    QApplication::sendEvent(customPlot, &wheelEvent);
////#endif
//}

//void frmPlotPanel::on_btnAuto_clicked()
//{
////    customPlot->rescaleAxes();
////    customPlot->replot();
//}

//void frmPlotPanel::on_btnFull_clicked()
//{
////    customPlot->xAxis->setRange(-0.5, maxX - 0.5);
////    customPlot->yAxis->setRange(0, maxY);
////    customPlot->replot();
//}
