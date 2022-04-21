#ifndef MANAGERWIDGET_H
#define MANAGERWIDGET_H

#include <QMainWindow>
#include "SgsTagging.h"
namespace Ui {
class ManagerWidget;
}

class ManagerWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManagerWidget(QWidget *parent = nullptr);
    ~ManagerWidget();

private:
    Ui::ManagerWidget *ui;
//    SgsTagging *m_SgsTagging;
};

#endif // MANAGERWIDGET_H



