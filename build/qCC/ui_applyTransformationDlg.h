/********************************************************************************
** Form generated from reading UI file 'applyTransformationDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLYTRANSFORMATIONDLG_H
#define UI_APPLYTRANSFORMATIONDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ApplyTransformationDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QToolButton *fromFileToolButton;
    QToolButton *fromClipboardToolButton;
    QToolButton *fromDipDipDirToolButton;
    QToolButton *helpToolButton;
    QPlainTextEdit *helpTextEdit;
    QPlainTextEdit *matrixTextEdit;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *rotAxisGroupBox;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *rxAxisDoubleSpinBox;
    QDoubleSpinBox *ryAxisDoubleSpinBox;
    QDoubleSpinBox *rzAxisDoubleSpinBox;
    QGroupBox *rotAngleGroupBox;
    QHBoxLayout *horizontalLayout_3;
    QDoubleSpinBox *rAngleDoubleSpinBox;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *transGroupBox;
    QHBoxLayout *horizontalLayout_4;
    QDoubleSpinBox *txAxisDoubleSpinBox;
    QDoubleSpinBox *tyAxisDoubleSpinBox;
    QDoubleSpinBox *tzAxisDoubleSpinBox;
    QSpacerItem *verticalSpacer;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *eulerAnglesGroupBox;
    QHBoxLayout *horizontalLayout_6;
    QDoubleSpinBox *ePhiDoubleSpinBox;
    QDoubleSpinBox *eThetaDoubleSpinBox;
    QDoubleSpinBox *ePsiDoubleSpinBox;
    QGroupBox *eulerTransGroupBox;
    QHBoxLayout *horizontalLayout_5;
    QDoubleSpinBox *etxAxisDoubleSpinBox;
    QDoubleSpinBox *etyAxisDoubleSpinBox;
    QDoubleSpinBox *etzAxisDoubleSpinBox;
    QSpacerItem *verticalSpacer_2;
    QCheckBox *inverseCheckBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ApplyTransformationDialog)
    {
        if (ApplyTransformationDialog->objectName().isEmpty())
            ApplyTransformationDialog->setObjectName(QStringLiteral("ApplyTransformationDialog"));
        ApplyTransformationDialog->resize(687, 415);
        verticalLayout_4 = new QVBoxLayout(ApplyTransformationDialog);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        tabWidget = new QTabWidget(ApplyTransformationDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        fromFileToolButton = new QToolButton(tab);
        fromFileToolButton->setObjectName(QStringLiteral("fromFileToolButton"));

        horizontalLayout->addWidget(fromFileToolButton);

        fromClipboardToolButton = new QToolButton(tab);
        fromClipboardToolButton->setObjectName(QStringLiteral("fromClipboardToolButton"));

        horizontalLayout->addWidget(fromClipboardToolButton);

        fromDipDipDirToolButton = new QToolButton(tab);
        fromDipDipDirToolButton->setObjectName(QStringLiteral("fromDipDipDirToolButton"));

        horizontalLayout->addWidget(fromDipDipDirToolButton);

        helpToolButton = new QToolButton(tab);
        helpToolButton->setObjectName(QStringLiteral("helpToolButton"));
        helpToolButton->setCheckable(true);

        horizontalLayout->addWidget(helpToolButton);


        verticalLayout->addLayout(horizontalLayout);

        helpTextEdit = new QPlainTextEdit(tab);
        helpTextEdit->setObjectName(QStringLiteral("helpTextEdit"));
        helpTextEdit->setMinimumSize(QSize(0, 150));
        helpTextEdit->setMaximumSize(QSize(16777215, 150));
        QPalette palette;
        QBrush brush(QColor(202, 202, 202, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(212, 208, 200, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        helpTextEdit->setPalette(palette);
        helpTextEdit->setReadOnly(true);

        verticalLayout->addWidget(helpTextEdit);

        matrixTextEdit = new QPlainTextEdit(tab);
        matrixTextEdit->setObjectName(QStringLiteral("matrixTextEdit"));
        matrixTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
        matrixTextEdit->setPlainText(QLatin1String("1.000000	0.000000	0.000000	0.000000\n"
"0.000000	1.000000	0.000000	0.000000\n"
"0.000000	0.000000	1.000000	0.000000\n"
"0.000000	0.000000	0.000000	1.000000"));

        verticalLayout->addWidget(matrixTextEdit);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        rotAxisGroupBox = new QGroupBox(tab_2);
        rotAxisGroupBox->setObjectName(QStringLiteral("rotAxisGroupBox"));
        rotAxisGroupBox->setFlat(true);
        horizontalLayout_2 = new QHBoxLayout(rotAxisGroupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, -1, 0, -1);
        rxAxisDoubleSpinBox = new QDoubleSpinBox(rotAxisGroupBox);
        rxAxisDoubleSpinBox->setObjectName(QStringLiteral("rxAxisDoubleSpinBox"));
        rxAxisDoubleSpinBox->setPrefix(QStringLiteral("X: "));
        rxAxisDoubleSpinBox->setDecimals(8);
        rxAxisDoubleSpinBox->setMinimum(-1e+09);
        rxAxisDoubleSpinBox->setMaximum(1e+09);

        horizontalLayout_2->addWidget(rxAxisDoubleSpinBox);

        ryAxisDoubleSpinBox = new QDoubleSpinBox(rotAxisGroupBox);
        ryAxisDoubleSpinBox->setObjectName(QStringLiteral("ryAxisDoubleSpinBox"));
        ryAxisDoubleSpinBox->setPrefix(QStringLiteral("Y: "));
        ryAxisDoubleSpinBox->setDecimals(8);
        ryAxisDoubleSpinBox->setMinimum(-1e+09);
        ryAxisDoubleSpinBox->setMaximum(1e+09);

        horizontalLayout_2->addWidget(ryAxisDoubleSpinBox);

        rzAxisDoubleSpinBox = new QDoubleSpinBox(rotAxisGroupBox);
        rzAxisDoubleSpinBox->setObjectName(QStringLiteral("rzAxisDoubleSpinBox"));
        rzAxisDoubleSpinBox->setPrefix(QStringLiteral("Z: "));
        rzAxisDoubleSpinBox->setDecimals(8);
        rzAxisDoubleSpinBox->setMinimum(-1e+09);
        rzAxisDoubleSpinBox->setMaximum(1e+09);

        horizontalLayout_2->addWidget(rzAxisDoubleSpinBox);


        verticalLayout_2->addWidget(rotAxisGroupBox);

        rotAngleGroupBox = new QGroupBox(tab_2);
        rotAngleGroupBox->setObjectName(QStringLiteral("rotAngleGroupBox"));
        rotAngleGroupBox->setFlat(true);
        horizontalLayout_3 = new QHBoxLayout(rotAngleGroupBox);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, -1, 0, -1);
        rAngleDoubleSpinBox = new QDoubleSpinBox(rotAngleGroupBox);
        rAngleDoubleSpinBox->setObjectName(QStringLiteral("rAngleDoubleSpinBox"));
        rAngleDoubleSpinBox->setDecimals(4);
        rAngleDoubleSpinBox->setMinimum(-1e+09);
        rAngleDoubleSpinBox->setMaximum(1e+09);

        horizontalLayout_3->addWidget(rAngleDoubleSpinBox);

        horizontalSpacer_2 = new QSpacerItem(247, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(rotAngleGroupBox);

        transGroupBox = new QGroupBox(tab_2);
        transGroupBox->setObjectName(QStringLiteral("transGroupBox"));
        transGroupBox->setFlat(true);
        horizontalLayout_4 = new QHBoxLayout(transGroupBox);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, -1, 0, -1);
        txAxisDoubleSpinBox = new QDoubleSpinBox(transGroupBox);
        txAxisDoubleSpinBox->setObjectName(QStringLiteral("txAxisDoubleSpinBox"));
        txAxisDoubleSpinBox->setPrefix(QStringLiteral("X: "));
        txAxisDoubleSpinBox->setDecimals(8);
        txAxisDoubleSpinBox->setMinimum(-1e+09);
        txAxisDoubleSpinBox->setMaximum(1e+09);

        horizontalLayout_4->addWidget(txAxisDoubleSpinBox);

        tyAxisDoubleSpinBox = new QDoubleSpinBox(transGroupBox);
        tyAxisDoubleSpinBox->setObjectName(QStringLiteral("tyAxisDoubleSpinBox"));
        tyAxisDoubleSpinBox->setPrefix(QStringLiteral("Y: "));
        tyAxisDoubleSpinBox->setDecimals(8);
        tyAxisDoubleSpinBox->setMinimum(-1e+09);
        tyAxisDoubleSpinBox->setMaximum(1e+09);

        horizontalLayout_4->addWidget(tyAxisDoubleSpinBox);

        tzAxisDoubleSpinBox = new QDoubleSpinBox(transGroupBox);
        tzAxisDoubleSpinBox->setObjectName(QStringLiteral("tzAxisDoubleSpinBox"));
        tzAxisDoubleSpinBox->setPrefix(QStringLiteral("Z: "));
        tzAxisDoubleSpinBox->setDecimals(8);
        tzAxisDoubleSpinBox->setMinimum(-1e+09);
        tzAxisDoubleSpinBox->setMaximum(1e+09);

        horizontalLayout_4->addWidget(tzAxisDoubleSpinBox);


        verticalLayout_2->addWidget(transGroupBox);

        verticalSpacer = new QSpacerItem(20, 73, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        eulerAnglesGroupBox = new QGroupBox(tab_3);
        eulerAnglesGroupBox->setObjectName(QStringLiteral("eulerAnglesGroupBox"));
        eulerAnglesGroupBox->setFlat(true);
        horizontalLayout_6 = new QHBoxLayout(eulerAnglesGroupBox);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, -1, 0, -1);
        ePhiDoubleSpinBox = new QDoubleSpinBox(eulerAnglesGroupBox);
        ePhiDoubleSpinBox->setObjectName(QStringLiteral("ePhiDoubleSpinBox"));
        ePhiDoubleSpinBox->setPrefix(QStringLiteral("Phi: "));
        ePhiDoubleSpinBox->setDecimals(8);
        ePhiDoubleSpinBox->setMinimum(-1e+09);
        ePhiDoubleSpinBox->setMaximum(1e+09);

        horizontalLayout_6->addWidget(ePhiDoubleSpinBox);

        eThetaDoubleSpinBox = new QDoubleSpinBox(eulerAnglesGroupBox);
        eThetaDoubleSpinBox->setObjectName(QStringLiteral("eThetaDoubleSpinBox"));
        eThetaDoubleSpinBox->setPrefix(QStringLiteral("Theta: "));
        eThetaDoubleSpinBox->setDecimals(8);
        eThetaDoubleSpinBox->setMinimum(-1e+09);
        eThetaDoubleSpinBox->setMaximum(1e+09);

        horizontalLayout_6->addWidget(eThetaDoubleSpinBox);

        ePsiDoubleSpinBox = new QDoubleSpinBox(eulerAnglesGroupBox);
        ePsiDoubleSpinBox->setObjectName(QStringLiteral("ePsiDoubleSpinBox"));
        ePsiDoubleSpinBox->setPrefix(QStringLiteral("Psi: "));
        ePsiDoubleSpinBox->setDecimals(8);
        ePsiDoubleSpinBox->setMinimum(-1e+09);
        ePsiDoubleSpinBox->setMaximum(1e+09);

        horizontalLayout_6->addWidget(ePsiDoubleSpinBox);


        verticalLayout_3->addWidget(eulerAnglesGroupBox);

        eulerTransGroupBox = new QGroupBox(tab_3);
        eulerTransGroupBox->setObjectName(QStringLiteral("eulerTransGroupBox"));
        eulerTransGroupBox->setFlat(true);
        horizontalLayout_5 = new QHBoxLayout(eulerTransGroupBox);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, -1, 0, -1);
        etxAxisDoubleSpinBox = new QDoubleSpinBox(eulerTransGroupBox);
        etxAxisDoubleSpinBox->setObjectName(QStringLiteral("etxAxisDoubleSpinBox"));
        etxAxisDoubleSpinBox->setPrefix(QStringLiteral("X: "));
        etxAxisDoubleSpinBox->setDecimals(8);
        etxAxisDoubleSpinBox->setMinimum(-1e+09);
        etxAxisDoubleSpinBox->setMaximum(1e+09);

        horizontalLayout_5->addWidget(etxAxisDoubleSpinBox);

        etyAxisDoubleSpinBox = new QDoubleSpinBox(eulerTransGroupBox);
        etyAxisDoubleSpinBox->setObjectName(QStringLiteral("etyAxisDoubleSpinBox"));
        etyAxisDoubleSpinBox->setPrefix(QStringLiteral("Y: "));
        etyAxisDoubleSpinBox->setDecimals(8);
        etyAxisDoubleSpinBox->setMinimum(-1e+09);
        etyAxisDoubleSpinBox->setMaximum(1e+09);

        horizontalLayout_5->addWidget(etyAxisDoubleSpinBox);

        etzAxisDoubleSpinBox = new QDoubleSpinBox(eulerTransGroupBox);
        etzAxisDoubleSpinBox->setObjectName(QStringLiteral("etzAxisDoubleSpinBox"));
        etzAxisDoubleSpinBox->setPrefix(QStringLiteral("Z: "));
        etzAxisDoubleSpinBox->setDecimals(8);
        etzAxisDoubleSpinBox->setMinimum(-1e+09);
        etzAxisDoubleSpinBox->setMaximum(1e+09);

        horizontalLayout_5->addWidget(etzAxisDoubleSpinBox);


        verticalLayout_3->addWidget(eulerTransGroupBox);

        verticalSpacer_2 = new QSpacerItem(20, 139, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_4->addWidget(tabWidget);

        inverseCheckBox = new QCheckBox(ApplyTransformationDialog);
        inverseCheckBox->setObjectName(QStringLiteral("inverseCheckBox"));

        verticalLayout_4->addWidget(inverseCheckBox);

        buttonBox = new QDialogButtonBox(ApplyTransformationDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok|QDialogButtonBox::Reset);

        verticalLayout_4->addWidget(buttonBox);


        retranslateUi(ApplyTransformationDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), ApplyTransformationDialog, SLOT(reject()));
        QObject::connect(helpToolButton, SIGNAL(toggled(bool)), helpTextEdit, SLOT(setVisible(bool)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ApplyTransformationDialog);
    } // setupUi

    void retranslateUi(QDialog *ApplyTransformationDialog)
    {
        ApplyTransformationDialog->setWindowTitle(QApplication::translate("ApplyTransformationDialog", "Apply transformation", 0));
        label->setText(QApplication::translate("ApplyTransformationDialog", "Enter 4x4 matrix values:", 0));
#ifndef QT_NO_TOOLTIP
        fromFileToolButton->setToolTip(QApplication::translate("ApplyTransformationDialog", "Load matrix from ascii file", 0));
#endif // QT_NO_TOOLTIP
        fromFileToolButton->setText(QApplication::translate("ApplyTransformationDialog", "ASCII file", 0));
#ifndef QT_NO_TOOLTIP
        fromClipboardToolButton->setToolTip(QApplication::translate("ApplyTransformationDialog", "Paste clipboard contents", 0));
#endif // QT_NO_TOOLTIP
        fromClipboardToolButton->setText(QApplication::translate("ApplyTransformationDialog", "clipboard", 0));
#ifndef QT_NO_TOOLTIP
        fromDipDipDirToolButton->setToolTip(QApplication::translate("ApplyTransformationDialog", "Inits the matrix from dip/dip direction values\n"
"--> assuming an initial position of (0,0)", 0));
#endif // QT_NO_TOOLTIP
        fromDipDipDirToolButton->setText(QApplication::translate("ApplyTransformationDialog", "dip / dip direction", 0));
        helpToolButton->setText(QApplication::translate("ApplyTransformationDialog", "help", 0));
        helpTextEdit->setPlainText(QApplication::translate("ApplyTransformationDialog", "Matrix should be of the form:\n"
"R11   R12   R13   Tx\n"
"R21   R22   R23   Ty\n"
"R31   R32   R33   Tz\n"
"0       0        0       1\n"
"\n"
"Where R is a standard 3x3 rotation matrix and T is a translation vector.\n"
"\n"
"Let P be a 3D point, the transformed point P' will be such that: P' = R.P + T.", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ApplyTransformationDialog", "Matrix 4x4", 0));
        rotAxisGroupBox->setTitle(QApplication::translate("ApplyTransformationDialog", "Rotation axis", 0));
        rotAngleGroupBox->setTitle(QApplication::translate("ApplyTransformationDialog", "Rotation angle (degrees)", 0));
        rAngleDoubleSpinBox->setSuffix(QApplication::translate("ApplyTransformationDialog", " deg.", 0));
        transGroupBox->setTitle(QApplication::translate("ApplyTransformationDialog", "Translation", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ApplyTransformationDialog", "Axis, Angle", 0));
        eulerAnglesGroupBox->setTitle(QApplication::translate("ApplyTransformationDialog", "Angles", 0));
        eulerTransGroupBox->setTitle(QApplication::translate("ApplyTransformationDialog", "Translation", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("ApplyTransformationDialog", "Euler angles", 0));
        inverseCheckBox->setText(QApplication::translate("ApplyTransformationDialog", "Apply inverse transformation", 0));
    } // retranslateUi

};

namespace Ui {
    class ApplyTransformationDialog: public Ui_ApplyTransformationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLYTRANSFORMATIONDLG_H
