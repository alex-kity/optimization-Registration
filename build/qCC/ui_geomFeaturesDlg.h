/********************************************************************************
** Form generated from reading UI file 'geomFeaturesDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GEOMFEATURESDLG_H
#define UI_GEOMFEATURESDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GeomFeaturesDialog
{
public:
    QVBoxLayout *verticalLayout_7;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QDoubleSpinBox *radiusDoubleSpinBox;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *roughnessGroupBox;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *roughnessCheckBox;
    QGroupBox *curvatureGroupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *curvMeanCheckBox;
    QCheckBox *curvGaussCheckBox;
    QCheckBox *curvNCRCheckBox;
    QGroupBox *desnityGroupBox;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *densityKnnCheckBox;
    QCheckBox *densitySurfCheckBox;
    QCheckBox *densityVolCheckBox;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_8;
    QCheckBox *firstOrderMomentCheckBox;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *featureGroupBox;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *eigSumCheckBox;
    QCheckBox *eigOmnivarianceCheckBox;
    QCheckBox *eigenentropyCheckBox;
    QCheckBox *eigAnisotropyCheckBox;
    QCheckBox *eigPlanarityBox;
    QCheckBox *eigLinearityCheckBox;
    QCheckBox *eigPCA1CheckBox;
    QCheckBox *eigPCA2CheckBox;
    QCheckBox *eigSurfaceVarCheckBox;
    QCheckBox *eigSphericityCheckBox;
    QCheckBox *eigVerticalityCheckBox;
    QCheckBox *eigenvalue1CheckBox;
    QCheckBox *eigenvalue2CheckBox;
    QCheckBox *eigenvalue3CheckBox;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GeomFeaturesDialog)
    {
        if (GeomFeaturesDialog->objectName().isEmpty())
            GeomFeaturesDialog->setObjectName(QStringLiteral("GeomFeaturesDialog"));
        GeomFeaturesDialog->resize(452, 700);
        verticalLayout_7 = new QVBoxLayout(GeomFeaturesDialog);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        frame = new QFrame(GeomFeaturesDialog);
        frame->setObjectName(QStringLiteral("frame"));
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(101, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        radiusDoubleSpinBox = new QDoubleSpinBox(frame);
        radiusDoubleSpinBox->setObjectName(QStringLiteral("radiusDoubleSpinBox"));
        radiusDoubleSpinBox->setDecimals(6);
        radiusDoubleSpinBox->setMinimum(1e-06);
        radiusDoubleSpinBox->setMaximum(1e+06);
        radiusDoubleSpinBox->setValue(1);

        horizontalLayout_2->addWidget(radiusDoubleSpinBox);

        horizontalSpacer_2 = new QSpacerItem(101, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_7->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        roughnessGroupBox = new QGroupBox(GeomFeaturesDialog);
        roughnessGroupBox->setObjectName(QStringLiteral("roughnessGroupBox"));
        verticalLayout_4 = new QVBoxLayout(roughnessGroupBox);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        roughnessCheckBox = new QCheckBox(roughnessGroupBox);
        roughnessCheckBox->setObjectName(QStringLiteral("roughnessCheckBox"));

        verticalLayout_4->addWidget(roughnessCheckBox);


        verticalLayout_5->addWidget(roughnessGroupBox);

        curvatureGroupBox = new QGroupBox(GeomFeaturesDialog);
        curvatureGroupBox->setObjectName(QStringLiteral("curvatureGroupBox"));
        verticalLayout = new QVBoxLayout(curvatureGroupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        curvMeanCheckBox = new QCheckBox(curvatureGroupBox);
        curvMeanCheckBox->setObjectName(QStringLiteral("curvMeanCheckBox"));

        verticalLayout->addWidget(curvMeanCheckBox);

        curvGaussCheckBox = new QCheckBox(curvatureGroupBox);
        curvGaussCheckBox->setObjectName(QStringLiteral("curvGaussCheckBox"));

        verticalLayout->addWidget(curvGaussCheckBox);

        curvNCRCheckBox = new QCheckBox(curvatureGroupBox);
        curvNCRCheckBox->setObjectName(QStringLiteral("curvNCRCheckBox"));

        verticalLayout->addWidget(curvNCRCheckBox);


        verticalLayout_5->addWidget(curvatureGroupBox);

        desnityGroupBox = new QGroupBox(GeomFeaturesDialog);
        desnityGroupBox->setObjectName(QStringLiteral("desnityGroupBox"));
        verticalLayout_3 = new QVBoxLayout(desnityGroupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        densityKnnCheckBox = new QCheckBox(desnityGroupBox);
        densityKnnCheckBox->setObjectName(QStringLiteral("densityKnnCheckBox"));

        verticalLayout_3->addWidget(densityKnnCheckBox);

        densitySurfCheckBox = new QCheckBox(desnityGroupBox);
        densitySurfCheckBox->setObjectName(QStringLiteral("densitySurfCheckBox"));

        verticalLayout_3->addWidget(densitySurfCheckBox);

        densityVolCheckBox = new QCheckBox(desnityGroupBox);
        densityVolCheckBox->setObjectName(QStringLiteral("densityVolCheckBox"));

        verticalLayout_3->addWidget(densityVolCheckBox);


        verticalLayout_5->addWidget(desnityGroupBox);

        groupBox_2 = new QGroupBox(GeomFeaturesDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_8 = new QVBoxLayout(groupBox_2);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        firstOrderMomentCheckBox = new QCheckBox(groupBox_2);
        firstOrderMomentCheckBox->setObjectName(QStringLiteral("firstOrderMomentCheckBox"));

        verticalLayout_8->addWidget(firstOrderMomentCheckBox);


        verticalLayout_5->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        featureGroupBox = new QGroupBox(GeomFeaturesDialog);
        featureGroupBox->setObjectName(QStringLiteral("featureGroupBox"));
        verticalLayout_2 = new QVBoxLayout(featureGroupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        eigSumCheckBox = new QCheckBox(featureGroupBox);
        eigSumCheckBox->setObjectName(QStringLiteral("eigSumCheckBox"));

        verticalLayout_2->addWidget(eigSumCheckBox);

        eigOmnivarianceCheckBox = new QCheckBox(featureGroupBox);
        eigOmnivarianceCheckBox->setObjectName(QStringLiteral("eigOmnivarianceCheckBox"));

        verticalLayout_2->addWidget(eigOmnivarianceCheckBox);

        eigenentropyCheckBox = new QCheckBox(featureGroupBox);
        eigenentropyCheckBox->setObjectName(QStringLiteral("eigenentropyCheckBox"));

        verticalLayout_2->addWidget(eigenentropyCheckBox);

        eigAnisotropyCheckBox = new QCheckBox(featureGroupBox);
        eigAnisotropyCheckBox->setObjectName(QStringLiteral("eigAnisotropyCheckBox"));

        verticalLayout_2->addWidget(eigAnisotropyCheckBox);

        eigPlanarityBox = new QCheckBox(featureGroupBox);
        eigPlanarityBox->setObjectName(QStringLiteral("eigPlanarityBox"));

        verticalLayout_2->addWidget(eigPlanarityBox);

        eigLinearityCheckBox = new QCheckBox(featureGroupBox);
        eigLinearityCheckBox->setObjectName(QStringLiteral("eigLinearityCheckBox"));

        verticalLayout_2->addWidget(eigLinearityCheckBox);

        eigPCA1CheckBox = new QCheckBox(featureGroupBox);
        eigPCA1CheckBox->setObjectName(QStringLiteral("eigPCA1CheckBox"));

        verticalLayout_2->addWidget(eigPCA1CheckBox);

        eigPCA2CheckBox = new QCheckBox(featureGroupBox);
        eigPCA2CheckBox->setObjectName(QStringLiteral("eigPCA2CheckBox"));

        verticalLayout_2->addWidget(eigPCA2CheckBox);

        eigSurfaceVarCheckBox = new QCheckBox(featureGroupBox);
        eigSurfaceVarCheckBox->setObjectName(QStringLiteral("eigSurfaceVarCheckBox"));

        verticalLayout_2->addWidget(eigSurfaceVarCheckBox);

        eigSphericityCheckBox = new QCheckBox(featureGroupBox);
        eigSphericityCheckBox->setObjectName(QStringLiteral("eigSphericityCheckBox"));

        verticalLayout_2->addWidget(eigSphericityCheckBox);

        eigVerticalityCheckBox = new QCheckBox(featureGroupBox);
        eigVerticalityCheckBox->setObjectName(QStringLiteral("eigVerticalityCheckBox"));

        verticalLayout_2->addWidget(eigVerticalityCheckBox);

        eigenvalue1CheckBox = new QCheckBox(featureGroupBox);
        eigenvalue1CheckBox->setObjectName(QStringLiteral("eigenvalue1CheckBox"));

        verticalLayout_2->addWidget(eigenvalue1CheckBox);

        eigenvalue2CheckBox = new QCheckBox(featureGroupBox);
        eigenvalue2CheckBox->setObjectName(QStringLiteral("eigenvalue2CheckBox"));

        verticalLayout_2->addWidget(eigenvalue2CheckBox);

        eigenvalue3CheckBox = new QCheckBox(featureGroupBox);
        eigenvalue3CheckBox->setObjectName(QStringLiteral("eigenvalue3CheckBox"));

        verticalLayout_2->addWidget(eigenvalue3CheckBox);


        verticalLayout_6->addWidget(featureGroupBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_6);


        verticalLayout_7->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);

        buttonBox = new QDialogButtonBox(GeomFeaturesDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok|QDialogButtonBox::Reset);

        verticalLayout_7->addWidget(buttonBox);


        retranslateUi(GeomFeaturesDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), GeomFeaturesDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GeomFeaturesDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(GeomFeaturesDialog);
    } // setupUi

    void retranslateUi(QDialog *GeomFeaturesDialog)
    {
        GeomFeaturesDialog->setWindowTitle(QApplication::translate("GeomFeaturesDialog", "Geometric features", 0));
        label->setText(QApplication::translate("GeomFeaturesDialog", "Local neighborhood radius", 0));
        roughnessGroupBox->setTitle(QApplication::translate("GeomFeaturesDialog", "Roughness", 0));
        roughnessCheckBox->setText(QApplication::translate("GeomFeaturesDialog", "Roughness", 0));
        curvatureGroupBox->setTitle(QApplication::translate("GeomFeaturesDialog", "Curvature", 0));
#ifndef QT_NO_TOOLTIP
        curvMeanCheckBox->setToolTip(QApplication::translate("GeomFeaturesDialog", "Mean curvature (unsigned)", 0));
#endif // QT_NO_TOOLTIP
        curvMeanCheckBox->setText(QApplication::translate("GeomFeaturesDialog", "Mean", 0));
#ifndef QT_NO_TOOLTIP
        curvGaussCheckBox->setToolTip(QApplication::translate("GeomFeaturesDialog", "Gaussian curvature (unsigned)", 0));
#endif // QT_NO_TOOLTIP
        curvGaussCheckBox->setText(QApplication::translate("GeomFeaturesDialog", "Gaussian", 0));
#ifndef QT_NO_TOOLTIP
        curvNCRCheckBox->setToolTip(QApplication::translate("GeomFeaturesDialog", "'Speed' of orientation change", 0));
#endif // QT_NO_TOOLTIP
        curvNCRCheckBox->setText(QApplication::translate("GeomFeaturesDialog", "Normal change rate", 0));
        desnityGroupBox->setTitle(QApplication::translate("GeomFeaturesDialog", "Density", 0));
#ifndef QT_NO_TOOLTIP
        densityKnnCheckBox->setToolTip(QApplication::translate("GeomFeaturesDialog", "Number of neighbors", 0));
#endif // QT_NO_TOOLTIP
        densityKnnCheckBox->setText(QApplication::translate("GeomFeaturesDialog", "Number of neighbors", 0));
#ifndef QT_NO_TOOLTIP
        densitySurfCheckBox->setToolTip(QApplication::translate("GeomFeaturesDialog", "Number of neighbors / neighborhood area", 0));
#endif // QT_NO_TOOLTIP
        densitySurfCheckBox->setText(QApplication::translate("GeomFeaturesDialog", "Surface density", 0));
#ifndef QT_NO_TOOLTIP
        densityVolCheckBox->setToolTip(QApplication::translate("GeomFeaturesDialog", "Number of neighbors / neighborhood volume", 0));
#endif // QT_NO_TOOLTIP
        densityVolCheckBox->setText(QApplication::translate("GeomFeaturesDialog", "Volume density", 0));
        groupBox_2->setTitle(QApplication::translate("GeomFeaturesDialog", "Moment", 0));
        firstOrderMomentCheckBox->setText(QApplication::translate("GeomFeaturesDialog", "1st order moment", 0));
#ifndef QT_NO_TOOLTIP
        featureGroupBox->setToolTip(QApplication::translate("GeomFeaturesDialog", "Geometric features (based on local eigenvalues: (L1, L2, L3))", 0));
#endif // QT_NO_TOOLTIP
        featureGroupBox->setTitle(QApplication::translate("GeomFeaturesDialog", "Features", 0));
#ifndef QT_NO_TOOLTIP
        eigSumCheckBox->setToolTip(QApplication::translate("GeomFeaturesDialog", "L1 + L2 + L3", 0));
#endif // QT_NO_TOOLTIP
        eigSumCheckBox->setText(QApplication::translate("GeomFeaturesDialog", "Sum of eigenvalues", 0));
#ifndef QT_NO_TOOLTIP
        eigOmnivarianceCheckBox->setToolTip(QApplication::translate("GeomFeaturesDialog", "(L1 * L2 * L3)^(1/3)", 0));
#endif // QT_NO_TOOLTIP
        eigOmnivarianceCheckBox->setText(QApplication::translate("GeomFeaturesDialog", "Ominvariance", 0));
#ifndef QT_NO_TOOLTIP
        eigenentropyCheckBox->setToolTip(QApplication::translate("GeomFeaturesDialog", "-( L1*ln(L1) + L2*ln(L2) + L3*ln(L3) )", 0));
#endif // QT_NO_TOOLTIP
        eigenentropyCheckBox->setText(QApplication::translate("GeomFeaturesDialog", "Eigenentropy", 0));
#ifndef QT_NO_TOOLTIP
        eigAnisotropyCheckBox->setToolTip(QApplication::translate("GeomFeaturesDialog", "(L1 - L3)/L1", 0));
#endif // QT_NO_TOOLTIP
        eigAnisotropyCheckBox->setText(QApplication::translate("GeomFeaturesDialog", "Anisotropy", 0));
#ifndef QT_NO_TOOLTIP
        eigPlanarityBox->setToolTip(QApplication::translate("GeomFeaturesDialog", "(L2 - L3)/L1", 0));
#endif // QT_NO_TOOLTIP
        eigPlanarityBox->setText(QApplication::translate("GeomFeaturesDialog", "Planarity", 0));
#ifndef QT_NO_TOOLTIP
        eigLinearityCheckBox->setToolTip(QApplication::translate("GeomFeaturesDialog", "(L1 - L2)/L1", 0));
#endif // QT_NO_TOOLTIP
        eigLinearityCheckBox->setText(QApplication::translate("GeomFeaturesDialog", "Linearity", 0));
#ifndef QT_NO_TOOLTIP
        eigPCA1CheckBox->setToolTip(QApplication::translate("GeomFeaturesDialog", "L1 / (L1 + L2 + L3)", 0));
#endif // QT_NO_TOOLTIP
        eigPCA1CheckBox->setText(QApplication::translate("GeomFeaturesDialog", "PCA1", 0));
#ifndef QT_NO_TOOLTIP
        eigPCA2CheckBox->setToolTip(QApplication::translate("GeomFeaturesDialog", "L2 / (L1 + L2 + L3)", 0));
#endif // QT_NO_TOOLTIP
        eigPCA2CheckBox->setText(QApplication::translate("GeomFeaturesDialog", "PCA2", 0));
#ifndef QT_NO_TOOLTIP
        eigSurfaceVarCheckBox->setToolTip(QApplication::translate("GeomFeaturesDialog", "L3 / (L1 + L2 + L3)", 0));
#endif // QT_NO_TOOLTIP
        eigSurfaceVarCheckBox->setText(QApplication::translate("GeomFeaturesDialog", "Surface variation", 0));
#ifndef QT_NO_TOOLTIP
        eigSphericityCheckBox->setToolTip(QApplication::translate("GeomFeaturesDialog", "L3 / L1", 0));
#endif // QT_NO_TOOLTIP
        eigSphericityCheckBox->setText(QApplication::translate("GeomFeaturesDialog", "Sphericity", 0));
#ifndef QT_NO_TOOLTIP
        eigVerticalityCheckBox->setToolTip(QApplication::translate("GeomFeaturesDialog", "1 - |Z.N|", 0));
#endif // QT_NO_TOOLTIP
        eigVerticalityCheckBox->setText(QApplication::translate("GeomFeaturesDialog", "Verticality", 0));
        eigenvalue1CheckBox->setText(QApplication::translate("GeomFeaturesDialog", "1st eigenvalue", 0));
        eigenvalue2CheckBox->setText(QApplication::translate("GeomFeaturesDialog", "2nd eigenvalue", 0));
        eigenvalue3CheckBox->setText(QApplication::translate("GeomFeaturesDialog", "3rd eigenvalue", 0));
    } // retranslateUi

};

namespace Ui {
    class GeomFeaturesDialog: public Ui_GeomFeaturesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GEOMFEATURESDLG_H
