#include "frmdevicecontrol.h"
#include "ui_frmdevicecontrol.h"
#include "quihelper.h"
#include "iconhelper.h"

frmDeviceControl *frmDeviceControl::self = 0;
frmDeviceControl *frmDeviceControl::Instance()
{
    if (!self) {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if (!self) {
            self = new frmDeviceControl;
        }
    }

    return self;
}

frmDeviceControl::frmDeviceControl(QWidget *parent) : QWidget(parent), ui(new Ui::frmDeviceControl)
{
    ui->setupUi(this);
    this->initForm();
    this->changeStyle("#159C77");
    this->setCurrentValue(50);
    QUIHelper::setFormInCenter(this);
}

frmDeviceControl::~frmDeviceControl()
{
    delete ui;
}

void frmDeviceControl::initForm()
{
    this->setWindowOpacity(1.0);
    this->setProperty("form", true);
    this->setProperty("canMove", true);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

    QFont font = this->font();
    font.setBold(true);

    font.setPixelSize(20);
    ui->btnOk->setFont(font);
    ui->btnCancel->setFont(font);

    font.setPixelSize(35);
    ui->btnAdd->setFont(font);
    ui->btnSub->setFont(font);
    ui->labValue->setFont(font);

    int iconSize = 20;
    int iconWidth = 35;
    int iconHeight = 25;

    QPixmap pixAdd = IconHelper::getPixmap("#FFFFFF", 0xf067, iconSize, iconWidth, iconHeight);
    ui->btnAdd->setIcon(QIcon(pixAdd));
    ui->btnAdd->setIconSize(QSize(iconWidth, iconHeight));

    QPixmap pixSub = IconHelper::getPixmap("#FFFFFF", 0xf068, iconSize, iconWidth, iconHeight);
    ui->btnSub->setIcon(QIcon(pixSub));
    ui->btnSub->setIconSize(QSize(iconWidth, iconHeight));
}

void frmDeviceControl::on_btnSub_clicked()
{
    int value = ui->slider->value();
    if (value > ui->slider->minimum()) {
        setCurrentValue(value - 1);
    }
}

void frmDeviceControl::on_btnAdd_clicked()
{
    int value = ui->slider->value();
    if (value < ui->slider->maximum()) {
        setCurrentValue(value + 1);
    }
}

void frmDeviceControl::on_btnOk_clicked()
{
    emit setValue(targetName, ui->slider->value());
    close();
}

void frmDeviceControl::on_btnCancel_clicked()
{
    close();
}

void frmDeviceControl::changeStyle(const QString &color)
{
    QStringList qss;

    int sliderHeight = 20;
    int handleSize = 40;
    int sliderBorder = 0;
    QString navBtnBgColor = "#EAEAEA";
    QString borderColor = "#E1E1E2";

    qss.append(QString("QSlider::groove:horizontal{background:%1;height:%2px;border-radius:%3px;}").arg(navBtnBgColor).arg(sliderHeight).arg(sliderHeight / 2));
    qss.append(QString("QSlider::add-page:horizontal{background:%1;height:%2px;border-radius:%3px;}").arg(navBtnBgColor).arg(sliderHeight).arg(sliderHeight / 2));
    qss.append(QString("QSlider::sub-page:horizontal{background:%1;height:%2px;border-radius:%3px;}").arg(color).arg(sliderHeight).arg(sliderHeight / 2));
    qss.append(QString("QSlider::handle:horizontal{width:%1px;margin-top:-%2px;margin-bottom:-%2px;border-radius:%3px;border:%4px solid %5;")
               .arg(handleSize - sliderBorder).arg(handleSize / 4 + sliderBorder).arg(handleSize / 2).arg(sliderBorder).arg(borderColor));
    qss.append(QString("background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.3,fx:0.5,fy:0.5,stop:0.3 #FFFFFF,stop:0.8 %1);}").arg(color));

    ui->slider->setStyleSheet(qss.join(""));
}

void frmDeviceControl::setRange(int minValue, int maxValue)
{
    ui->slider->setRange(minValue, maxValue);
}

void frmDeviceControl::setCurrentValue(int value)
{
    ui->slider->setValue(value);
    on_slider_sliderMoved(value);
}

void frmDeviceControl::setTargetName(const QString &targetName)
{
    this->targetName = targetName;
}

void frmDeviceControl::on_slider_sliderMoved(int position)
{
    ui->labValue->setText(QString("当前值: %1").arg(position));
}
