/********************************************************************************
** Form generated from reading UI file 'ransacSDDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANSACSDDLG_H
#define UI_RANSACSDDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RansacSDDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *planeCheckBox;
    QCheckBox *sphereCheckBox;
    QCheckBox *cylinderCheckBox;
    QCheckBox *coneCheckBox;
    QCheckBox *torusCheckBox;
    QGroupBox *advancedConeGroupBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *maxConeRadiuscheckBox;
    QDoubleSpinBox *maxConeRadiusdoubleSpinBox;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *maxConeLengthcheckBox;
    QDoubleSpinBox *maxConeLengthdoubleSpinBox;
    QHBoxLayout *horizontalLayout_11;
    QCheckBox *maxConeAnglecheckBox;
    QDoubleSpinBox *maxConeAngledoubleSpinBox;
    QGroupBox *groupBox_3;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QCheckBox *minSphereRadiuscheckBox;
    QDoubleSpinBox *minSphereRadiusdoubleSpinBox;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *maxSphereRadiuscheckBox;
    QDoubleSpinBox *maxSphereRadiusdoubleSpinBox;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *minCylinderRadiuscheckBox;
    QDoubleSpinBox *minCylinderRadiusdoubleSpinBox;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *maxCylinderRadiuscheckBox;
    QDoubleSpinBox *maxCylinderRadiusdoubleSpinBox;
    QCheckBox *saveLeftOverscheckBox;
    QCheckBox *allowFittingcheckBox;
    QCheckBox *simplifyShapescheckBox;
    QDialogButtonBox *buttonBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpinBox *supportPointsSpinBox;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QDoubleSpinBox *epsilonDoubleSpinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *bitmapEpsilonDoubleSpinBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QDoubleSpinBox *maxNormDevAngleSpinBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QDoubleSpinBox *probaDoubleSpinBox;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *hboxLayout1;
    QCheckBox *minTorusMinorRadiuscheckBox;
    QDoubleSpinBox *minTorusMinorRadiusdoubleSpinBox;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *maxTorusMinorRadiuscheckBox;
    QDoubleSpinBox *maxTorusMinorRadiusdoubleSpinBox;
    QHBoxLayout *hboxLayout2;
    QCheckBox *minTorusMajorRadiuscheckBox;
    QDoubleSpinBox *minTorusMajorRadiusdoubleSpinBox;
    QHBoxLayout *horizontalLayout_13;
    QCheckBox *maxTorusMajorRadiuscheckBox;
    QDoubleSpinBox *maxTorusMajorRadiusdoubleSpinBox;
    QCheckBox *randomColorcheckBox;

    void setupUi(QDialog *RansacSDDialog)
    {
        if (RansacSDDialog->objectName().isEmpty())
            RansacSDDialog->setObjectName(QStringLiteral("RansacSDDialog"));
        RansacSDDialog->resize(656, 579);
        QIcon icon;
        icon.addFile(QStringLiteral(":/CC/plugin/qRANSAC_SD/images/qRANSAC_SD.png"), QSize(), QIcon::Normal, QIcon::Off);
        RansacSDDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(RansacSDDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_2 = new QGroupBox(RansacSDDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        planeCheckBox = new QCheckBox(groupBox_2);
        planeCheckBox->setObjectName(QStringLiteral("planeCheckBox"));
        planeCheckBox->setChecked(true);

        verticalLayout_2->addWidget(planeCheckBox);

        sphereCheckBox = new QCheckBox(groupBox_2);
        sphereCheckBox->setObjectName(QStringLiteral("sphereCheckBox"));
        sphereCheckBox->setChecked(true);

        verticalLayout_2->addWidget(sphereCheckBox);

        cylinderCheckBox = new QCheckBox(groupBox_2);
        cylinderCheckBox->setObjectName(QStringLiteral("cylinderCheckBox"));
        cylinderCheckBox->setChecked(true);

        verticalLayout_2->addWidget(cylinderCheckBox);

        coneCheckBox = new QCheckBox(groupBox_2);
        coneCheckBox->setObjectName(QStringLiteral("coneCheckBox"));
        coneCheckBox->setChecked(true);

        verticalLayout_2->addWidget(coneCheckBox);

        torusCheckBox = new QCheckBox(groupBox_2);
        torusCheckBox->setObjectName(QStringLiteral("torusCheckBox"));
        torusCheckBox->setChecked(true);

        verticalLayout_2->addWidget(torusCheckBox);


        gridLayout->addWidget(groupBox_2, 5, 0, 1, 1);

        advancedConeGroupBox = new QGroupBox(RansacSDDialog);
        advancedConeGroupBox->setObjectName(QStringLiteral("advancedConeGroupBox"));
        advancedConeGroupBox->setEnabled(true);
        advancedConeGroupBox->setFlat(false);
        advancedConeGroupBox->setCheckable(false);
        verticalLayout_5 = new QVBoxLayout(advancedConeGroupBox);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        maxConeRadiuscheckBox = new QCheckBox(advancedConeGroupBox);
        maxConeRadiuscheckBox->setObjectName(QStringLiteral("maxConeRadiuscheckBox"));

        horizontalLayout_8->addWidget(maxConeRadiuscheckBox);

        maxConeRadiusdoubleSpinBox = new QDoubleSpinBox(advancedConeGroupBox);
        maxConeRadiusdoubleSpinBox->setObjectName(QStringLiteral("maxConeRadiusdoubleSpinBox"));
        maxConeRadiusdoubleSpinBox->setEnabled(false);
        maxConeRadiusdoubleSpinBox->setDecimals(3);
        maxConeRadiusdoubleSpinBox->setMinimum(0.001);
        maxConeRadiusdoubleSpinBox->setMaximum(10000);
        maxConeRadiusdoubleSpinBox->setValue(1);

        horizontalLayout_8->addWidget(maxConeRadiusdoubleSpinBox);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        maxConeLengthcheckBox = new QCheckBox(advancedConeGroupBox);
        maxConeLengthcheckBox->setObjectName(QStringLiteral("maxConeLengthcheckBox"));

        horizontalLayout_10->addWidget(maxConeLengthcheckBox);

        maxConeLengthdoubleSpinBox = new QDoubleSpinBox(advancedConeGroupBox);
        maxConeLengthdoubleSpinBox->setObjectName(QStringLiteral("maxConeLengthdoubleSpinBox"));
        maxConeLengthdoubleSpinBox->setEnabled(false);
        maxConeLengthdoubleSpinBox->setDecimals(3);
        maxConeLengthdoubleSpinBox->setMinimum(0.001);
        maxConeLengthdoubleSpinBox->setMaximum(10000);
        maxConeLengthdoubleSpinBox->setValue(1);

        horizontalLayout_10->addWidget(maxConeLengthdoubleSpinBox);


        verticalLayout_5->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        maxConeAnglecheckBox = new QCheckBox(advancedConeGroupBox);
        maxConeAnglecheckBox->setObjectName(QStringLiteral("maxConeAnglecheckBox"));

        horizontalLayout_11->addWidget(maxConeAnglecheckBox);

        maxConeAngledoubleSpinBox = new QDoubleSpinBox(advancedConeGroupBox);
        maxConeAngledoubleSpinBox->setObjectName(QStringLiteral("maxConeAngledoubleSpinBox"));
        maxConeAngledoubleSpinBox->setEnabled(false);
        maxConeAngledoubleSpinBox->setDecimals(3);
        maxConeAngledoubleSpinBox->setMinimum(0.001);
        maxConeAngledoubleSpinBox->setMaximum(90);
        maxConeAngledoubleSpinBox->setValue(5);

        horizontalLayout_11->addWidget(maxConeAngledoubleSpinBox);


        verticalLayout_5->addLayout(horizontalLayout_11);


        gridLayout->addWidget(advancedConeGroupBox, 11, 2, 1, 1);

        groupBox_3 = new QGroupBox(RansacSDDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setEnabled(true);
        groupBox_3->setMinimumSize(QSize(0, 48));
        vboxLayout = new QVBoxLayout(groupBox_3);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        minSphereRadiuscheckBox = new QCheckBox(groupBox_3);
        minSphereRadiuscheckBox->setObjectName(QStringLiteral("minSphereRadiuscheckBox"));

        hboxLayout->addWidget(minSphereRadiuscheckBox);

        minSphereRadiusdoubleSpinBox = new QDoubleSpinBox(groupBox_3);
        minSphereRadiusdoubleSpinBox->setObjectName(QStringLiteral("minSphereRadiusdoubleSpinBox"));
        minSphereRadiusdoubleSpinBox->setEnabled(false);
        minSphereRadiusdoubleSpinBox->setDecimals(3);
        minSphereRadiusdoubleSpinBox->setMinimum(0.001);
        minSphereRadiusdoubleSpinBox->setMaximum(10000);
        minSphereRadiusdoubleSpinBox->setValue(1);

        hboxLayout->addWidget(minSphereRadiusdoubleSpinBox);


        vboxLayout->addLayout(hboxLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        maxSphereRadiuscheckBox = new QCheckBox(groupBox_3);
        maxSphereRadiuscheckBox->setObjectName(QStringLiteral("maxSphereRadiuscheckBox"));

        horizontalLayout_6->addWidget(maxSphereRadiuscheckBox);

        maxSphereRadiusdoubleSpinBox = new QDoubleSpinBox(groupBox_3);
        maxSphereRadiusdoubleSpinBox->setObjectName(QStringLiteral("maxSphereRadiusdoubleSpinBox"));
        maxSphereRadiusdoubleSpinBox->setEnabled(false);
        maxSphereRadiusdoubleSpinBox->setDecimals(3);
        maxSphereRadiusdoubleSpinBox->setMinimum(0.001);
        maxSphereRadiusdoubleSpinBox->setMaximum(10000);
        maxSphereRadiusdoubleSpinBox->setValue(1);

        horizontalLayout_6->addWidget(maxSphereRadiusdoubleSpinBox);


        vboxLayout->addLayout(horizontalLayout_6);


        gridLayout->addWidget(groupBox_3, 11, 0, 1, 1);

        groupBox_4 = new QGroupBox(RansacSDDialog);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        minCylinderRadiuscheckBox = new QCheckBox(groupBox_4);
        minCylinderRadiuscheckBox->setObjectName(QStringLiteral("minCylinderRadiuscheckBox"));

        horizontalLayout_9->addWidget(minCylinderRadiuscheckBox);

        minCylinderRadiusdoubleSpinBox = new QDoubleSpinBox(groupBox_4);
        minCylinderRadiusdoubleSpinBox->setObjectName(QStringLiteral("minCylinderRadiusdoubleSpinBox"));
        minCylinderRadiusdoubleSpinBox->setEnabled(false);
        minCylinderRadiusdoubleSpinBox->setDecimals(3);
        minCylinderRadiusdoubleSpinBox->setMinimum(0.001);
        minCylinderRadiusdoubleSpinBox->setMaximum(10000);
        minCylinderRadiusdoubleSpinBox->setValue(1);

        horizontalLayout_9->addWidget(minCylinderRadiusdoubleSpinBox);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        maxCylinderRadiuscheckBox = new QCheckBox(groupBox_4);
        maxCylinderRadiuscheckBox->setObjectName(QStringLiteral("maxCylinderRadiuscheckBox"));

        horizontalLayout_7->addWidget(maxCylinderRadiuscheckBox);

        maxCylinderRadiusdoubleSpinBox = new QDoubleSpinBox(groupBox_4);
        maxCylinderRadiusdoubleSpinBox->setObjectName(QStringLiteral("maxCylinderRadiusdoubleSpinBox"));
        maxCylinderRadiusdoubleSpinBox->setEnabled(false);
        maxCylinderRadiusdoubleSpinBox->setDecimals(3);
        maxCylinderRadiusdoubleSpinBox->setMinimum(0.001);
        maxCylinderRadiusdoubleSpinBox->setMaximum(10000);
        maxCylinderRadiusdoubleSpinBox->setValue(1);

        horizontalLayout_7->addWidget(maxCylinderRadiusdoubleSpinBox);


        verticalLayout_4->addLayout(horizontalLayout_7);


        gridLayout->addWidget(groupBox_4, 11, 1, 1, 1);

        saveLeftOverscheckBox = new QCheckBox(RansacSDDialog);
        saveLeftOverscheckBox->setObjectName(QStringLiteral("saveLeftOverscheckBox"));

        gridLayout->addWidget(saveLeftOverscheckBox, 1, 0, 1, 3);

        allowFittingcheckBox = new QCheckBox(RansacSDDialog);
        allowFittingcheckBox->setObjectName(QStringLiteral("allowFittingcheckBox"));

        gridLayout->addWidget(allowFittingcheckBox, 2, 0, 1, 1);

        simplifyShapescheckBox = new QCheckBox(RansacSDDialog);
        simplifyShapescheckBox->setObjectName(QStringLiteral("simplifyShapescheckBox"));
        simplifyShapescheckBox->setEnabled(false);

        gridLayout->addWidget(simplifyShapescheckBox, 3, 0, 1, 3);

        buttonBox = new QDialogButtonBox(RansacSDDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 16, 2, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));

        gridLayout->addLayout(verticalLayout_3, 10, 0, 1, 3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(RansacSDDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        supportPointsSpinBox = new QSpinBox(RansacSDDialog);
        supportPointsSpinBox->setObjectName(QStringLiteral("supportPointsSpinBox"));
        supportPointsSpinBox->setMinimum(10);
        supportPointsSpinBox->setMaximum(1000000000);
        supportPointsSpinBox->setSingleStep(100);
        supportPointsSpinBox->setValue(500);

        horizontalLayout_3->addWidget(supportPointsSpinBox);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 14, 2, 1, 1);

        groupBox = new QGroupBox(RansacSDDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        epsilonDoubleSpinBox = new QDoubleSpinBox(groupBox);
        epsilonDoubleSpinBox->setObjectName(QStringLiteral("epsilonDoubleSpinBox"));
        epsilonDoubleSpinBox->setPrefix(QStringLiteral("e = "));
        epsilonDoubleSpinBox->setDecimals(3);
        epsilonDoubleSpinBox->setMaximum(1e+09);
        epsilonDoubleSpinBox->setSingleStep(0.01);
        epsilonDoubleSpinBox->setValue(0.01);

        horizontalLayout->addWidget(epsilonDoubleSpinBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        bitmapEpsilonDoubleSpinBox = new QDoubleSpinBox(groupBox);
        bitmapEpsilonDoubleSpinBox->setObjectName(QStringLiteral("bitmapEpsilonDoubleSpinBox"));
        bitmapEpsilonDoubleSpinBox->setPrefix(QStringLiteral("b = "));
        bitmapEpsilonDoubleSpinBox->setDecimals(3);
        bitmapEpsilonDoubleSpinBox->setMaximum(1e+09);
        bitmapEpsilonDoubleSpinBox->setSingleStep(0.01);
        bitmapEpsilonDoubleSpinBox->setValue(0.02);

        horizontalLayout_2->addWidget(bitmapEpsilonDoubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        maxNormDevAngleSpinBox = new QDoubleSpinBox(groupBox);
        maxNormDevAngleSpinBox->setObjectName(QStringLiteral("maxNormDevAngleSpinBox"));
        maxNormDevAngleSpinBox->setPrefix(QStringLiteral("a = "));
        maxNormDevAngleSpinBox->setSuffix(QString::fromUtf8("\302\260"));
        maxNormDevAngleSpinBox->setMaximum(90);
        maxNormDevAngleSpinBox->setSingleStep(1);
        maxNormDevAngleSpinBox->setValue(25);

        horizontalLayout_4->addWidget(maxNormDevAngleSpinBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        probaDoubleSpinBox = new QDoubleSpinBox(groupBox);
        probaDoubleSpinBox->setObjectName(QStringLiteral("probaDoubleSpinBox"));
        probaDoubleSpinBox->setDecimals(6);
        probaDoubleSpinBox->setMaximum(1);
        probaDoubleSpinBox->setSingleStep(0.001);
        probaDoubleSpinBox->setValue(0.001);

        horizontalLayout_5->addWidget(probaDoubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout->addWidget(groupBox, 5, 1, 1, 2);

        groupBox_6 = new QGroupBox(RansacSDDialog);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        verticalLayout_6 = new QVBoxLayout(groupBox_6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        minTorusMinorRadiuscheckBox = new QCheckBox(groupBox_6);
        minTorusMinorRadiuscheckBox->setObjectName(QStringLiteral("minTorusMinorRadiuscheckBox"));

        hboxLayout1->addWidget(minTorusMinorRadiuscheckBox);

        minTorusMinorRadiusdoubleSpinBox = new QDoubleSpinBox(groupBox_6);
        minTorusMinorRadiusdoubleSpinBox->setObjectName(QStringLiteral("minTorusMinorRadiusdoubleSpinBox"));
        minTorusMinorRadiusdoubleSpinBox->setEnabled(false);
        minTorusMinorRadiusdoubleSpinBox->setDecimals(3);
        minTorusMinorRadiusdoubleSpinBox->setMinimum(0.001);
        minTorusMinorRadiusdoubleSpinBox->setMaximum(10000);
        minTorusMinorRadiusdoubleSpinBox->setValue(1);

        hboxLayout1->addWidget(minTorusMinorRadiusdoubleSpinBox);


        verticalLayout_6->addLayout(hboxLayout1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        maxTorusMinorRadiuscheckBox = new QCheckBox(groupBox_6);
        maxTorusMinorRadiuscheckBox->setObjectName(QStringLiteral("maxTorusMinorRadiuscheckBox"));

        horizontalLayout_12->addWidget(maxTorusMinorRadiuscheckBox);

        maxTorusMinorRadiusdoubleSpinBox = new QDoubleSpinBox(groupBox_6);
        maxTorusMinorRadiusdoubleSpinBox->setObjectName(QStringLiteral("maxTorusMinorRadiusdoubleSpinBox"));
        maxTorusMinorRadiusdoubleSpinBox->setEnabled(false);
        maxTorusMinorRadiusdoubleSpinBox->setDecimals(3);
        maxTorusMinorRadiusdoubleSpinBox->setMinimum(0.001);
        maxTorusMinorRadiusdoubleSpinBox->setMaximum(10000);
        maxTorusMinorRadiusdoubleSpinBox->setValue(1);

        horizontalLayout_12->addWidget(maxTorusMinorRadiusdoubleSpinBox);


        verticalLayout_6->addLayout(horizontalLayout_12);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName(QStringLiteral("hboxLayout2"));
        minTorusMajorRadiuscheckBox = new QCheckBox(groupBox_6);
        minTorusMajorRadiuscheckBox->setObjectName(QStringLiteral("minTorusMajorRadiuscheckBox"));

        hboxLayout2->addWidget(minTorusMajorRadiuscheckBox);

        minTorusMajorRadiusdoubleSpinBox = new QDoubleSpinBox(groupBox_6);
        minTorusMajorRadiusdoubleSpinBox->setObjectName(QStringLiteral("minTorusMajorRadiusdoubleSpinBox"));
        minTorusMajorRadiusdoubleSpinBox->setEnabled(false);
        minTorusMajorRadiusdoubleSpinBox->setDecimals(3);
        minTorusMajorRadiusdoubleSpinBox->setMinimum(0.001);
        minTorusMajorRadiusdoubleSpinBox->setMaximum(10000);
        minTorusMajorRadiusdoubleSpinBox->setValue(1);

        hboxLayout2->addWidget(minTorusMajorRadiusdoubleSpinBox);


        verticalLayout_6->addLayout(hboxLayout2);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        maxTorusMajorRadiuscheckBox = new QCheckBox(groupBox_6);
        maxTorusMajorRadiuscheckBox->setObjectName(QStringLiteral("maxTorusMajorRadiuscheckBox"));

        horizontalLayout_13->addWidget(maxTorusMajorRadiuscheckBox);

        maxTorusMajorRadiusdoubleSpinBox = new QDoubleSpinBox(groupBox_6);
        maxTorusMajorRadiusdoubleSpinBox->setObjectName(QStringLiteral("maxTorusMajorRadiusdoubleSpinBox"));
        maxTorusMajorRadiusdoubleSpinBox->setEnabled(false);
        maxTorusMajorRadiusdoubleSpinBox->setDecimals(3);
        maxTorusMajorRadiusdoubleSpinBox->setMinimum(0.001);
        maxTorusMajorRadiusdoubleSpinBox->setMaximum(10000);
        maxTorusMajorRadiusdoubleSpinBox->setValue(1);

        horizontalLayout_13->addWidget(maxTorusMajorRadiusdoubleSpinBox);


        verticalLayout_6->addLayout(horizontalLayout_13);


        gridLayout->addWidget(groupBox_6, 14, 0, 1, 2);

        randomColorcheckBox = new QCheckBox(RansacSDDialog);
        randomColorcheckBox->setObjectName(QStringLiteral("randomColorcheckBox"));

        gridLayout->addWidget(randomColorcheckBox, 4, 0, 1, 1);


        retranslateUi(RansacSDDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), RansacSDDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RansacSDDialog, SLOT(reject()));
        QObject::connect(sphereCheckBox, SIGNAL(toggled(bool)), groupBox_3, SLOT(setEnabled(bool)));
        QObject::connect(maxSphereRadiuscheckBox, SIGNAL(toggled(bool)), maxSphereRadiusdoubleSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(minCylinderRadiuscheckBox, SIGNAL(toggled(bool)), minCylinderRadiusdoubleSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(cylinderCheckBox, SIGNAL(toggled(bool)), groupBox_4, SLOT(setEnabled(bool)));
        QObject::connect(maxCylinderRadiuscheckBox, SIGNAL(toggled(bool)), maxCylinderRadiusdoubleSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(coneCheckBox, SIGNAL(toggled(bool)), advancedConeGroupBox, SLOT(setEnabled(bool)));
        QObject::connect(maxConeRadiuscheckBox, SIGNAL(toggled(bool)), maxConeRadiusdoubleSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(maxConeLengthcheckBox, SIGNAL(toggled(bool)), maxConeLengthdoubleSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(maxConeAnglecheckBox, SIGNAL(toggled(bool)), maxConeAngledoubleSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(torusCheckBox, SIGNAL(toggled(bool)), groupBox_6, SLOT(setEnabled(bool)));
        QObject::connect(maxTorusMajorRadiuscheckBox, SIGNAL(toggled(bool)), maxTorusMajorRadiusdoubleSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(maxTorusMinorRadiuscheckBox, SIGNAL(toggled(bool)), maxTorusMinorRadiusdoubleSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(minSphereRadiuscheckBox, SIGNAL(toggled(bool)), minSphereRadiusdoubleSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(minTorusMajorRadiuscheckBox, SIGNAL(toggled(bool)), minTorusMajorRadiusdoubleSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(minTorusMinorRadiuscheckBox, SIGNAL(toggled(bool)), minTorusMinorRadiusdoubleSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(allowFittingcheckBox, SIGNAL(toggled(bool)), simplifyShapescheckBox, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(RansacSDDialog);
    } // setupUi

    void retranslateUi(QDialog *RansacSDDialog)
    {
        RansacSDDialog->setWindowTitle(QApplication::translate("RansacSDDialog", "Ransac Shape Detection", 0));
        groupBox_2->setTitle(QApplication::translate("RansacSDDialog", "Primitives", 0));
        planeCheckBox->setText(QApplication::translate("RansacSDDialog", "Plane", 0));
        sphereCheckBox->setText(QApplication::translate("RansacSDDialog", "Sphere", 0));
        cylinderCheckBox->setText(QApplication::translate("RansacSDDialog", "Cylinder", 0));
        coneCheckBox->setText(QApplication::translate("RansacSDDialog", "Cone", 0));
        torusCheckBox->setText(QApplication::translate("RansacSDDialog", "Torus", 0));
        advancedConeGroupBox->setTitle(QApplication::translate("RansacSDDialog", "Cone Advanced Parameters", 0));
        maxConeRadiuscheckBox->setText(QApplication::translate("RansacSDDialog", "Max Radius", 0));
        maxConeLengthcheckBox->setText(QApplication::translate("RansacSDDialog", "Max Length", 0));
        maxConeAnglecheckBox->setText(QApplication::translate("RansacSDDialog", "Max Angle", 0));
        maxConeAngledoubleSpinBox->setSuffix(QApplication::translate("RansacSDDialog", "\302\260", 0));
        groupBox_3->setTitle(QApplication::translate("RansacSDDialog", "Sphere Advanced Parameters", 0));
        minSphereRadiuscheckBox->setText(QApplication::translate("RansacSDDialog", "Min Radius", 0));
        maxSphereRadiuscheckBox->setText(QApplication::translate("RansacSDDialog", "Max Radius", 0));
        groupBox_4->setTitle(QApplication::translate("RansacSDDialog", "Cylinder Advanced Parameters", 0));
        minCylinderRadiuscheckBox->setText(QApplication::translate("RansacSDDialog", "Min Radius", 0));
        maxCylinderRadiuscheckBox->setText(QApplication::translate("RansacSDDialog", "Max Radius", 0));
        saveLeftOverscheckBox->setText(QApplication::translate("RansacSDDialog", "Save leftover points into new cloud", 0));
        allowFittingcheckBox->setText(QApplication::translate("RansacSDDialog", "Use Least Squares fitting on found shapes", 0));
#ifndef QT_NO_TOOLTIP
        simplifyShapescheckBox->setToolTip(QApplication::translate("RansacSDDialog", "Will attempt to convert Spheres, Cones, Cylinders and Torus into a simpler shape (for example Cones may be simplified into a Cylinder, Plane, or Sphere)", 0));
#endif // QT_NO_TOOLTIP
        simplifyShapescheckBox->setText(QApplication::translate("RansacSDDialog", "Attempt to simplify shapes", 0));
        label->setText(QApplication::translate("RansacSDDialog", "Min support points per primitive", 0));
#ifndef QT_NO_TOOLTIP
        supportPointsSpinBox->setToolTip(QApplication::translate("RansacSDDialog", "This is the minimal number of points required for a primitive", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        supportPointsSpinBox->setStatusTip(QApplication::translate("RansacSDDialog", "This is the minimal number of points required for a primitive", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        supportPointsSpinBox->setWhatsThis(QApplication::translate("RansacSDDialog", "This is the minimal number of points required for a primitive", 0));
#endif // QT_NO_WHATSTHIS
        groupBox->setTitle(QApplication::translate("RansacSDDialog", "Parameters", 0));
        label_2->setText(QApplication::translate("RansacSDDialog", "max distance to primitive", 0));
#ifndef QT_NO_TOOLTIP
        epsilonDoubleSpinBox->setToolTip(QApplication::translate("RansacSDDialog", "Maximum distance of samples to the ideal shape", 0));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("RansacSDDialog", "sampling resolution", 0));
#ifndef QT_NO_TOOLTIP
        bitmapEpsilonDoubleSpinBox->setToolTip(QApplication::translate("RansacSDDialog", "Should correspond to the distance between neighboring points in the data", 0));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("RansacSDDialog", "max normal deviation", 0));
#ifndef QT_NO_TOOLTIP
        maxNormDevAngleSpinBox->setToolTip(QApplication::translate("RansacSDDialog", "Maximum deviation from the ideal shape normal vector (in degrees)", 0));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("RansacSDDialog", "overlooking probability", 0));
#ifndef QT_NO_TOOLTIP
        probaDoubleSpinBox->setToolTip(QApplication::translate("RansacSDDialog", "Probability that no better candidate was overlooked during sampling (the lower the better!)", 0));
#endif // QT_NO_TOOLTIP
        groupBox_6->setTitle(QApplication::translate("RansacSDDialog", "Torus Advanced Parameters", 0));
        minTorusMinorRadiuscheckBox->setText(QApplication::translate("RansacSDDialog", "Min Minor Radius", 0));
        maxTorusMinorRadiuscheckBox->setText(QApplication::translate("RansacSDDialog", "Max Minor Radius", 0));
        minTorusMajorRadiuscheckBox->setText(QApplication::translate("RansacSDDialog", "Min Major Radius", 0));
        maxTorusMajorRadiuscheckBox->setText(QApplication::translate("RansacSDDialog", "Max Major Radius", 0));
        randomColorcheckBox->setText(QApplication::translate("RansacSDDialog", "Set Random color for each shape found", 0));
    } // retranslateUi

};

namespace Ui {
    class RansacSDDialog: public Ui_RansacSDDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANSACSDDLG_H
