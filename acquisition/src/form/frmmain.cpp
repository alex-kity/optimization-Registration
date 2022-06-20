#include "frmmain.h"
#include "ui_frmmain.h"
#include "quihelper.h"
#include "iconhelper.h"
#include "frmstylewidget.h"

#include "frmdevice.h"
#include "frmplot.h"
#include "frmconfig.h"
#include "frmdevicecontrol.h"

frmMain::frmMain(QWidget *parent) : QDialog(parent), ui(new Ui::frmMain)
{
    ui->setupUi(this);
    this->initForm();
    this->initBtn();
    this->changeStyle("#159C77");
    ui->btnDevice->click();
}

frmMain::~frmMain()
{
    delete ui;
}

bool frmMain::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->widgetTitle) {
        if (event->type() == QEvent::MouseButtonDblClick) {
            this->on_btnMenu_Max_clicked();
            return true;
        }
    }

    return QWidget::eventFilter(watched, event);
}

void frmMain::initForm()
{
    //设置无边框
    QUIHelper::setFramelessForm(this);
    //设置图标
    IconHelper::setIcon(ui->labIco, 0xf0f4, 25);
    IconHelper::setIcon(ui->btnMenu_Style, 0xf1fb, 15);
    IconHelper::setIcon(ui->btnMenu_Min, 0xf068, 15);
    IconHelper::setIcon(ui->btnMenu_Max, 0xf067, 15);
    IconHelper::setIcon(ui->btnMenu_Close, 0xf00d, 15);

    ui->labTitle->setText("传感器控制系统");
    ui->widgetLeft->setProperty("flag", "nav");

    //如果不需要标题栏,只需要隐藏标题栏即可
    //默认ARM上会有标题栏,但是没有最小化最大化关闭按钮
    ui->widgetTitle->setVisible(true);
    ui->widgetTime->setVisible(false);

#ifdef __arm__
    ui->btnMenu_Min->setVisible(false);
    ui->btnMenu_Max->setVisible(false);
    ui->btnMenu_Close->setVisible(false);
    on_btnMenu_Max_clicked();
#else
    ui->btnMenu_Min->setVisible(true);
    ui->btnMenu_Max->setVisible(true);
    ui->btnMenu_Close->setVisible(true);
    ui->widgetTitle->installEventFilter(this);
#endif

    style = new frmStyleWidget;
    connect(style, SIGNAL(changeStyle(QString)), this, SLOT(changeStyle(QString)));
    style->setCurrentStyle(4);

    frmDevice *device = new frmDevice;
    frmplot *plot = new frmplot;
    frmConfig *config = new frmConfig;

    connect(style, SIGNAL(changeStyle(QString)), device, SIGNAL(changeStyle(QString)));
    connect(style, SIGNAL(changeStyle(QString)), frmDeviceControl::Instance(), SLOT(changeStyle(QString)));

    connect(config, SIGNAL(setMaxX(int)), plot, SIGNAL(setMaxX(int)));
    connect(config, SIGNAL(setMaxY(int)), plot, SIGNAL(setMaxY(int)));

    ui->stackedWidget->addWidget(device);
    ui->stackedWidget->addWidget(plot);
    ui->stackedWidget->addWidget(config);

    //启动时间定时器,并立即执行一次
    QTimer *timerTime = new QTimer(this);
    connect(timerTime, SIGNAL(timeout()), this, SLOT(changeTime()));
    timerTime->setInterval(1000);
    timerTime->start();
    changeTime();
}

void frmMain::initBtn()
{
    icons << 0xf26c << 0xf074 << 0xf0ad;
    btns << ui->btnDevice << ui->btnPlot << ui->btnConfig;
    ui->btnDevice->setText("采集设置");
    ui->btnPlot->setText("采集状态");
    ui->btnConfig->setText("系统设置");

    int count = btns.count();
    for (int i = 0; i < count; i++) {
        QToolButton *btn = btns.at(i);
        btn->setCheckable(true);
        btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        connect(btn, SIGNAL(clicked(bool)), this, SLOT(buttonClicked()));
    }
}

void frmMain::buttonClicked()
{

    QToolButton *b = (QToolButton *)sender();
    QString name = b->text();
    qDebug()<<b->text();

    int count = btns.count();
    for (int i = 0; i < count; i++) {
        if (btns.at(i) == b) {
            btns.at(i)->setChecked(true);
            btns.at(i)->setIcon(QIcon(pixDark.at(i)));
        } else {
            btns.at(i)->setChecked(false);
            btns.at(i)->setIcon(QIcon(pixNormal.at(i)));
        }
    }

    if (name == "采集设置") {
        ui->stackedWidget->setCurrentIndex(0);
    } else if (name == "采集状态") {
        ui->stackedWidget->setCurrentIndex(1);
    } else if (name == "系统设置") {
        ui->stackedWidget->setCurrentIndex(2);
    }
}

void frmMain::changeTime()
{
    QDateTime now = QDateTime::currentDateTime();
    ui->labTime->setText(now.toString("HH:mm"));
    ui->labDate->setText(now.toString("yyyy.M.d"));
    QString str = now.toString("dddd");

#ifdef __arm__
    if (str == "Monday") {
        str = "星期一";
    } else if (str == "Tuesday") {
        str = "星期二";
    } else if (str == "Wednesday") {
        str = "星期三";
    } else if (str == "Thursday") {
        str = "星期四";
    } else if (str == "Friday") {
        str = "星期五";
    } else if (str == "Saturday") {
        str = "星期六";
    } else if (str == "Sunday") {
        str = "星期天";
    }
#endif

    ui->labDay->setText(str);
}

void frmMain::changeStyle(const QString &color)
{
    QString mainBgColor = "#FFFFFF";
    QString mainTextNormalColor = "#5C5C5C";
    QString mainTextDarkColor = "#474849";
    QString titleBgColor = color;
    QString titleTextNormalColor = "#F0F0F0";
    QString titleTextDarkColor = "#FFFFFF";
    QString navBgColor = "#F6F6F8";
    QString navBtnBgColor = "#EAEAEA";
    QString navBtnBorderColor = color;
    QString borderColor = "#E1E1E2";

    setStyle(mainBgColor, mainTextNormalColor, mainTextDarkColor, titleBgColor, titleTextNormalColor,
             titleTextDarkColor, navBgColor, navBtnBgColor, navBtnBorderColor, borderColor);
}

void frmMain::setStyle(const QString &mainBgColor, const QString &mainTextNormalColor,
                       const QString &mainTextDarkColor, const QString &titleBgColor,
                       const QString &titleTextNormalColor, const QString &titleTextDarkColor,
                       const QString &navBgColor, const QString &navBtnBgColor,
                       const QString &navBtnBorderColor, const QString &borderColor)
{
    //生成图标
    pixNormal.clear();
    pixDark.clear();

    int iconSize = 16;
    int iconWidth = 35;
    int iconHeight = 25;

    int btnCount = btns.count();
    for (int i = 0; i < btnCount; i++) {
        //存储对应按钮对象,方便鼠标移上去的时候切换图片
        QPixmap pixNormal = IconHelper::getPixmap(mainTextNormalColor, icons.at(i), iconSize, iconWidth, iconHeight);
        QPixmap pixDark = IconHelper::getPixmap(mainTextDarkColor, icons.at(i), iconSize, iconWidth, iconHeight);

        btns.at(i)->setIcon(QIcon(pixNormal));
        btns.at(i)->setIconSize(QSize(iconWidth, iconHeight));

        this->pixNormal.append(pixNormal);
        this->pixDark.append(pixDark);
    }

    QStringList qss;

    //自定义开关按钮样式
    qss.append(QString("SwitchButton{qproperty-showText:true;qproperty-textOff:停止;qproperty-textOn:启动;"
                       "qproperty-bgColorOn:%1;qproperty-sliderColorOff:%2;qproperty-sliderColorOff:%2;}").arg(titleBgColor).arg("#FFFFFF"));

    //自定义仪表盘控件和温度计控件样式
    qss.append(QString("BarTemp{qproperty-barColor:%1;}GaugeSimple{qproperty-usedColor:%1;qproperty-userValueColor:%1;}").arg(titleBgColor));

    //全局无焦点虚边框,全局文字颜色,全局字号
    qss.append(QString("*{outline:0px;color:%1;}").arg(mainTextNormalColor));
    qss.append(QString("QLabel#labTitle{font:75 %1px;}").arg(18));
    qss.append(QString("QWidget[flag=\"nav\"] QAbstractButton{font:%1px;}").arg(13));

    //日期时间样式
    qss.append(QString("QLabel#labTime{font:%1px;}").arg(18));
    qss.append(QString("QLabel#labDay{font:%1px;}").arg(20));
    qss.append(QString("QLabel#labDate{font:%1px;}").arg(12));

    //主界面
    qss.append(QString("QWidget#widgetMain{background:%1;border:1px solid %2;}").arg(mainBgColor).arg(borderColor));

    //主界面顶部栏背景
    qss.append(QString("QWidget#widgetTitle{background:%1;}").arg(titleBgColor));
    qss.append(QString("QWidget#widgetTitle>QLabel{color:%1;}").arg(titleTextNormalColor));
    qss.append(QString("QWidget#widgetMenu>QAbstractButton{color:%1;}").arg(titleTextNormalColor));

    //主界面顶部右上角
    qss.append(QString("QWidget#widgetMenu QAbstractButton{border:0px solid #000000;}"));
    qss.append(QString("QAbstractButton::menu-indicator{image:None;}"));
    qss.append(QString("QWidget#widgetMenu QAbstractButton:hover,QWidget#widgetMenu QAbstractButton:pressed{color:%1;}").arg(titleTextDarkColor));

    //左侧导航栏
    qss.append(QString("QWidget#widgetLeft{background:%1;}").arg(navBgColor));
    qss.append(QString("QWidget[flag=\"nav\"] QAbstractButton{min-height:%1px;max-height:%1px;}").arg(53));
    qss.append(QString("QWidget[flag=\"nav\"] QAbstractButton{border-style:none;border-radius:0px;padding:5px;color:%1;background:%2;}").arg(mainTextNormalColor).arg(navBtnBgColor));
    qss.append(QString("QWidget[flag=\"nav\"] QAbstractButton:hover,QWidget[flag=\"nav\"] QAbstractButton:pressed,QWidget[flag=\"nav\"] QAbstractButton:checked{"
                       "border-style:solid;border-width:0px 0px 0px %1px;padding:%2px %2px %2px %1px;border-color:%3;color:%4;background:%5;}")
               .arg(3).arg(6).arg(navBtnBorderColor).arg(mainTextDarkColor).arg(navBgColor));

    //按钮
    qss.append(QString("QAbstractButton{border-radius:5px;background:%1;color:%2;border:2px solid %3;}").arg(titleBgColor).arg(titleTextDarkColor).arg(navBtnBgColor));
    qss.append(QString("QAbstractButton:hover,QAbstractButton:pressed{border:2px solid %1;}").arg(mainTextDarkColor));

    //文本框
    qss.append(QString("QLineEdit{border-style:none;padding:3px;border-radius:%1px;border:%2px solid %3;}").arg(5).arg(1).arg(borderColor));
    qss.append(QString("QLineEdit:focus{border:%1px solid %2;}").arg(2).arg(titleBgColor));

    //滑块条样式
    int sliderHeight = 8;
    int handleSize = 16;
    int sliderBorder = 1;
    qss.append(QString("QSlider::groove:horizontal{background:%1;height:%2px;border-radius:%3px;}").arg(navBtnBgColor).arg(sliderHeight).arg(sliderHeight / 2));
    qss.append(QString("QSlider::add-page:horizontal{background:%1;height:%2px;border-radius:%3px;}").arg(navBtnBgColor).arg(sliderHeight).arg(sliderHeight / 2));
    qss.append(QString("QSlider::sub-page:horizontal{background:%1;height:%2px;border-radius:%3px;}").arg(titleBgColor).arg(sliderHeight).arg(sliderHeight / 2));
    qss.append(QString("QSlider::handle:horizontal{width:%1px;margin-top:-%2px;margin-bottom:-%2px;border-radius:%3px;border:%4px solid %5;")
               .arg(handleSize - sliderBorder).arg(handleSize / 4 + sliderBorder).arg(handleSize / 2).arg(sliderBorder).arg(borderColor));
    qss.append(QString("background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.3,fx:0.5,fy:0.5,stop:0.3 %1,stop:0.8 #FFFFFF);}").arg(titleBgColor));

    //滚动条样式
    qss.append(QString("QScrollBar:vertical{background:%1;padding:0px;border-radius:5px;min-width:10px;max-width:10px;}").arg(mainBgColor));
    qss.append(QString("QScrollBar::handle:vertical{background:%1;min-height:120px;border-radius:5px;}").arg(mainTextNormalColor));
    qss.append(QString("QScrollBar::handle:vertical:hover{background:%1;}").arg(mainTextDarkColor));
    qss.append(QString("QScrollBar::handle:vertical:pressed{background:%1;}").arg(mainTextDarkColor));
    qss.append(QString("QScrollBar::add-page:vertical{background:none;}"));
    qss.append(QString("QScrollBar::sub-page:vertical{background:none;}"));
    qss.append(QString("QScrollBar::add-line:vertical{background:none;}"));
    qss.append(QString("QScrollBar::sub-line:vertical{background:none;}"));

    //进度条样式
    int barHeight = 15;
    int barRadius = 7;
    qss.append(QString("QProgressBar{background:%1;min-height:%2px;max-height:%2px;border-radius:%3px;text-align:center;border:1px solid %1;color:%4;}").arg(borderColor).arg(barHeight).arg(barRadius).arg(titleTextDarkColor));
    qss.append(QString("QProgressBar:chunk{border-radius:%2px;background-color:%1;}").arg(titleBgColor).arg(barRadius));

    qApp->setPalette(QPalette(mainBgColor));
    qApp->setStyleSheet(qss.join(""));
}

void frmMain::on_btnMenu_Style_clicked()
{
    style->show();
}

void frmMain::on_btnMenu_Min_clicked()
{
    showMinimized();
}

void frmMain::on_btnMenu_Max_clicked()
{
    static bool max = false;
    static QRect location = this->geometry();

    if (max) {
        this->setGeometry(location);
        ui->btnMenu_Max->setToolTip("最大化");
    } else {
        location = this->geometry();
        ui->btnMenu_Max->setToolTip("还原");
        this->setGeometry(QUIHelper::getScreenRect());
    }

    this->setProperty("canMove", max);
    max = !max;
}

void frmMain::on_btnMenu_Close_clicked()
{
    exit(0);
}
