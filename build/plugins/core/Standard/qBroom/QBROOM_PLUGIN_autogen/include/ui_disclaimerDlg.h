/********************************************************************************
** Form generated from reading UI file 'disclaimerDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISCLAIMERDLG_H
#define UI_DISCLAIMERDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DisclaimerDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *logoLabel;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DisclaimerDialog)
    {
        if (DisclaimerDialog->objectName().isEmpty())
            DisclaimerDialog->setObjectName(QStringLiteral("DisclaimerDialog"));
        DisclaimerDialog->resize(500, 380);
        QIcon icon;
        icon.addFile(QStringLiteral(":/CC/plugin/qBroom/images/qBroom.png"), QSize(), QIcon::Normal, QIcon::Off);
        DisclaimerDialog->setWindowIcon(icon);
        DisclaimerDialog->setStyleSheet(QStringLiteral("background-color: white"));
        verticalLayout = new QVBoxLayout(DisclaimerDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        logoLabel = new QLabel(DisclaimerDialog);
        logoLabel->setObjectName(QStringLiteral("logoLabel"));
        logoLabel->setPixmap(QPixmap(QString::fromUtf8(":/CC/plugin/qBroom/images/cea_logo.jpg")));
        logoLabel->setAlignment(Qt::AlignCenter);
        logoLabel->setOpenExternalLinks(true);

        verticalLayout->addWidget(logoLabel);

        label = new QLabel(DisclaimerDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setOpenExternalLinks(true);

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(DisclaimerDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DisclaimerDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DisclaimerDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DisclaimerDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DisclaimerDialog);
    } // setupUi

    void retranslateUi(QDialog *DisclaimerDialog)
    {
        DisclaimerDialog->setWindowTitle(QApplication::translate("DisclaimerDialog", "qBroom (disclaimer)", 0));
        label->setText(QApplication::translate("DisclaimerDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\">\n"
"This plugin is kindly provided by Wesley Grimes,\n"
"<br/>\n"
"Collision Engineering Associates, Inc.\n"
"<br/>\n"
"<a href=\"https://cea-az.com/\">https://cea-az.com/</a>\n"
"</p>\n"
"<p align=\"center\">\n"
"<b>Please donate if you find this tool useful</b>\n"
"<br/>\n"
"<br/>\n"
"<a href=\"https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&amp;hosted_button_id=DZAYQVLL8MMNL\"><img src=\":/CC/plugin/qBroom/btn_donateCC_LG.gif\" /></a>\n"
"</p>\n"
"<p align=\"center\" style=\"font-size:8pt;\">This program is distributed in the hope that it will be useful,\n"
"<br/>but WITHOUT ANY WARRANTY; without even the implied warranty of <br/>MERCHANTABILITY o"
                        "r FITNESS FOR A PARTICULAR PURPOSE.\n"
"<br/>See the GNU General Public License for more details.</p>\n"
"</body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class DisclaimerDialog: public Ui_DisclaimerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISCLAIMERDLG_H
