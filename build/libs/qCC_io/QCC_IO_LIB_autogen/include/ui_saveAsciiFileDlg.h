/********************************************************************************
** Form generated from reading UI file 'saveAsciiFileDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEASCIIFILEDLG_H
#define UI_SAVEASCIIFILEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AsciiSaveDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *coordsPrecisionSpinBox;
    QLabel *label_2;
    QSpinBox *sfPrecisionSpinBox;
    QLabel *label_3;
    QComboBox *separatorComboBox;
    QLabel *label_4;
    QComboBox *orderComboBox;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *columnsHeaderCheckBox;
    QCheckBox *pointCountHeaderCheckBox;
    QGroupBox *colorOptionsGroupBox;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *saveFloatColorsCheckBox;
    QCheckBox *saveAlphaChannelCheckBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AsciiSaveDialog)
    {
        if (AsciiSaveDialog->objectName().isEmpty())
            AsciiSaveDialog->setObjectName(QStringLiteral("AsciiSaveDialog"));
        AsciiSaveDialog->resize(454, 450);
        verticalLayout_2 = new QVBoxLayout(AsciiSaveDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(AsciiSaveDialog);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        coordsPrecisionSpinBox = new QSpinBox(AsciiSaveDialog);
        coordsPrecisionSpinBox->setObjectName(QStringLiteral("coordsPrecisionSpinBox"));
        coordsPrecisionSpinBox->setMaximum(16);
        coordsPrecisionSpinBox->setValue(8);

        formLayout->setWidget(0, QFormLayout::FieldRole, coordsPrecisionSpinBox);

        label_2 = new QLabel(AsciiSaveDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        sfPrecisionSpinBox = new QSpinBox(AsciiSaveDialog);
        sfPrecisionSpinBox->setObjectName(QStringLiteral("sfPrecisionSpinBox"));
        sfPrecisionSpinBox->setMaximum(12);
        sfPrecisionSpinBox->setValue(6);

        formLayout->setWidget(1, QFormLayout::FieldRole, sfPrecisionSpinBox);

        label_3 = new QLabel(AsciiSaveDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        separatorComboBox = new QComboBox(AsciiSaveDialog);
        separatorComboBox->setObjectName(QStringLiteral("separatorComboBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, separatorComboBox);

        label_4 = new QLabel(AsciiSaveDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        orderComboBox = new QComboBox(AsciiSaveDialog);
        orderComboBox->setObjectName(QStringLiteral("orderComboBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, orderComboBox);


        verticalLayout_2->addLayout(formLayout);

        groupBox = new QGroupBox(AsciiSaveDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        columnsHeaderCheckBox = new QCheckBox(groupBox);
        columnsHeaderCheckBox->setObjectName(QStringLiteral("columnsHeaderCheckBox"));

        verticalLayout->addWidget(columnsHeaderCheckBox);

        pointCountHeaderCheckBox = new QCheckBox(groupBox);
        pointCountHeaderCheckBox->setObjectName(QStringLiteral("pointCountHeaderCheckBox"));

        verticalLayout->addWidget(pointCountHeaderCheckBox);


        verticalLayout_2->addWidget(groupBox);

        colorOptionsGroupBox = new QGroupBox(AsciiSaveDialog);
        colorOptionsGroupBox->setObjectName(QStringLiteral("colorOptionsGroupBox"));
        verticalLayout_3 = new QVBoxLayout(colorOptionsGroupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        saveFloatColorsCheckBox = new QCheckBox(colorOptionsGroupBox);
        saveFloatColorsCheckBox->setObjectName(QStringLiteral("saveFloatColorsCheckBox"));

        verticalLayout_3->addWidget(saveFloatColorsCheckBox);

        saveAlphaChannelCheckBox = new QCheckBox(colorOptionsGroupBox);
        saveAlphaChannelCheckBox->setObjectName(QStringLiteral("saveAlphaChannelCheckBox"));

        verticalLayout_3->addWidget(saveAlphaChannelCheckBox);


        verticalLayout_2->addWidget(colorOptionsGroupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(AsciiSaveDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(AsciiSaveDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AsciiSaveDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AsciiSaveDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AsciiSaveDialog);
    } // setupUi

    void retranslateUi(QDialog *AsciiSaveDialog)
    {
        AsciiSaveDialog->setWindowTitle(QApplication::translate("AsciiSaveDialog", "Save ASCII file", 0));
        label->setText(QApplication::translate("AsciiSaveDialog", "coordinates precision", 0));
        label_2->setText(QApplication::translate("AsciiSaveDialog", "scalar precision", 0));
        label_3->setText(QApplication::translate("AsciiSaveDialog", "separator", 0));
        separatorComboBox->clear();
        separatorComboBox->insertItems(0, QStringList()
         << QApplication::translate("AsciiSaveDialog", "space", 0)
         << QApplication::translate("AsciiSaveDialog", "semicolon", 0)
         << QApplication::translate("AsciiSaveDialog", "comma", 0)
         << QApplication::translate("AsciiSaveDialog", "tab", 0)
        );
        label_4->setText(QApplication::translate("AsciiSaveDialog", "order", 0));
        orderComboBox->clear();
        orderComboBox->insertItems(0, QStringList()
         << QApplication::translate("AsciiSaveDialog", "[ASC] point, color, SF(s), normal", 0)
         << QApplication::translate("AsciiSaveDialog", "[PTS] point, SF(s), color, normal", 0)
        );
        groupBox->setTitle(QApplication::translate("AsciiSaveDialog", "Header", 0));
        columnsHeaderCheckBox->setText(QApplication::translate("AsciiSaveDialog", "columns title", 0));
        pointCountHeaderCheckBox->setText(QApplication::translate("AsciiSaveDialog", "number of points (separate line)", 0));
        colorOptionsGroupBox->setTitle(QApplication::translate("AsciiSaveDialog", "Colors", 0));
#ifndef QT_NO_TOOLTIP
        saveFloatColorsCheckBox->setToolTip(QApplication::translate("AsciiSaveDialog", "Save RGB color components as floats values between 0 and 1", 0));
#endif // QT_NO_TOOLTIP
        saveFloatColorsCheckBox->setText(QApplication::translate("AsciiSaveDialog", "Save colors as float values (0-1)", 0));
#ifndef QT_NO_TOOLTIP
        saveAlphaChannelCheckBox->setToolTip(QApplication::translate("AsciiSaveDialog", "Save RGB color components as floats values between 0 and 1", 0));
#endif // QT_NO_TOOLTIP
        saveAlphaChannelCheckBox->setText(QApplication::translate("AsciiSaveDialog", "Save alpha channel", 0));
    } // retranslateUi

};

namespace Ui {
    class AsciiSaveDialog: public Ui_AsciiSaveDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEASCIIFILEDLG_H
