#ifndef CSENSORDATA_H
#define CSENSORDATA_H

#include <QWidget>
#include <QDateTime>
namespace Ui {
class CSensorData;
}

class CSensorData : public QWidget
{
    Q_OBJECT

public:
    explicit CSensorData(QWidget *parent = nullptr);
    ~CSensorData();

private:
    Ui::CSensorData *ui;

private:
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

#endif // CSENSORDATA_H
