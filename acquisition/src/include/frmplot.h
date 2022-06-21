#ifndef FRMPLOT_H
#define FRMPLOT_H

#include <QMainWindow>

namespace Ui {
class frmplot;
}

class frmplot : public QMainWindow
{
    Q_OBJECT

public:
    explicit frmplot(QWidget *parent = nullptr);
    ~frmplot();

protected:
    bool eventFilter(QObject *watched, QEvent *event);
private:
    Ui::frmplot *ui;
};

#endif // FRMPLOT_H
