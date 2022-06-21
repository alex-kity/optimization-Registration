#ifndef FRMDEVICECONTROL_H
#define FRMDEVICECONTROL_H

#include <QWidget>

namespace Ui {
class frmDeviceControl;
}

class frmDeviceControl : public QWidget
{
    Q_OBJECT

public:
    static frmDeviceControl *Instance();
    explicit frmDeviceControl(QWidget *parent = 0);
    ~frmDeviceControl();

private:
    Ui::frmDeviceControl *ui;
    static frmDeviceControl *self;
    QString targetName;

private slots:
    void initForm();

private slots:
    void on_btnSub_clicked();
    void on_btnAdd_clicked();
    void on_btnOk_clicked();
    void on_btnCancel_clicked();
    void on_slider_sliderMoved(int position);

signals:
    void setValue(const QString &targetName, int value);

public slots:
    void changeStyle(const QString &color);
    void setRange(int minValue, int maxValue);
    void setCurrentValue(int value);
    void setTargetName(const QString &targetName);
};

#endif // FRMDEVICECONTROL_H
