#ifndef FRMDEVICEPANELX_H
#define FRMDEVICEPANELX_H

#include <QWidget>
#include <QDateTime>

namespace Ui {
class frmDevicePanelX;
}

class frmDevicePanelX : public QWidget
{
    Q_OBJECT

public:
    explicit frmDevicePanelX(QWidget *parent = 0);
    ~frmDevicePanelX();

private:
    Ui::frmDevicePanelX *ui;
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

#endif // FRMDEVICEPANELX_H
