#ifndef FRMDEVICEPANEL_H
#define FRMDEVICEPANEL_H

#include <QWidget>
#include <QDateTime>

namespace Ui {
class frmDevicePanel;
}

class frmDevicePanel : public QWidget
{
    Q_OBJECT

public:
    explicit frmDevicePanel(QWidget *parent = 0);
    ~frmDevicePanel();

private:
    Ui::frmDevicePanel *ui;
    QString name;
    QString color;
    QTimer *timer;
    QDateTime lastTime;

private slots:
    void initForm();
    void changeBg();

private slots:
    void on_btnSetValue_clicked();
    void on_btnMode_clicked();

public slots:
    void changeStyle(const QString &color);
    void setName(const QString &name);
    void setChecked(bool checked);
    void checkedChanged(bool checked);
    void setValue(const QString &targetName, int value);
};

#endif // FRMDEVICEPANEL_H
