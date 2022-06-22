/********************************************************************************
** Form generated from reading UI file 'ManagerWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERWIDGET_H
#define UI_MANAGERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManagerWidget
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ManagerWidget)
    {
        if (ManagerWidget->objectName().isEmpty())
            ManagerWidget->setObjectName(QStringLiteral("ManagerWidget"));
        ManagerWidget->resize(800, 600);
        centralwidget = new QWidget(ManagerWidget);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(500, 110, 93, 28));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(180, 120, 113, 21));
        ManagerWidget->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ManagerWidget);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        ManagerWidget->setMenuBar(menubar);
        statusbar = new QStatusBar(ManagerWidget);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ManagerWidget->setStatusBar(statusbar);

        retranslateUi(ManagerWidget);

        QMetaObject::connectSlotsByName(ManagerWidget);
    } // setupUi

    void retranslateUi(QMainWindow *ManagerWidget)
    {
        ManagerWidget->setWindowTitle(QApplication::translate("ManagerWidget", "MainWindow", 0));
        pushButton->setText(QApplication::translate("ManagerWidget", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class ManagerWidget: public Ui_ManagerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERWIDGET_H
