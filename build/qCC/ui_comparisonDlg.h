/********************************************************************************
** Form generated from reading UI file 'comparisonDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPARISONDLG_H
#define UI_COMPARISONDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComparisonDialog
{
public:
    QVBoxLayout *verticalLayout_5;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLineEdit *compName;
    QLabel *label_2;
    QLineEdit *refName;
    QTabWidget *preciseResultsTabWidget;
    QWidget *generalParamsTab;
    QVBoxLayout *verticalLayout_7;
    QFormLayout *formLayout;
    QLabel *label_5;
    QComboBox *octreeLevelComboBox;
    QCheckBox *maxDistCheckBox;
    QDoubleSpinBox *maxSearchDistSpinBox;
    QCheckBox *signedDistCheckBox;
    QCheckBox *flipNormalsCheckBox;
    QCheckBox *split3DCheckBox;
    QCheckBox *filterVisibilityCheckBox;
    QHBoxLayout *horizontalLayout;
    QCheckBox *multiThreadedCheckBox;
    QSpacerItem *horizontalSpacer;
    QFrame *threadCountFrame;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QSpinBox *maxThreadCountSpinBox;
    QSpacerItem *verticalSpacer_2;
    QWidget *localModelingTab;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *hboxLayout;
    QLabel *label_3;
    QComboBox *localModelComboBox;
    QFrame *localModelParamsFrame;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *lmKNNRadioButton;
    QSpinBox *lmKNNSpinBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *lmRadiusRadioButton;
    QDoubleSpinBox *lmRadiusDoubleSpinBox;
    QCheckBox *lmOptimizeCheckBox;
    QSpacerItem *verticalSpacer;
    QWidget *approxTab;
    QVBoxLayout *verticalLayout_9;
    QFrame *approxResultsInnerFrame;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_4;
    QTableWidget *approxStats;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem;
    QToolButton *histoButton;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *hboxLayout2;
    QSpacerItem *spacerItem1;
    QPushButton *computeButton;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *ComparisonDialog)
    {
        if (ComparisonDialog->objectName().isEmpty())
            ComparisonDialog->setObjectName(QStringLiteral("ComparisonDialog"));
        ComparisonDialog->resize(442, 458);
        verticalLayout_5 = new QVBoxLayout(ComparisonDialog);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label = new QLabel(ComparisonDialog);
        label->setObjectName(QStringLiteral("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        compName = new QLineEdit(ComparisonDialog);
        compName->setObjectName(QStringLiteral("compName"));
        compName->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, compName);

        label_2 = new QLabel(ComparisonDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        refName = new QLineEdit(ComparisonDialog);
        refName->setObjectName(QStringLiteral("refName"));
        refName->setReadOnly(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, refName);


        verticalLayout_5->addLayout(formLayout_2);

        preciseResultsTabWidget = new QTabWidget(ComparisonDialog);
        preciseResultsTabWidget->setObjectName(QStringLiteral("preciseResultsTabWidget"));
        generalParamsTab = new QWidget();
        generalParamsTab->setObjectName(QStringLiteral("generalParamsTab"));
        verticalLayout_7 = new QVBoxLayout(generalParamsTab);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_5 = new QLabel(generalParamsTab);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        octreeLevelComboBox = new QComboBox(generalParamsTab);
        octreeLevelComboBox->setObjectName(QStringLiteral("octreeLevelComboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, octreeLevelComboBox);

        maxDistCheckBox = new QCheckBox(generalParamsTab);
        maxDistCheckBox->setObjectName(QStringLiteral("maxDistCheckBox"));

        formLayout->setWidget(1, QFormLayout::LabelRole, maxDistCheckBox);

        maxSearchDistSpinBox = new QDoubleSpinBox(generalParamsTab);
        maxSearchDistSpinBox->setObjectName(QStringLiteral("maxSearchDistSpinBox"));
        maxSearchDistSpinBox->setEnabled(false);
        maxSearchDistSpinBox->setDecimals(6);
        maxSearchDistSpinBox->setMaximum(1e+09);
        maxSearchDistSpinBox->setValue(1);

        formLayout->setWidget(1, QFormLayout::FieldRole, maxSearchDistSpinBox);

        signedDistCheckBox = new QCheckBox(generalParamsTab);
        signedDistCheckBox->setObjectName(QStringLiteral("signedDistCheckBox"));

        formLayout->setWidget(2, QFormLayout::LabelRole, signedDistCheckBox);

        flipNormalsCheckBox = new QCheckBox(generalParamsTab);
        flipNormalsCheckBox->setObjectName(QStringLiteral("flipNormalsCheckBox"));
        flipNormalsCheckBox->setEnabled(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, flipNormalsCheckBox);


        verticalLayout_7->addLayout(formLayout);

        split3DCheckBox = new QCheckBox(generalParamsTab);
        split3DCheckBox->setObjectName(QStringLiteral("split3DCheckBox"));

        verticalLayout_7->addWidget(split3DCheckBox);

        filterVisibilityCheckBox = new QCheckBox(generalParamsTab);
        filterVisibilityCheckBox->setObjectName(QStringLiteral("filterVisibilityCheckBox"));

        verticalLayout_7->addWidget(filterVisibilityCheckBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        multiThreadedCheckBox = new QCheckBox(generalParamsTab);
        multiThreadedCheckBox->setObjectName(QStringLiteral("multiThreadedCheckBox"));
        multiThreadedCheckBox->setChecked(true);

        horizontalLayout->addWidget(multiThreadedCheckBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        threadCountFrame = new QFrame(generalParamsTab);
        threadCountFrame->setObjectName(QStringLiteral("threadCountFrame"));
        threadCountFrame->setFrameShape(QFrame::StyledPanel);
        threadCountFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_8 = new QHBoxLayout(threadCountFrame);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(threadCountFrame);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_8->addWidget(label_6);

        maxThreadCountSpinBox = new QSpinBox(threadCountFrame);
        maxThreadCountSpinBox->setObjectName(QStringLiteral("maxThreadCountSpinBox"));
        maxThreadCountSpinBox->setSuffix(QStringLiteral(" / 8"));

        horizontalLayout_8->addWidget(maxThreadCountSpinBox);


        horizontalLayout->addWidget(threadCountFrame);


        verticalLayout_7->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 87, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);

        preciseResultsTabWidget->addTab(generalParamsTab, QString());
        localModelingTab = new QWidget();
        localModelingTab->setObjectName(QStringLiteral("localModelingTab"));
        verticalLayout_3 = new QVBoxLayout(localModelingTab);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        label_3 = new QLabel(localModelingTab);
        label_3->setObjectName(QStringLiteral("label_3"));

        hboxLayout->addWidget(label_3);

        localModelComboBox = new QComboBox(localModelingTab);
        localModelComboBox->setObjectName(QStringLiteral("localModelComboBox"));

        hboxLayout->addWidget(localModelComboBox);


        verticalLayout_3->addLayout(hboxLayout);

        localModelParamsFrame = new QFrame(localModelingTab);
        localModelParamsFrame->setObjectName(QStringLiteral("localModelParamsFrame"));
        localModelParamsFrame->setEnabled(false);
        verticalLayout_4 = new QVBoxLayout(localModelParamsFrame);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lmKNNRadioButton = new QRadioButton(localModelParamsFrame);
        lmKNNRadioButton->setObjectName(QStringLiteral("lmKNNRadioButton"));
        lmKNNRadioButton->setChecked(true);

        verticalLayout_2->addWidget(lmKNNRadioButton);

        lmKNNSpinBox = new QSpinBox(localModelParamsFrame);
        lmKNNSpinBox->setObjectName(QStringLiteral("lmKNNSpinBox"));
        lmKNNSpinBox->setMinimum(3);
        lmKNNSpinBox->setValue(6);

        verticalLayout_2->addWidget(lmKNNSpinBox);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lmRadiusRadioButton = new QRadioButton(localModelParamsFrame);
        lmRadiusRadioButton->setObjectName(QStringLiteral("lmRadiusRadioButton"));

        verticalLayout->addWidget(lmRadiusRadioButton);

        lmRadiusDoubleSpinBox = new QDoubleSpinBox(localModelParamsFrame);
        lmRadiusDoubleSpinBox->setObjectName(QStringLiteral("lmRadiusDoubleSpinBox"));
        lmRadiusDoubleSpinBox->setEnabled(false);
        lmRadiusDoubleSpinBox->setDecimals(6);
        lmRadiusDoubleSpinBox->setMaximum(1e+09);

        verticalLayout->addWidget(lmRadiusDoubleSpinBox);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_4->addLayout(horizontalLayout_2);

        lmOptimizeCheckBox = new QCheckBox(localModelParamsFrame);
        lmOptimizeCheckBox->setObjectName(QStringLiteral("lmOptimizeCheckBox"));

        verticalLayout_4->addWidget(lmOptimizeCheckBox);


        verticalLayout_3->addWidget(localModelParamsFrame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        preciseResultsTabWidget->addTab(localModelingTab, QString());
        approxTab = new QWidget();
        approxTab->setObjectName(QStringLiteral("approxTab"));
        verticalLayout_9 = new QVBoxLayout(approxTab);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        approxResultsInnerFrame = new QFrame(approxTab);
        approxResultsInnerFrame->setObjectName(QStringLiteral("approxResultsInnerFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(approxResultsInnerFrame->sizePolicy().hasHeightForWidth());
        approxResultsInnerFrame->setSizePolicy(sizePolicy);
        approxResultsInnerFrame->setFrameShape(QFrame::StyledPanel);
        approxResultsInnerFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(approxResultsInnerFrame);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(approxResultsInnerFrame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("color: red;"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_4);

        approxStats = new QTableWidget(approxResultsInnerFrame);
        approxStats->setObjectName(QStringLiteral("approxStats"));
        approxStats->setMaximumSize(QSize(16777215, 150));

        verticalLayout_8->addWidget(approxStats);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem);

        histoButton = new QToolButton(approxResultsInnerFrame);
        histoButton->setObjectName(QStringLiteral("histoButton"));
        histoButton->setText(QStringLiteral("..."));
        QIcon icon;
        icon.addFile(QStringLiteral(":/CC/images/ccHistogram.png"), QSize(), QIcon::Normal, QIcon::Off);
        histoButton->setIcon(icon);

        hboxLayout1->addWidget(histoButton);


        verticalLayout_8->addLayout(hboxLayout1);


        verticalLayout_9->addWidget(approxResultsInnerFrame);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_3);

        preciseResultsTabWidget->addTab(approxTab, QString());

        verticalLayout_5->addWidget(preciseResultsTabWidget);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName(QStringLiteral("hboxLayout2"));
        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem1);

        computeButton = new QPushButton(ComparisonDialog);
        computeButton->setObjectName(QStringLiteral("computeButton"));
        computeButton->setStyleSheet(QStringLiteral("background-color:red; color: white;"));

        hboxLayout2->addWidget(computeButton);

        okButton = new QPushButton(ComparisonDialog);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setEnabled(false);

        hboxLayout2->addWidget(okButton);

        cancelButton = new QPushButton(ComparisonDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout2->addWidget(cancelButton);


        verticalLayout_5->addLayout(hboxLayout2);


        retranslateUi(ComparisonDialog);
        QObject::connect(maxDistCheckBox, SIGNAL(toggled(bool)), maxSearchDistSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(lmKNNRadioButton, SIGNAL(toggled(bool)), lmKNNSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(lmRadiusRadioButton, SIGNAL(toggled(bool)), lmRadiusDoubleSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(signedDistCheckBox, SIGNAL(toggled(bool)), flipNormalsCheckBox, SLOT(setEnabled(bool)));

        preciseResultsTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ComparisonDialog);
    } // setupUi

    void retranslateUi(QDialog *ComparisonDialog)
    {
        ComparisonDialog->setWindowTitle(QApplication::translate("ComparisonDialog", "Distance computation", 0));
        label->setText(QApplication::translate("ComparisonDialog", "Compared", 0));
        label_2->setText(QApplication::translate("ComparisonDialog", "Reference", 0));
#ifndef QT_NO_TOOLTIP
        label_5->setToolTip(QApplication::translate("ComparisonDialog", "Level of subdivision used for computing the distances", 0));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("ComparisonDialog", "Octree level", 0));
#ifndef QT_NO_TOOLTIP
        maxDistCheckBox->setToolTip(QApplication::translate("ComparisonDialog", "Acceleration: distances above this limit won't be computed accurately", 0));
#endif // QT_NO_TOOLTIP
        maxDistCheckBox->setText(QApplication::translate("ComparisonDialog", "max. distance", 0));
#ifndef QT_NO_TOOLTIP
        maxSearchDistSpinBox->setToolTip(QApplication::translate("ComparisonDialog", "Acceleration: distances above this limit won't be computed accurately", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        signedDistCheckBox->setToolTip(QApplication::translate("ComparisonDialog", "compute signed distances (slower)", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        signedDistCheckBox->setStatusTip(QApplication::translate("ComparisonDialog", "compute signed distances (slower)", 0));
#endif // QT_NO_STATUSTIP
        signedDistCheckBox->setText(QApplication::translate("ComparisonDialog", "signed distances", 0));
        flipNormalsCheckBox->setText(QApplication::translate("ComparisonDialog", "flip normals", 0));
#ifndef QT_NO_TOOLTIP
        split3DCheckBox->setToolTip(QApplication::translate("ComparisonDialog", "Generate 3 supplementary scalar fields with distances along each dimension", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        split3DCheckBox->setStatusTip(QApplication::translate("ComparisonDialog", "Generate 3 supplementary scalar fields with distances along each dimension", 0));
#endif // QT_NO_STATUSTIP
        split3DCheckBox->setText(QApplication::translate("ComparisonDialog", "split X,Y and Z components", 0));
#ifndef QT_NO_TOOLTIP
        filterVisibilityCheckBox->setToolTip(QApplication::translate("ComparisonDialog", "Use the sensor associated to the reference cloud to ignore the points in the compared cloud\n"
"that could not have been seen (hidden/out of range/out of field of view).", 0));
#endif // QT_NO_TOOLTIP
        filterVisibilityCheckBox->setText(QApplication::translate("ComparisonDialog", "use reference sensor to filter hidden points", 0));
        multiThreadedCheckBox->setText(QApplication::translate("ComparisonDialog", "multi-threaded", 0));
        label_6->setText(QApplication::translate("ComparisonDialog", "max thread count", 0));
#ifndef QT_NO_TOOLTIP
        maxThreadCountSpinBox->setToolTip(QApplication::translate("ComparisonDialog", "Maximum number of threads/cores to be used\n"
"(CC or your computer might not respond for a while if you use all available cores)", 0));
#endif // QT_NO_TOOLTIP
        preciseResultsTabWidget->setTabText(preciseResultsTabWidget->indexOf(generalParamsTab), QApplication::translate("ComparisonDialog", "General parameters", 0));
        label_3->setText(QApplication::translate("ComparisonDialog", "Local model", 0));
        lmKNNRadioButton->setText(QApplication::translate("ComparisonDialog", "Points (kNN)", 0));
        lmRadiusRadioButton->setText(QApplication::translate("ComparisonDialog", "Radius (Sphere)", 0));
#ifndef QT_NO_TOOLTIP
        lmOptimizeCheckBox->setToolTip(QApplication::translate("ComparisonDialog", "faster but more ... approximate", 0));
#endif // QT_NO_TOOLTIP
        lmOptimizeCheckBox->setText(QApplication::translate("ComparisonDialog", "use the same model for nearby points", 0));
        preciseResultsTabWidget->setTabText(preciseResultsTabWidget->indexOf(localModelingTab), QApplication::translate("ComparisonDialog", "Local modeling", 0));
        label_4->setText(QApplication::translate("ComparisonDialog", "Warning: approximate distances are only provided\n"
"to help advanced users setting the general parameters", 0));
        preciseResultsTabWidget->setTabText(preciseResultsTabWidget->indexOf(approxTab), QApplication::translate("ComparisonDialog", "Approximate distances", 0));
        computeButton->setText(QApplication::translate("ComparisonDialog", "Compute", 0));
        okButton->setText(QApplication::translate("ComparisonDialog", "Ok", 0));
        cancelButton->setText(QApplication::translate("ComparisonDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class ComparisonDialog: public Ui_ComparisonDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPARISONDLG_H
