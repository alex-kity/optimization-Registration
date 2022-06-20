#ifndef FRMCONFIG_H
#define FRMCONFIG_H

#include <QWidget>

namespace Ui {
class frmConfig;
}

class frmConfig : public QWidget
{
    Q_OBJECT

public:
    explicit frmConfig(QWidget *parent = 0);
    ~frmConfig();

private:
    Ui::frmConfig *ui;

private slots:
    void initForm();

private slots:
    void on_txtMaxX_textChanged(const QString &arg1);
    void on_txtMaxY_textChanged(const QString &arg1);

signals:
    void setMaxX(int maxX);
    void setMaxY(int maxY);

};

#endif // FRMCONFIG_H
