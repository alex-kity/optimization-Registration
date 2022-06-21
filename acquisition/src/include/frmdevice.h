#ifndef FRMDEVICE_H
#define FRMDEVICE_H

#include <QWidget>
#include <QGridLayout>
namespace Ui {
class frmDevice;
}

class frmDevice : public QWidget
{
    Q_OBJECT

public:
    explicit frmDevice(QWidget *parent = 0);
    ~frmDevice();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::frmDevice *ui;
    QList<QWidget *> frms;
    QGridLayout * m_GridLayout;

private slots:
    void initForm();
    void initPanel();

signals:
    void changeStyle(const QString &color);
};

#endif // FRMDEVICE_H
