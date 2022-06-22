/********************************************************************************
** Form generated from reading UI file 'scalarFieldFromColorDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCALARFIELDFROMCOLORDLG_H
#define UI_SCALARFIELDFROMCOLORDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_scalarFieldFromColorDlg
{
public:
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBoxR;
    QCheckBox *checkBoxG;
    QCheckBox *checkBoxB;
    QCheckBox *checkBoxA;
    QCheckBox *checkBoxComposite;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *scalarFieldFromColorDlg)
    {
        if (scalarFieldFromColorDlg->objectName().isEmpty())
            scalarFieldFromColorDlg->setObjectName(QStringLiteral("scalarFieldFromColorDlg"));
        scalarFieldFromColorDlg->resize(259, 260);
        verticalLayout = new QVBoxLayout(scalarFieldFromColorDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        checkBoxR = new QCheckBox(scalarFieldFromColorDlg);
        checkBoxR->setObjectName(QStringLiteral("checkBoxR"));
        checkBoxR->setChecked(true);

        verticalLayout->addWidget(checkBoxR);

        checkBoxG = new QCheckBox(scalarFieldFromColorDlg);
        checkBoxG->setObjectName(QStringLiteral("checkBoxG"));
        checkBoxG->setChecked(true);

        verticalLayout->addWidget(checkBoxG);

        checkBoxB = new QCheckBox(scalarFieldFromColorDlg);
        checkBoxB->setObjectName(QStringLiteral("checkBoxB"));
        checkBoxB->setChecked(true);

        verticalLayout->addWidget(checkBoxB);

        checkBoxA = new QCheckBox(scalarFieldFromColorDlg);
        checkBoxA->setObjectName(QStringLiteral("checkBoxA"));

        verticalLayout->addWidget(checkBoxA);

        checkBoxComposite = new QCheckBox(scalarFieldFromColorDlg);
        checkBoxComposite->setObjectName(QStringLiteral("checkBoxComposite"));
        checkBoxComposite->setChecked(true);

        verticalLayout->addWidget(checkBoxComposite);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(scalarFieldFromColorDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(scalarFieldFromColorDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), scalarFieldFromColorDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), scalarFieldFromColorDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(scalarFieldFromColorDlg);
    } // setupUi

    void retranslateUi(QDialog *scalarFieldFromColorDlg)
    {
        scalarFieldFromColorDlg->setWindowTitle(QApplication::translate("scalarFieldFromColorDlg", "SF from RGB", 0));
        checkBoxR->setText(QApplication::translate("scalarFieldFromColorDlg", "R Channel", 0));
        checkBoxG->setText(QApplication::translate("scalarFieldFromColorDlg", "G Channel", 0));
        checkBoxB->setText(QApplication::translate("scalarFieldFromColorDlg", "B Channel", 0));
        checkBoxA->setText(QApplication::translate("scalarFieldFromColorDlg", "Alpha Channel", 0));
        checkBoxComposite->setText(QApplication::translate("scalarFieldFromColorDlg", "Composite = (R+ G+ B) / 3", 0));
    } // retranslateUi

};

namespace Ui {
    class scalarFieldFromColorDlg: public Ui_scalarFieldFromColorDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCALARFIELDFROMCOLORDLG_H
