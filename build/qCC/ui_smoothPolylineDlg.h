/********************************************************************************
** Form generated from reading UI file 'smoothPolylineDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMOOTHPOLYLINEDLG_H
#define UI_SMOOTHPOLYLINEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SmoothPolylineDialog
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QDoubleSpinBox *ratioDoubleSpinBox;
    QLabel *label_2;
    QSpinBox *iterationSpinBox;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *SmoothPolylineDialog)
    {
        if (SmoothPolylineDialog->objectName().isEmpty())
            SmoothPolylineDialog->setObjectName(QStringLiteral("SmoothPolylineDialog"));
        SmoothPolylineDialog->resize(300, 150);
        formLayout = new QFormLayout(SmoothPolylineDialog);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(SmoothPolylineDialog);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        ratioDoubleSpinBox = new QDoubleSpinBox(SmoothPolylineDialog);
        ratioDoubleSpinBox->setObjectName(QStringLiteral("ratioDoubleSpinBox"));
        ratioDoubleSpinBox->setMinimum(0.01);
        ratioDoubleSpinBox->setMaximum(0.49);
        ratioDoubleSpinBox->setSingleStep(0.01);
        ratioDoubleSpinBox->setValue(0.25);

        formLayout->setWidget(0, QFormLayout::FieldRole, ratioDoubleSpinBox);

        label_2 = new QLabel(SmoothPolylineDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        iterationSpinBox = new QSpinBox(SmoothPolylineDialog);
        iterationSpinBox->setObjectName(QStringLiteral("iterationSpinBox"));
        iterationSpinBox->setMinimum(1);
        iterationSpinBox->setMaximum(10);
        iterationSpinBox->setValue(5);

        formLayout->setWidget(1, QFormLayout::FieldRole, iterationSpinBox);

        buttonBox = new QDialogButtonBox(SmoothPolylineDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(3, QFormLayout::SpanningRole, buttonBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::FieldRole, verticalSpacer);


        retranslateUi(SmoothPolylineDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SmoothPolylineDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SmoothPolylineDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SmoothPolylineDialog);
    } // setupUi

    void retranslateUi(QDialog *SmoothPolylineDialog)
    {
        SmoothPolylineDialog->setWindowTitle(QApplication::translate("SmoothPolylineDialog", "Smooth polyline (Chaikin)", 0));
        label->setText(QApplication::translate("SmoothPolylineDialog", "Ratio (strength)", 0));
        label_2->setText(QApplication::translate("SmoothPolylineDialog", "iterations", 0));
    } // retranslateUi

};

namespace Ui {
    class SmoothPolylineDialog: public Ui_SmoothPolylineDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMOOTHPOLYLINEDLG_H
