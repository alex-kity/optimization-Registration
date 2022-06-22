/********************************************************************************
** Form generated from reading UI file 'rasterizeDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RASTERIZEDLG_H
#define UI_RASTERIZEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RasterizeToolDialog
{
public:
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout;
    QFrame *leftFrame;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *gridWidthLabel;
    QHBoxLayout *horizontalLayout_4;
    QDoubleSpinBox *gridStepDoubleSpinBox;
    QToolButton *editGridToolButton;
    QLabel *label_13;
    QComboBox *activeLayerComboBox;
    QLabel *label_7;
    QLabel *gridLayerRangeLabel;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QComboBox *scalarFieldProjection;
    QLabel *label_8;
    QLabel *label_9;
    QCheckBox *resampleCloudCheckBox;
    QComboBox *dimensionComboBox;
    QComboBox *heightProjectionComboBox;
    QCheckBox *interpolateSFCheckBox;
    QLabel *warningResampleWithAverageLabel;
    QGroupBox *emptyCellsFrame;
    QFormLayout *formLayout;
    QLabel *label_5;
    QComboBox *fillEmptyCellsComboBox;
    QDoubleSpinBox *emptyValueDoubleSpinBox;
    QPushButton *updateGridPushButton;
    QSpacerItem *verticalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *exportTab;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *generateCloudPushButton;
    QPushButton *generateMeshPushButton;
    QLabel *label_12;
    QFrame *exportCloudSFFrame;
    QFormLayout *formLayout_4;
    QCheckBox *generateCountSFcheckBox;
    QCheckBox *generateMinHeightSFcheckBox;
    QCheckBox *generateAvgHeightSFcheckBox;
    QCheckBox *generateMaxHeightSFcheckBox;
    QCheckBox *generateStdDevHeightSFcheckBox;
    QCheckBox *generateHeightRangeSFcheckBox;
    QSpacerItem *verticalSpacer;
    QFrame *line;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *generateRasterPushButton;
    QPushButton *generateImagePushButton;
    QPushButton *generateASCIIPushButton;
    QWidget *contourTab;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_15;
    QFormLayout *formLayout_3;
    QLabel *label_6;
    QDoubleSpinBox *contourStartDoubleSpinBox;
    QLabel *label_10;
    QDoubleSpinBox *contourStepDoubleSpinBox;
    QLabel *label_11;
    QSpinBox *minVertexCountSpinBox;
    QLabel *label_14;
    QSpinBox *contourWidthSpinBox;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *colorizeContoursCheckBox;
    QCheckBox *ignoreContourBordersCheckBox;
    QSpacerItem *horizontalSpacer;
    QCheckBox *projectContoursOnAltCheckBox;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *clearContoursPushButton;
    QPushButton *exportContoursPushButton;
    QPushButton *generateContoursPushButton;
    QWidget *hillshadeTab;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_16;
    QFormLayout *formLayout_5;
    QLabel *label_17;
    QSpinBox *sunZenithSpinBox;
    QLabel *label_18;
    QSpinBox *sunAzimuthSpinBox;
    QSpacerItem *verticalSpacer_3;
    QPushButton *generateHillshadePushButton;
    QWidget *volumeTab;
    QFormLayout *formLayout_6;
    QLabel *label_19;
    QLabel *volumeLabel;
    QLabel *label_20;
    QLabel *filledCellsPercentageLabel;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *cloudInfoGroupBox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *cloudNameLabel;
    QFrame *mapFrame;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *RasterizeToolDialog)
    {
        if (RasterizeToolDialog->objectName().isEmpty())
            RasterizeToolDialog->setObjectName(QStringLiteral("RasterizeToolDialog"));
        RasterizeToolDialog->resize(1024, 873);
        verticalLayout_7 = new QVBoxLayout(RasterizeToolDialog);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        horizontalLayout->setSpacing(-1);
#endif
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        leftFrame = new QFrame(RasterizeToolDialog);
        leftFrame->setObjectName(QStringLiteral("leftFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leftFrame->sizePolicy().hasHeightForWidth());
        leftFrame->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(leftFrame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(leftFrame);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(6);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        gridWidthLabel = new QLabel(groupBox);
        gridWidthLabel->setObjectName(QStringLiteral("gridWidthLabel"));
        gridWidthLabel->setText(QStringLiteral("640 x 480"));

        gridLayout->addWidget(gridWidthLabel, 2, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        gridStepDoubleSpinBox = new QDoubleSpinBox(groupBox);
        gridStepDoubleSpinBox->setObjectName(QStringLiteral("gridStepDoubleSpinBox"));
        gridStepDoubleSpinBox->setDecimals(6);
        gridStepDoubleSpinBox->setMinimum(1e-05);
        gridStepDoubleSpinBox->setMaximum(100000);
        gridStepDoubleSpinBox->setSingleStep(0.001);
        gridStepDoubleSpinBox->setValue(1);

        horizontalLayout_4->addWidget(gridStepDoubleSpinBox);

        editGridToolButton = new QToolButton(groupBox);
        editGridToolButton->setObjectName(QStringLiteral("editGridToolButton"));

        horizontalLayout_4->addWidget(editGridToolButton);


        gridLayout->addLayout(horizontalLayout_4, 1, 1, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 3, 0, 1, 1);

        activeLayerComboBox = new QComboBox(groupBox);
        activeLayerComboBox->setObjectName(QStringLiteral("activeLayerComboBox"));

        gridLayout->addWidget(activeLayerComboBox, 3, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        gridLayerRangeLabel = new QLabel(groupBox);
        gridLayerRangeLabel->setObjectName(QStringLiteral("gridLayerRangeLabel"));

        gridLayout->addWidget(gridLayerRangeLabel, 4, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(leftFrame);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        scalarFieldProjection = new QComboBox(groupBox_2);
        scalarFieldProjection->setObjectName(QStringLiteral("scalarFieldProjection"));

        gridLayout_3->addWidget(scalarFieldProjection, 2, 1, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_3->addWidget(label_9, 0, 0, 1, 1);

        resampleCloudCheckBox = new QCheckBox(groupBox_2);
        resampleCloudCheckBox->setObjectName(QStringLiteral("resampleCloudCheckBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(resampleCloudCheckBox->sizePolicy().hasHeightForWidth());
        resampleCloudCheckBox->setSizePolicy(sizePolicy1);
        resampleCloudCheckBox->setChecked(false);

        gridLayout_3->addWidget(resampleCloudCheckBox, 3, 0, 1, 1);

        dimensionComboBox = new QComboBox(groupBox_2);
        dimensionComboBox->insertItems(0, QStringList()
         << QStringLiteral("X")
         << QStringLiteral("Y")
         << QStringLiteral("Z")
        );
        dimensionComboBox->setObjectName(QStringLiteral("dimensionComboBox"));

        gridLayout_3->addWidget(dimensionComboBox, 0, 1, 1, 1);

        heightProjectionComboBox = new QComboBox(groupBox_2);
        heightProjectionComboBox->setObjectName(QStringLiteral("heightProjectionComboBox"));

        gridLayout_3->addWidget(heightProjectionComboBox, 1, 1, 1, 1);

        interpolateSFCheckBox = new QCheckBox(groupBox_2);
        interpolateSFCheckBox->setObjectName(QStringLiteral("interpolateSFCheckBox"));
        sizePolicy1.setHeightForWidth(interpolateSFCheckBox->sizePolicy().hasHeightForWidth());
        interpolateSFCheckBox->setSizePolicy(sizePolicy1);
        interpolateSFCheckBox->setChecked(true);

        gridLayout_3->addWidget(interpolateSFCheckBox, 2, 0, 1, 1);

        warningResampleWithAverageLabel = new QLabel(groupBox_2);
        warningResampleWithAverageLabel->setObjectName(QStringLiteral("warningResampleWithAverageLabel"));
        warningResampleWithAverageLabel->setEnabled(false);
        warningResampleWithAverageLabel->setStyleSheet(QStringLiteral("color:red;"));
        warningResampleWithAverageLabel->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(warningResampleWithAverageLabel, 4, 0, 1, 2);


        verticalLayout->addWidget(groupBox_2);

        emptyCellsFrame = new QGroupBox(leftFrame);
        emptyCellsFrame->setObjectName(QStringLiteral("emptyCellsFrame"));
        formLayout = new QFormLayout(emptyCellsFrame);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout->setVerticalSpacing(6);
        label_5 = new QLabel(emptyCellsFrame);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        fillEmptyCellsComboBox = new QComboBox(emptyCellsFrame);
        fillEmptyCellsComboBox->setObjectName(QStringLiteral("fillEmptyCellsComboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(fillEmptyCellsComboBox->sizePolicy().hasHeightForWidth());
        fillEmptyCellsComboBox->setSizePolicy(sizePolicy2);

        formLayout->setWidget(0, QFormLayout::FieldRole, fillEmptyCellsComboBox);

        emptyValueDoubleSpinBox = new QDoubleSpinBox(emptyCellsFrame);
        emptyValueDoubleSpinBox->setObjectName(QStringLiteral("emptyValueDoubleSpinBox"));
        emptyValueDoubleSpinBox->setEnabled(false);
        sizePolicy1.setHeightForWidth(emptyValueDoubleSpinBox->sizePolicy().hasHeightForWidth());
        emptyValueDoubleSpinBox->setSizePolicy(sizePolicy1);
        emptyValueDoubleSpinBox->setDecimals(6);
        emptyValueDoubleSpinBox->setMinimum(-1e+09);
        emptyValueDoubleSpinBox->setMaximum(1e+09);
        emptyValueDoubleSpinBox->setValue(0);

        formLayout->setWidget(1, QFormLayout::FieldRole, emptyValueDoubleSpinBox);


        verticalLayout->addWidget(emptyCellsFrame);

        updateGridPushButton = new QPushButton(leftFrame);
        updateGridPushButton->setObjectName(QStringLiteral("updateGridPushButton"));
        sizePolicy1.setHeightForWidth(updateGridPushButton->sizePolicy().hasHeightForWidth());
        updateGridPushButton->setSizePolicy(sizePolicy1);
        updateGridPushButton->setStyleSheet(QStringLiteral("color: white; background-color:red;"));

        verticalLayout->addWidget(updateGridPushButton);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout->addItem(verticalSpacer_2);

        tabWidget = new QTabWidget(leftFrame);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy3);
        exportTab = new QWidget();
        exportTab->setObjectName(QStringLiteral("exportTab"));
        verticalLayout_3 = new QVBoxLayout(exportTab);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(8, -1, 8, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        generateCloudPushButton = new QPushButton(exportTab);
        generateCloudPushButton->setObjectName(QStringLiteral("generateCloudPushButton"));

        horizontalLayout_6->addWidget(generateCloudPushButton);

        generateMeshPushButton = new QPushButton(exportTab);
        generateMeshPushButton->setObjectName(QStringLiteral("generateMeshPushButton"));

        horizontalLayout_6->addWidget(generateMeshPushButton);


        verticalLayout_3->addLayout(horizontalLayout_6);

        label_12 = new QLabel(exportTab);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_3->addWidget(label_12);

        exportCloudSFFrame = new QFrame(exportTab);
        exportCloudSFFrame->setObjectName(QStringLiteral("exportCloudSFFrame"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(exportCloudSFFrame->sizePolicy().hasHeightForWidth());
        exportCloudSFFrame->setSizePolicy(sizePolicy4);
        exportCloudSFFrame->setFrameShape(QFrame::NoFrame);
        exportCloudSFFrame->setFrameShadow(QFrame::Plain);
        formLayout_4 = new QFormLayout(exportCloudSFFrame);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout_4->setContentsMargins(6, 6, 6, 6);
        generateCountSFcheckBox = new QCheckBox(exportCloudSFFrame);
        generateCountSFcheckBox->setObjectName(QStringLiteral("generateCountSFcheckBox"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, generateCountSFcheckBox);

        generateMinHeightSFcheckBox = new QCheckBox(exportCloudSFFrame);
        generateMinHeightSFcheckBox->setObjectName(QStringLiteral("generateMinHeightSFcheckBox"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, generateMinHeightSFcheckBox);

        generateAvgHeightSFcheckBox = new QCheckBox(exportCloudSFFrame);
        generateAvgHeightSFcheckBox->setObjectName(QStringLiteral("generateAvgHeightSFcheckBox"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, generateAvgHeightSFcheckBox);

        generateMaxHeightSFcheckBox = new QCheckBox(exportCloudSFFrame);
        generateMaxHeightSFcheckBox->setObjectName(QStringLiteral("generateMaxHeightSFcheckBox"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, generateMaxHeightSFcheckBox);

        generateStdDevHeightSFcheckBox = new QCheckBox(exportCloudSFFrame);
        generateStdDevHeightSFcheckBox->setObjectName(QStringLiteral("generateStdDevHeightSFcheckBox"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, generateStdDevHeightSFcheckBox);

        generateHeightRangeSFcheckBox = new QCheckBox(exportCloudSFFrame);
        generateHeightRangeSFcheckBox->setObjectName(QStringLiteral("generateHeightRangeSFcheckBox"));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, generateHeightRangeSFcheckBox);


        verticalLayout_3->addWidget(exportCloudSFFrame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        line = new QFrame(exportTab);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        generateRasterPushButton = new QPushButton(exportTab);
        generateRasterPushButton->setObjectName(QStringLiteral("generateRasterPushButton"));

        horizontalLayout_8->addWidget(generateRasterPushButton);

        generateImagePushButton = new QPushButton(exportTab);
        generateImagePushButton->setObjectName(QStringLiteral("generateImagePushButton"));

        horizontalLayout_8->addWidget(generateImagePushButton);

        generateASCIIPushButton = new QPushButton(exportTab);
        generateASCIIPushButton->setObjectName(QStringLiteral("generateASCIIPushButton"));

        horizontalLayout_8->addWidget(generateASCIIPushButton);


        verticalLayout_3->addLayout(horizontalLayout_8);

        tabWidget->addTab(exportTab, QString());
        contourTab = new QWidget();
        contourTab->setObjectName(QStringLiteral("contourTab"));
        verticalLayout_4 = new QVBoxLayout(contourTab);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(8, -1, 8, 0);
        label_15 = new QLabel(contourTab);
        label_15->setObjectName(QStringLiteral("label_15"));
        QFont font;
        font.setItalic(true);
        label_15->setFont(font);
        label_15->setStyleSheet(QStringLiteral("color: blue;"));

        verticalLayout_4->addWidget(label_15);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_6 = new QLabel(contourTab);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_6);

        contourStartDoubleSpinBox = new QDoubleSpinBox(contourTab);
        contourStartDoubleSpinBox->setObjectName(QStringLiteral("contourStartDoubleSpinBox"));
        contourStartDoubleSpinBox->setDecimals(6);
        contourStartDoubleSpinBox->setMinimum(-1e+09);
        contourStartDoubleSpinBox->setMaximum(1e+09);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, contourStartDoubleSpinBox);

        label_10 = new QLabel(contourTab);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_10);

        contourStepDoubleSpinBox = new QDoubleSpinBox(contourTab);
        contourStepDoubleSpinBox->setObjectName(QStringLiteral("contourStepDoubleSpinBox"));
        contourStepDoubleSpinBox->setDecimals(6);
        contourStepDoubleSpinBox->setMinimum(1e-06);
        contourStepDoubleSpinBox->setMaximum(1e+09);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, contourStepDoubleSpinBox);

        label_11 = new QLabel(contourTab);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_11);

        minVertexCountSpinBox = new QSpinBox(contourTab);
        minVertexCountSpinBox->setObjectName(QStringLiteral("minVertexCountSpinBox"));
        minVertexCountSpinBox->setMinimum(3);
        minVertexCountSpinBox->setMaximum(10000000);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, minVertexCountSpinBox);

        label_14 = new QLabel(contourTab);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_14);

        contourWidthSpinBox = new QSpinBox(contourTab);
        contourWidthSpinBox->setObjectName(QStringLiteral("contourWidthSpinBox"));
        contourWidthSpinBox->setMinimum(1);
        contourWidthSpinBox->setMaximum(10);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, contourWidthSpinBox);


        verticalLayout_4->addLayout(formLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        colorizeContoursCheckBox = new QCheckBox(contourTab);
        colorizeContoursCheckBox->setObjectName(QStringLiteral("colorizeContoursCheckBox"));

        horizontalLayout_5->addWidget(colorizeContoursCheckBox);

        ignoreContourBordersCheckBox = new QCheckBox(contourTab);
        ignoreContourBordersCheckBox->setObjectName(QStringLiteral("ignoreContourBordersCheckBox"));
        ignoreContourBordersCheckBox->setChecked(true);

        horizontalLayout_5->addWidget(ignoreContourBordersCheckBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout_5);

        projectContoursOnAltCheckBox = new QCheckBox(contourTab);
        projectContoursOnAltCheckBox->setObjectName(QStringLiteral("projectContoursOnAltCheckBox"));
        projectContoursOnAltCheckBox->setEnabled(false);

        verticalLayout_4->addWidget(projectContoursOnAltCheckBox);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        clearContoursPushButton = new QPushButton(contourTab);
        clearContoursPushButton->setObjectName(QStringLiteral("clearContoursPushButton"));
        clearContoursPushButton->setEnabled(false);

        horizontalLayout_7->addWidget(clearContoursPushButton);

        exportContoursPushButton = new QPushButton(contourTab);
        exportContoursPushButton->setObjectName(QStringLiteral("exportContoursPushButton"));
        exportContoursPushButton->setEnabled(false);

        horizontalLayout_7->addWidget(exportContoursPushButton);

        generateContoursPushButton = new QPushButton(contourTab);
        generateContoursPushButton->setObjectName(QStringLiteral("generateContoursPushButton"));

        horizontalLayout_7->addWidget(generateContoursPushButton);


        verticalLayout_4->addLayout(horizontalLayout_7);

        tabWidget->addTab(contourTab, QString());
        hillshadeTab = new QWidget();
        hillshadeTab->setObjectName(QStringLiteral("hillshadeTab"));
        verticalLayout_5 = new QVBoxLayout(hillshadeTab);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, -1, -1, 0);
        label_16 = new QLabel(hillshadeTab);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font);
        label_16->setStyleSheet(QStringLiteral("color: blue;"));

        verticalLayout_5->addWidget(label_16);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        label_17 = new QLabel(hillshadeTab);
        label_17->setObjectName(QStringLiteral("label_17"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_17);

        sunZenithSpinBox = new QSpinBox(hillshadeTab);
        sunZenithSpinBox->setObjectName(QStringLiteral("sunZenithSpinBox"));
        sunZenithSpinBox->setMaximum(90);
        sunZenithSpinBox->setSingleStep(5);
        sunZenithSpinBox->setValue(45);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, sunZenithSpinBox);

        label_18 = new QLabel(hillshadeTab);
        label_18->setObjectName(QStringLiteral("label_18"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, label_18);

        sunAzimuthSpinBox = new QSpinBox(hillshadeTab);
        sunAzimuthSpinBox->setObjectName(QStringLiteral("sunAzimuthSpinBox"));
        sunAzimuthSpinBox->setMaximum(360);
        sunAzimuthSpinBox->setSingleStep(5);
        sunAzimuthSpinBox->setValue(315);

        formLayout_5->setWidget(1, QFormLayout::FieldRole, sunAzimuthSpinBox);


        verticalLayout_5->addLayout(formLayout_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        generateHillshadePushButton = new QPushButton(hillshadeTab);
        generateHillshadePushButton->setObjectName(QStringLiteral("generateHillshadePushButton"));

        verticalLayout_5->addWidget(generateHillshadePushButton);

        tabWidget->addTab(hillshadeTab, QString());
        volumeTab = new QWidget();
        volumeTab->setObjectName(QStringLiteral("volumeTab"));
        formLayout_6 = new QFormLayout(volumeTab);
        formLayout_6->setObjectName(QStringLiteral("formLayout_6"));
        formLayout_6->setContentsMargins(-1, -1, -1, 0);
        label_19 = new QLabel(volumeTab);
        label_19->setObjectName(QStringLiteral("label_19"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_19);

        volumeLabel = new QLabel(volumeTab);
        volumeLabel->setObjectName(QStringLiteral("volumeLabel"));
        volumeLabel->setText(QStringLiteral("0"));

        formLayout_6->setWidget(0, QFormLayout::FieldRole, volumeLabel);

        label_20 = new QLabel(volumeTab);
        label_20->setObjectName(QStringLiteral("label_20"));

        formLayout_6->setWidget(1, QFormLayout::LabelRole, label_20);

        filledCellsPercentageLabel = new QLabel(volumeTab);
        filledCellsPercentageLabel->setObjectName(QStringLiteral("filledCellsPercentageLabel"));
        filledCellsPercentageLabel->setText(QStringLiteral("0%"));

        formLayout_6->setWidget(1, QFormLayout::FieldRole, filledCellsPercentageLabel);

        tabWidget->addTab(volumeTab, QString());

        verticalLayout->addWidget(tabWidget);

        verticalLayout->setStretch(3, 1);

        horizontalLayout->addWidget(leftFrame);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        cloudInfoGroupBox = new QGroupBox(RasterizeToolDialog);
        cloudInfoGroupBox->setObjectName(QStringLiteral("cloudInfoGroupBox"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(cloudInfoGroupBox->sizePolicy().hasHeightForWidth());
        cloudInfoGroupBox->setSizePolicy(sizePolicy5);
        horizontalLayout_9 = new QHBoxLayout(cloudInfoGroupBox);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(12, 6, 12, 6);
        cloudNameLabel = new QLabel(cloudInfoGroupBox);
        cloudNameLabel->setObjectName(QStringLiteral("cloudNameLabel"));
        cloudNameLabel->setAlignment(Qt::AlignCenter);
        cloudNameLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_9->addWidget(cloudNameLabel);


        verticalLayout_6->addWidget(cloudInfoGroupBox);

        mapFrame = new QFrame(RasterizeToolDialog);
        mapFrame->setObjectName(QStringLiteral("mapFrame"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(mapFrame->sizePolicy().hasHeightForWidth());
        mapFrame->setSizePolicy(sizePolicy6);
        mapFrame->setMinimumSize(QSize(512, 512));
        mapFrame->setFrameShape(QFrame::StyledPanel);
        mapFrame->setFrameShadow(QFrame::Raised);

        verticalLayout_6->addWidget(mapFrame);

        verticalLayout_6->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout_6);

        horizontalLayout->setStretch(1, 1);

        verticalLayout_7->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(RasterizeToolDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_7->addWidget(buttonBox);


        retranslateUi(RasterizeToolDialog);
        QObject::connect(interpolateSFCheckBox, SIGNAL(toggled(bool)), scalarFieldProjection, SLOT(setEnabled(bool)));

        scalarFieldProjection->setCurrentIndex(1);
        dimensionComboBox->setCurrentIndex(0);
        heightProjectionComboBox->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RasterizeToolDialog);
    } // setupUi

    void retranslateUi(QDialog *RasterizeToolDialog)
    {
        RasterizeToolDialog->setWindowTitle(QApplication::translate("RasterizeToolDialog", "Rasterize", 0));
        groupBox->setTitle(QApplication::translate("RasterizeToolDialog", "Grid", 0));
        label_4->setText(QApplication::translate("RasterizeToolDialog", "size", 0));
        label_2->setText(QApplication::translate("RasterizeToolDialog", "step", 0));
#ifndef QT_NO_TOOLTIP
        gridStepDoubleSpinBox->setToolTip(QApplication::translate("RasterizeToolDialog", "size of step of the grid generated (in the same units as the coordinates of the point cloud)", 0));
#endif // QT_NO_TOOLTIP
        editGridToolButton->setText(QApplication::translate("RasterizeToolDialog", "Edit grid", 0));
#ifndef QT_NO_TOOLTIP
        label_13->setToolTip(QApplication::translate("RasterizeToolDialog", "Active layer (or 'scalar field')", 0));
#endif // QT_NO_TOOLTIP
        label_13->setText(QApplication::translate("RasterizeToolDialog", "active layer", 0));
        label_7->setText(QApplication::translate("RasterizeToolDialog", "range", 0));
        gridLayerRangeLabel->setText(QString());
        groupBox_2->setTitle(QApplication::translate("RasterizeToolDialog", "Projection", 0));
        scalarFieldProjection->clear();
        scalarFieldProjection->insertItems(0, QStringList()
         << QApplication::translate("RasterizeToolDialog", "minimum value", 0)
         << QApplication::translate("RasterizeToolDialog", "average value", 0)
         << QApplication::translate("RasterizeToolDialog", "maximum value", 0)
        );
#ifndef QT_NO_TOOLTIP
        scalarFieldProjection->setToolTip(QApplication::translate("RasterizeToolDialog", "SF interpolation method", 0));
#endif // QT_NO_TOOLTIP
        label_8->setText(QApplication::translate("RasterizeToolDialog", "cell height", 0));
        label_9->setText(QApplication::translate("RasterizeToolDialog", "direction", 0));
#ifndef QT_NO_TOOLTIP
        resampleCloudCheckBox->setToolTip(QApplication::translate("RasterizeToolDialog", "Use the nearest point of the input cloud in each cell instead of the cell center", 0));
#endif // QT_NO_TOOLTIP
        resampleCloudCheckBox->setText(QApplication::translate("RasterizeToolDialog", "resample input cloud", 0));
        heightProjectionComboBox->clear();
        heightProjectionComboBox->insertItems(0, QStringList()
         << QApplication::translate("RasterizeToolDialog", "minimum", 0)
         << QApplication::translate("RasterizeToolDialog", "average", 0)
         << QApplication::translate("RasterizeToolDialog", "maximum", 0)
        );
#ifndef QT_NO_TOOLTIP
        heightProjectionComboBox->setToolTip(QApplication::translate("RasterizeToolDialog", "Per-cell height computation method:\n"
" - minimum = lowest point in the cell\n"
" - average = mean height of all points inside the cell\n"
" - maximum = highest point in the cell", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        interpolateSFCheckBox->setToolTip(QApplication::translate("RasterizeToolDialog", "interpolate SF(s)", 0));
#endif // QT_NO_TOOLTIP
        interpolateSFCheckBox->setText(QApplication::translate("RasterizeToolDialog", "interpolate SF(s)", 0));
        warningResampleWithAverageLabel->setText(QApplication::translate("RasterizeToolDialog", "Warning: the original point's height will be\n"
"replaced by the cell's average height!", 0));
        emptyCellsFrame->setTitle(QApplication::translate("RasterizeToolDialog", "Empty cells", 0));
        label_5->setText(QApplication::translate("RasterizeToolDialog", "Fill with", 0));
        fillEmptyCellsComboBox->clear();
        fillEmptyCellsComboBox->insertItems(0, QStringList()
         << QApplication::translate("RasterizeToolDialog", "leave empty", 0)
         << QApplication::translate("RasterizeToolDialog", "minimum height", 0)
         << QApplication::translate("RasterizeToolDialog", "average height", 0)
         << QApplication::translate("RasterizeToolDialog", "maximum height", 0)
         << QApplication::translate("RasterizeToolDialog", "user specified value", 0)
         << QApplication::translate("RasterizeToolDialog", "interpolate", 0)
        );
#ifndef QT_NO_TOOLTIP
        fillEmptyCellsComboBox->setToolTip(QApplication::translate("RasterizeToolDialog", "choose the value to fill the cells in which no point is projected : minimum value over the whole point cloud or average value (over the whole cloud also)", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        emptyValueDoubleSpinBox->setToolTip(QApplication::translate("RasterizeToolDialog", "Custom value for empty cells", 0));
#endif // QT_NO_TOOLTIP
        updateGridPushButton->setText(QApplication::translate("RasterizeToolDialog", "Update grid", 0));
#ifndef QT_NO_TOOLTIP
        generateCloudPushButton->setToolTip(QApplication::translate("RasterizeToolDialog", "Export grid as a point cloud", 0));
#endif // QT_NO_TOOLTIP
        generateCloudPushButton->setText(QApplication::translate("RasterizeToolDialog", "Cloud", 0));
#ifndef QT_NO_TOOLTIP
        generateMeshPushButton->setToolTip(QApplication::translate("RasterizeToolDialog", "Export grid as a mesh", 0));
#endif // QT_NO_TOOLTIP
        generateMeshPushButton->setText(QApplication::translate("RasterizeToolDialog", "Mesh", 0));
        label_12->setText(QApplication::translate("RasterizeToolDialog", "Export per-cell statistics as SF(s):", 0));
#ifndef QT_NO_TOOLTIP
        generateCountSFcheckBox->setToolTip(QApplication::translate("RasterizeToolDialog", "Adds a scalar field with the grid density (= number of points inside each cell)", 0));
#endif // QT_NO_TOOLTIP
        generateCountSFcheckBox->setText(QApplication::translate("RasterizeToolDialog", "population", 0));
#ifndef QT_NO_TOOLTIP
        generateMinHeightSFcheckBox->setToolTip(QApplication::translate("RasterizeToolDialog", "Adds a scalar field with the min. height of the points inside the cell", 0));
#endif // QT_NO_TOOLTIP
        generateMinHeightSFcheckBox->setText(QApplication::translate("RasterizeToolDialog", "min height", 0));
#ifndef QT_NO_TOOLTIP
        generateAvgHeightSFcheckBox->setToolTip(QApplication::translate("RasterizeToolDialog", "Adds a scalar field with the average height of the points inside the cell", 0));
#endif // QT_NO_TOOLTIP
        generateAvgHeightSFcheckBox->setText(QApplication::translate("RasterizeToolDialog", "average height", 0));
#ifndef QT_NO_TOOLTIP
        generateMaxHeightSFcheckBox->setToolTip(QApplication::translate("RasterizeToolDialog", "Adds a scalar field with the max. height of the points inside the cell", 0));
#endif // QT_NO_TOOLTIP
        generateMaxHeightSFcheckBox->setText(QApplication::translate("RasterizeToolDialog", "max height", 0));
#ifndef QT_NO_TOOLTIP
        generateStdDevHeightSFcheckBox->setToolTip(QApplication::translate("RasterizeToolDialog", "Adds a scalar field with the standard deviation of the heights of the points inside the cell", 0));
#endif // QT_NO_TOOLTIP
        generateStdDevHeightSFcheckBox->setText(QApplication::translate("RasterizeToolDialog", "height std. dev.", 0));
#ifndef QT_NO_TOOLTIP
        generateHeightRangeSFcheckBox->setToolTip(QApplication::translate("RasterizeToolDialog", "Adds a scalar field with the standard deviation of the heights of the points inside the cell", 0));
#endif // QT_NO_TOOLTIP
        generateHeightRangeSFcheckBox->setText(QApplication::translate("RasterizeToolDialog", "height range", 0));
#ifndef QT_NO_TOOLTIP
        generateRasterPushButton->setToolTip(QApplication::translate("RasterizeToolDialog", "Export grid as a raster (geotiff)", 0));
#endif // QT_NO_TOOLTIP
        generateRasterPushButton->setText(QApplication::translate("RasterizeToolDialog", "Raster", 0));
#ifndef QT_NO_TOOLTIP
        generateImagePushButton->setToolTip(QApplication::translate("RasterizeToolDialog", "Export grid as an image", 0));
#endif // QT_NO_TOOLTIP
        generateImagePushButton->setText(QApplication::translate("RasterizeToolDialog", "Image", 0));
#ifndef QT_NO_TOOLTIP
        generateASCIIPushButton->setToolTip(QApplication::translate("RasterizeToolDialog", "Export grid as a matrix (text file)", 0));
#endif // QT_NO_TOOLTIP
        generateASCIIPushButton->setText(QApplication::translate("RasterizeToolDialog", "Matrix", 0));
        tabWidget->setTabText(tabWidget->indexOf(exportTab), QApplication::translate("RasterizeToolDialog", "Export", 0));
        label_15->setText(QApplication::translate("RasterizeToolDialog", "The contour plot is computed on the active layer", 0));
        label_6->setText(QApplication::translate("RasterizeToolDialog", "Start value", 0));
        label_10->setText(QApplication::translate("RasterizeToolDialog", "step", 0));
        label_11->setText(QApplication::translate("RasterizeToolDialog", "Min. vertex count", 0));
#ifndef QT_NO_TOOLTIP
        minVertexCountSpinBox->setToolTip(QApplication::translate("RasterizeToolDialog", "Min vertex count per iso-line (to ignore the smallest ones)", 0));
#endif // QT_NO_TOOLTIP
        label_14->setText(QApplication::translate("RasterizeToolDialog", "Line width", 0));
#ifndef QT_NO_TOOLTIP
        contourWidthSpinBox->setToolTip(QApplication::translate("RasterizeToolDialog", "Default contour lines width", 0));
#endif // QT_NO_TOOLTIP
        colorizeContoursCheckBox->setText(QApplication::translate("RasterizeToolDialog", "colorize", 0));
        ignoreContourBordersCheckBox->setText(QApplication::translate("RasterizeToolDialog", "ignore borders", 0));
        projectContoursOnAltCheckBox->setText(QApplication::translate("RasterizeToolDialog", "project contours on the altitude layer", 0));
#ifndef QT_NO_TOOLTIP
        clearContoursPushButton->setToolTip(QApplication::translate("RasterizeToolDialog", "Remove all contour lines", 0));
#endif // QT_NO_TOOLTIP
        clearContoursPushButton->setText(QApplication::translate("RasterizeToolDialog", "Clear", 0));
#ifndef QT_NO_TOOLTIP
        exportContoursPushButton->setToolTip(QApplication::translate("RasterizeToolDialog", "Export contour lines to the DB tree", 0));
#endif // QT_NO_TOOLTIP
        exportContoursPushButton->setText(QApplication::translate("RasterizeToolDialog", "Export", 0));
        generateContoursPushButton->setText(QApplication::translate("RasterizeToolDialog", "Generate", 0));
        tabWidget->setTabText(tabWidget->indexOf(contourTab), QApplication::translate("RasterizeToolDialog", "Contour plot", 0));
        label_16->setText(QApplication::translate("RasterizeToolDialog", "Hillshade is computed on the height layer", 0));
        label_17->setText(QApplication::translate("RasterizeToolDialog", "Sun zenith", 0));
#ifndef QT_NO_TOOLTIP
        sunZenithSpinBox->setToolTip(QApplication::translate("RasterizeToolDialog", "Zenith angle (in degrees) = 90 - altitude angle", 0));
#endif // QT_NO_TOOLTIP
        sunZenithSpinBox->setSuffix(QApplication::translate("RasterizeToolDialog", " deg.", 0));
        label_18->setText(QApplication::translate("RasterizeToolDialog", "Sun azimuth", 0));
#ifndef QT_NO_TOOLTIP
        sunAzimuthSpinBox->setToolTip(QApplication::translate("RasterizeToolDialog", "Azimuth angle (in degrees)", 0));
#endif // QT_NO_TOOLTIP
        sunAzimuthSpinBox->setSuffix(QApplication::translate("RasterizeToolDialog", " deg.", 0));
        generateHillshadePushButton->setText(QApplication::translate("RasterizeToolDialog", "Generate", 0));
        tabWidget->setTabText(tabWidget->indexOf(hillshadeTab), QApplication::translate("RasterizeToolDialog", "Hillshade", 0));
        label_19->setText(QApplication::translate("RasterizeToolDialog", "Volume", 0));
        label_20->setText(QApplication::translate("RasterizeToolDialog", "Non empty cells", 0));
        tabWidget->setTabText(tabWidget->indexOf(volumeTab), QApplication::translate("RasterizeToolDialog", "Volume", 0));
    } // retranslateUi

};

namespace Ui {
    class RasterizeToolDialog: public Ui_RasterizeToolDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RASTERIZEDLG_H
