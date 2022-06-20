#include "frmdevice.h"
#include "ui_frmdevice.h"
#include "quihelper.h"
#include "frmdevicepanel.h"
#include "frmdevicepanelx.h"
#include "CSensorData.h"
#define frmdevicepanel

frmDevice::frmDevice(QWidget *parent) : QWidget(parent), ui(new Ui::frmDevice)
{
    ui->setupUi(this);
    this->initForm();
    QTimer::singleShot(100, this, SLOT(initPanel()));
}

frmDevice::~frmDevice()
{
    delete ui;
}

bool frmDevice::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QString objName = watched->objectName();
        if (objName.startsWith("frmDevicePanel")) {
            int index = objName.right(1).toInt();

            //将当前按下的窗体高亮
            for (int i = 0; i < frms.count(); i++) {
#ifdef frmdevicepanel
                frmDevicePanel *frm = (frmDevicePanel *)frms.at(i);
#else
                frmDevicePanelX *frm = (frmDevicePanelX *)frms.at(i);
#endif
                frm->setChecked(i == index);
            }
        }
    }

    return QWidget::eventFilter(watched, event);
}

void frmDevice::initForm()
{

}

void frmDevice::initPanel()
{
    qDeleteAll(frms);
    frms.clear();

    QStringList names;
    names << "雷达" << "相机" << "轮速计" << "IMU" << "GPS" << "通道C2";

    for (int i = 0; i <2 ; i++) {
#ifdef frmdevicepanel
        frmDevicePanel *frm = new frmDevicePanel;
#else
        frmDevicePanelX *frm = new frmDevicePanelX;
#endif
        frm->setObjectName("frmDevicePanel" + QString::number(i));
        frm->installEventFilter(this);
        connect(this, SIGNAL(changeStyle(QString)), frm, SLOT(changeStyle(QString)));
        frm->setName(names.at(i));
        frms.append(frm);
        ui->gridLayout_op->addWidget(frm);
    }

    for (int i = 2; i <6 ; i++) {
#ifdef frmdevicepanel
        CSensorData *frm = new CSensorData;
#else
        frmDevicePanelX *frm = new frmDevicePanelX;
#endif
        frm->setObjectName("frmDevicePanel" + QString::number(i));
        frm->installEventFilter(this);
        connect(this, SIGNAL(changeStyle(QString)), frm, SLOT(changeStyle(QString)));
        frm->setName(names.at(i));
        frms.append(frm);
        ui->gridLayout_op->addWidget(frm);

    }

    ui->gridLayout_op->addWidget(frms[0],0,1);
    ui->gridLayout_op->addWidget(frms[1],0,2);
    ui->gridLayout_op->addWidget(frms[2],0,3);
    ui->gridLayout_op->addWidget(frms[3],1,1);
    ui->gridLayout_op->addWidget(frms[4],1,2);
    ui->gridLayout_op->addWidget(frms[5],1,3);

}
