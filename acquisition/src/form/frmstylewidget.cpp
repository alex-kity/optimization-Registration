#include "frmstylewidget.h"
#include "ui_frmstylewidget.h"
#include "quihelper.h"
#include "iconhelper.h"
#include "stylewidget.h"

frmStyleWidget::frmStyleWidget(QWidget *parent) : QWidget(parent), ui(new Ui::frmStyleWidget)
{
    ui->setupUi(this);
    this->initForm();
    QUIHelper::setFormInCenter(this);
}

frmStyleWidget::~frmStyleWidget()
{
    delete ui;
}

void frmStyleWidget::initForm()
{    
    this->setProperty("form", true);
    this->setProperty("canMove", true);
    this->setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

    IconHelper::setIcon(ui->labIco, 0xf0f4, 25);
    IconHelper::setIcon(ui->btnMenu_Close, 0xf00d, 15);
    connect(ui->btnMenu_Close, SIGNAL(pressed()), this, SLOT(close()));

    ui->labTitle->setText("选择皮肤");

    QStringList colors;
    colors << "#26282C" << "#C62F2F" << "#F759C1" << "#2980B9" << "#159C77";
    colors << "#8E44AD" << "#4BACF8" << "#2C3E50" << "#717FF9" << "#D35400";
    colors << "#2BB669" << "#E8774D" << "#00A2AC" << "#16A085" << "#34495E";

    widgets << ui->widget1 << ui->widget2 << ui->widget3 << ui->widget4 << ui->widget5;
    widgets << ui->widget6 << ui->widget7 << ui->widget8 << ui->widget9 << ui->widget10;
    widgets << ui->widget11 << ui->widget12 << ui->widget13 << ui->widget14 << ui->widget15;

    for (int i = 0; i < widgets.count(); i++) {
        widgets.at(i)->setBgColor(colors.at(i));
        connect(widgets.at(i), SIGNAL(selected(QColor)), this, SLOT(selected(QColor)));
    }

    connect(ui->sliderRed, SIGNAL(sliderMoved(int)), this, SLOT(sliderReleased()));
    connect(ui->sliderGreen, SIGNAL(sliderMoved(int)), this, SLOT(sliderReleased()));
    connect(ui->sliderBlue, SIGNAL(sliderMoved(int)), this, SLOT(sliderReleased()));

    ui->widget1->setChecked(true);
    ui->widget0->setHovered(true);
}

void frmStyleWidget::selected(const QColor &color)
{
    StyleWidget *w = (StyleWidget *)sender();
    
    foreach (StyleWidget *widget, widgets) {
        if (widget != w) {
            widget->setChecked(false);
        }
    }

    ui->sliderRed->setValue(color.red());
    ui->sliderGreen->setValue(color.green());
    ui->sliderBlue->setValue(color.blue());

    ui->labValue->setText(color.name().toUpper());
    ui->widget0->setBgColor(color);
    ui->widget0->setChecked(false);

    emit changeStyle(color.name());
}

void frmStyleWidget::sliderReleased()
{    
    foreach (StyleWidget *widget, widgets) {
        widget->setChecked(false);
    }

    int red = ui->sliderRed->value();
    int green = ui->sliderGreen->value();
    int blue = ui->sliderBlue->value();

    QColor color(red, green, blue);
    ui->labValue->setText(color.name().toUpper());
    ui->widget0->setBgColor(color);
    ui->widget0->setChecked(true);

    emit changeStyle(color.name());
}

void frmStyleWidget::setCurrentStyle(int index)
{
    widgets.at(index)->setChecked(true);
}
