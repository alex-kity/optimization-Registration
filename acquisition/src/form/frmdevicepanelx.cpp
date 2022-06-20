#include "frmdevicepanelx.h"
#include "ui_frmdevicepanelx.h"
#include "quihelper.h"
#include "frmdevicecontrol.h"

#ifndef __arm
#define flick true
#else
#define flick false
#endif

frmDevicePanelX::frmDevicePanelX(QWidget *parent) : QWidget(parent), ui(new Ui::frmDevicePanelX)
{
    ui->setupUi(this);
    this->initForm();
    this->changeStyle("#159C77");
    this->setChecked(false);
}

frmDevicePanelX::~frmDevicePanelX()
{
    delete ui;
}

void frmDevicePanelX::initForm()
{
    ui->barVoltage->setRange(0, 250);
    ui->barTemp->setRange(0, 200);
    ui->barVoltage->setValue(200);
    ui->barTemp->setValue(150);

    ui->lcdVoltage->display("150");
    ui->lcdTemp->display("90");

    QFont font;
    font.setPixelSize(15);
    ui->switchEn->setFont(font);
    ui->switchEn->setChecked(true);
    ui->switchEn->setAnimation(flick);

    font.setBold(true);
    font.setPixelSize(20);
    ui->labVoltage->setFont(font);
    ui->labTemp->setFont(font);

    timer = new QTimer(this);
    timer->setInterval(500);
    connect(timer, SIGNAL(timeout()), this, SLOT(changeBg()));

    //最后的操作时间,如果操作了直接更新该时间即可
    lastTime = QDateTime::currentDateTime();

    //绑定开关变动
    connect(ui->switchEn, SIGNAL(checkedChanged(bool)), this, SLOT(checkedChanged(bool)));

    //绑定滑块改动值
    connect(frmDeviceControl::Instance(), SIGNAL(setValue(QString, int)), this, SLOT(setValue(QString, int)));
}

void frmDevicePanelX::changeBg()
{
    if (flick) {
        static bool isDark = false;

        if (isDark) {
            ui->labName->setStyleSheet("QLabel{border:2px solid #E1E1E2;}");
            ui->widgetMain->setStyleSheet("QWidget#widgetMain{border-style:solid;border-color:#E1E1E2;border-width:0px 2px 2px 2px;}");
        } else {
            ui->labName->setStyleSheet(QString("QLabel{border:2px solid %1;background:%1;color:#FFFFFF;}").arg(color));
            ui->widgetMain->setStyleSheet(QString("QWidget#widgetMain{border-style:solid;border-color:%1;border-width:0px 2px 2px 2px;}").arg(color));
        }

        isDark = !isDark;

        //判断最后一次操作时间,是否超过规定时间,超过则自动停止
        QDateTime now = QDateTime::currentDateTime();
        if (lastTime.secsTo(now) > 5) {
            setChecked(false);
        }
    } else {
        setChecked(false);
    }
}

void frmDevicePanelX::on_btnSetValue_clicked()
{
    //根据不同模式设置弹出窗体的滑块值和当前设定值
    if (ui->btnMode->text() == "温度模式") {
        frmDeviceControl::Instance()->setRange(ui->barTemp->minimum(), ui->barTemp->maximum());
        frmDeviceControl::Instance()->setCurrentValue(ui->barTemp->value());
    } else {
        frmDeviceControl::Instance()->setRange(ui->barVoltage->minimum(), ui->barVoltage->maximum());
        frmDeviceControl::Instance()->setCurrentValue(ui->barVoltage->value());
    }

    frmDeviceControl::Instance()->setTargetName(this->objectName());
    frmDeviceControl::Instance()->show();
}

void frmDevicePanelX::on_btnMode_clicked()
{
    if (ui->btnMode->text() == "电压模式") {
        ui->btnMode->setText("温度模式");
    } else {
        ui->btnMode->setText("电压模式");
    }
}

void frmDevicePanelX::changeStyle(const QString &color)
{
    this->color = color;

    QString qss = QString("QLCDNumber{background:#000000;color:%1;}").arg(color);
    ui->lcdTemp->setStyleSheet(qss);
    ui->lcdVoltage->setStyleSheet(qss);
}

void frmDevicePanelX::setName(const QString &name)
{
    this->name = name;
    ui->labName->setText(name);
}

void frmDevicePanelX::setChecked(bool checked)
{
    lastTime = QDateTime::currentDateTime();

    if (checked) {
        if (flick) {
            timer->start();
        } else {
            QTimer::singleShot(5000, this, SLOT(changeBg()));
        }

        ui->labName->setStyleSheet(QString("QLabel{border:2px solid %1;background:%1;color:#FFFFFF;}").arg(color));
        ui->widgetMain->setStyleSheet(QString("QWidget#widgetMain{border-style:solid;border-color:%1;border-width:0px 2px 2px 2px;}").arg(color));
    } else {
        if (flick) {
            timer->stop();
        }

        ui->labName->setStyleSheet("QLabel{border:1px solid #E1E1E2;}");
        ui->widgetMain->setStyleSheet("QWidget#widgetMain{border-style:solid;border-color:#E1E1E2;border-width:0px 1px 1px 1px;}");
    }
}

void frmDevicePanelX::checkedChanged(bool checked)
{
    //qDebug() << objectName() << checked;
}

void frmDevicePanelX::setValue(const QString &targetName, int value)
{
    //如果不是发给当前窗体则返回
    if (this->objectName() != targetName) {
        return;
    }

    if (ui->btnMode->text() == "电压模式") {
        ui->barVoltage->setValue(value);
        ui->labVoltageValue->setText(QString("设定值: %1V").arg(value));
    } else {
        ui->barTemp->setValue(value);
        ui->labTempValue->setText(QString("设定值: %1℃").arg(value));
    }
}
