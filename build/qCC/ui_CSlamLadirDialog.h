/********************************************************************************
** Form generated from reading UI file 'CSlamLadirDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSLAMLADIRDIALOG_H
#define UI_CSLAMLADIRDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CSlamLadirDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QPushButton *load_path;
    QPushButton *btn_TestPath;
    QVBoxLayout *verticalLayout;
    QWidget *widget_option;
    QVBoxLayout *verticalLayout_2;
    QPushButton *setpointfile;
    QPushButton *pushButtonpointresi;
    QPushButton *m_btnTransFrom;
    QPushButton *pushButton_resample;
    QPushButton *getcurrentpath;
    QPushButton *pushButton;
    QPushButton *btnAuto;
    QPushButton *cloneBtn;
    QPushButton *SavePath;
    QPushButton *btnclose;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *CSlamLadirDialog)
    {
        if (CSlamLadirDialog->objectName().isEmpty())
            CSlamLadirDialog->setObjectName(QStringLiteral("CSlamLadirDialog"));
        CSlamLadirDialog->resize(148, 400);
        CSlamLadirDialog->setMaximumSize(QSize(16777215, 757));
        CSlamLadirDialog->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(CSlamLadirDialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        load_path = new QPushButton(CSlamLadirDialog);
        load_path->setObjectName(QStringLiteral("load_path"));

        verticalLayout_4->addWidget(load_path);

        btn_TestPath = new QPushButton(CSlamLadirDialog);
        btn_TestPath->setObjectName(QStringLiteral("btn_TestPath"));

        verticalLayout_4->addWidget(btn_TestPath);


        verticalLayout_3->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_option = new QWidget(CSlamLadirDialog);
        widget_option->setObjectName(QStringLiteral("widget_option"));
        widget_option->setMinimumSize(QSize(0, 300));
        verticalLayout_2 = new QVBoxLayout(widget_option);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        setpointfile = new QPushButton(widget_option);
        setpointfile->setObjectName(QStringLiteral("setpointfile"));

        verticalLayout_2->addWidget(setpointfile);

        pushButtonpointresi = new QPushButton(widget_option);
        pushButtonpointresi->setObjectName(QStringLiteral("pushButtonpointresi"));

        verticalLayout_2->addWidget(pushButtonpointresi);

        m_btnTransFrom = new QPushButton(widget_option);
        m_btnTransFrom->setObjectName(QStringLiteral("m_btnTransFrom"));

        verticalLayout_2->addWidget(m_btnTransFrom);

        pushButton_resample = new QPushButton(widget_option);
        pushButton_resample->setObjectName(QStringLiteral("pushButton_resample"));

        verticalLayout_2->addWidget(pushButton_resample);

        getcurrentpath = new QPushButton(widget_option);
        getcurrentpath->setObjectName(QStringLiteral("getcurrentpath"));

        verticalLayout_2->addWidget(getcurrentpath);

        pushButton = new QPushButton(widget_option);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        btnAuto = new QPushButton(widget_option);
        btnAuto->setObjectName(QStringLiteral("btnAuto"));

        verticalLayout_2->addWidget(btnAuto);

        cloneBtn = new QPushButton(widget_option);
        cloneBtn->setObjectName(QStringLiteral("cloneBtn"));

        verticalLayout_2->addWidget(cloneBtn);

        SavePath = new QPushButton(widget_option);
        SavePath->setObjectName(QStringLiteral("SavePath"));

        verticalLayout_2->addWidget(SavePath);

        btnclose = new QPushButton(widget_option);
        btnclose->setObjectName(QStringLiteral("btnclose"));

        verticalLayout_2->addWidget(btnclose);


        verticalLayout->addWidget(widget_option);


        verticalLayout_3->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        retranslateUi(CSlamLadirDialog);

        QMetaObject::connectSlotsByName(CSlamLadirDialog);
    } // setupUi

    void retranslateUi(QDialog *CSlamLadirDialog)
    {
        CSlamLadirDialog->setWindowTitle(QApplication::translate("CSlamLadirDialog", "Dialog", 0));
        load_path->setText(QApplication::translate("CSlamLadirDialog", "\345\212\240\350\275\275\350\275\250\350\277\271", 0));
        btn_TestPath->setText(QApplication::translate("CSlamLadirDialog", "\345\212\240\350\275\275\350\276\205\345\212\251\350\275\250\350\277\271", 0));
        setpointfile->setText(QApplication::translate("CSlamLadirDialog", "\350\256\276\347\275\256\347\202\271\344\272\221\350\267\257\345\276\204", 0));
        pushButtonpointresi->setText(QApplication::translate("CSlamLadirDialog", "\345\205\263\351\224\256\347\202\271\351\205\215\345\207\206", 0));
        m_btnTransFrom->setText(QApplication::translate("CSlamLadirDialog", "\345\212\250\346\200\201\345\217\230\346\215\242\351\205\215\345\207\206", 0));
        pushButton_resample->setText(QApplication::translate("CSlamLadirDialog", "\351\207\207\346\240\267", 0));
        getcurrentpath->setText(QApplication::translate("CSlamLadirDialog", "\350\216\267\345\217\226\345\275\223\345\211\215\345\270\247\346\225\260\346\215\256", 0));
        pushButton->setText(QApplication::translate("CSlamLadirDialog", "\346\211\213\345\212\250\350\256\276\347\275\256\345\217\230\346\215\242\344\270\255\345\277\203", 0));
        btnAuto->setText(QApplication::translate("CSlamLadirDialog", "\350\207\252\345\212\250\345\257\273\346\211\276\346\227\213\350\275\254\344\270\255\345\277\203", 0));
        cloneBtn->setText(QApplication::translate("CSlamLadirDialog", "\345\205\213\351\232\206", 0));
        SavePath->setText(QApplication::translate("CSlamLadirDialog", "\344\277\235\345\255\230", 0));
        btnclose->setText(QApplication::translate("CSlamLadirDialog", "\345\205\263\351\227\255", 0));
    } // retranslateUi

};

namespace Ui {
    class CSlamLadirDialog: public Ui_CSlamLadirDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSLAMLADIRDIALOG_H
