#include "frmconfig.h"
#include "ui_frmconfig.h"
#include "quihelper.h"

frmConfig::frmConfig(QWidget *parent) : QWidget(parent), ui(new Ui::frmConfig)
{
    ui->setupUi(this);
    this->initForm();
}

frmConfig::~frmConfig()
{
    delete ui;
}

void frmConfig::initForm()
{
    this->setFocusPolicy(Qt::StrongFocus);
    ui->switchBeep->setChecked(true);
}

void frmConfig::on_txtMaxX_textChanged(const QString &arg1)
{
    int value = arg1.toInt();
    if (value > 0) {
        emit setMaxX(value);
    }
}

void frmConfig::on_txtMaxY_textChanged(const QString &arg1)
{
    int value = arg1.toInt();
    if (value > 0) {
        emit setMaxY(value);
    }
}
