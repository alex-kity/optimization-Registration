/********************************************************************************
** Form generated from reading UI file 'clippingBoxRepeatDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIPPINGBOXREPEATDLG_H
#define UI_CLIPPINGBOXREPEATDLG_H

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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ClippingBoxRepeatDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *repeatDimGroupBox;
    QHBoxLayout *horizontalLayout;
    QCheckBox *xRepeatCheckBox;
    QCheckBox *yRepeatCheckBox;
    QCheckBox *zRepeatCheckBox;
    QGroupBox *extractSliceEntitiesGroupBox;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *randomColorCheckBox;
    QGroupBox *extractEnvelopesGroupBox;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout;
    QLabel *label_3;
    QComboBox *envelopeTypeComboBox;
    QLabel *label_2;
    QDoubleSpinBox *maxEnvelopeEdgeLengthDoubleSpinBox;
    QCheckBox *multiPassEnvelopeCheckBox;
    QCheckBox *envProjectPointsOnBestFitCheckBox;
    QCheckBox *splitEnvelopeCheckBox;
    QCheckBox *envDebugModeCheckBox;
    QGroupBox *extractLevelSetGroupBox;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QDoubleSpinBox *lsGridStepDoubleSpinBox;
    QLabel *label_11;
    QSpinBox *minLSVertexCountSpinBox;
    QGroupBox *otherOptionsGroupBox;
    QFormLayout *formLayout_3;
    QLabel *label;
    QDoubleSpinBox *gapDoubleSpinBox;
    QLabel *label_5;
    QComboBox *groupByTypeComboBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ClippingBoxRepeatDlg)
    {
        if (ClippingBoxRepeatDlg->objectName().isEmpty())
            ClippingBoxRepeatDlg->setObjectName(QStringLiteral("ClippingBoxRepeatDlg"));
        ClippingBoxRepeatDlg->resize(400, 550);
        verticalLayout = new QVBoxLayout(ClippingBoxRepeatDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        repeatDimGroupBox = new QGroupBox(ClippingBoxRepeatDlg);
        repeatDimGroupBox->setObjectName(QStringLiteral("repeatDimGroupBox"));
        horizontalLayout = new QHBoxLayout(repeatDimGroupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        xRepeatCheckBox = new QCheckBox(repeatDimGroupBox);
        xRepeatCheckBox->setObjectName(QStringLiteral("xRepeatCheckBox"));
        xRepeatCheckBox->setStyleSheet(QLatin1String("background-color: red;\n"
"color: white;"));
        xRepeatCheckBox->setText(QStringLiteral("X"));

        horizontalLayout->addWidget(xRepeatCheckBox);

        yRepeatCheckBox = new QCheckBox(repeatDimGroupBox);
        yRepeatCheckBox->setObjectName(QStringLiteral("yRepeatCheckBox"));
        yRepeatCheckBox->setStyleSheet(QLatin1String("background-color: green;\n"
"color: white;"));
        yRepeatCheckBox->setText(QStringLiteral("Y"));

        horizontalLayout->addWidget(yRepeatCheckBox);

        zRepeatCheckBox = new QCheckBox(repeatDimGroupBox);
        zRepeatCheckBox->setObjectName(QStringLiteral("zRepeatCheckBox"));
        zRepeatCheckBox->setStyleSheet(QLatin1String("background-color: blue;\n"
"color: white;"));
        zRepeatCheckBox->setText(QStringLiteral("Z"));
        zRepeatCheckBox->setChecked(true);

        horizontalLayout->addWidget(zRepeatCheckBox);


        verticalLayout->addWidget(repeatDimGroupBox);

        extractSliceEntitiesGroupBox = new QGroupBox(ClippingBoxRepeatDlg);
        extractSliceEntitiesGroupBox->setObjectName(QStringLiteral("extractSliceEntitiesGroupBox"));
        extractSliceEntitiesGroupBox->setMinimumSize(QSize(0, 30));
        extractSliceEntitiesGroupBox->setCheckable(true);
        verticalLayout_4 = new QVBoxLayout(extractSliceEntitiesGroupBox);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        randomColorCheckBox = new QCheckBox(extractSliceEntitiesGroupBox);
        randomColorCheckBox->setObjectName(QStringLiteral("randomColorCheckBox"));

        verticalLayout_4->addWidget(randomColorCheckBox);


        verticalLayout->addWidget(extractSliceEntitiesGroupBox);

        extractEnvelopesGroupBox = new QGroupBox(ClippingBoxRepeatDlg);
        extractEnvelopesGroupBox->setObjectName(QStringLiteral("extractEnvelopesGroupBox"));
        extractEnvelopesGroupBox->setCheckable(true);
        extractEnvelopesGroupBox->setChecked(false);
        verticalLayout_3 = new QVBoxLayout(extractEnvelopesGroupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_3 = new QLabel(extractEnvelopesGroupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        envelopeTypeComboBox = new QComboBox(extractEnvelopesGroupBox);
        envelopeTypeComboBox->setObjectName(QStringLiteral("envelopeTypeComboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, envelopeTypeComboBox);

        label_2 = new QLabel(extractEnvelopesGroupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        maxEnvelopeEdgeLengthDoubleSpinBox = new QDoubleSpinBox(extractEnvelopesGroupBox);
        maxEnvelopeEdgeLengthDoubleSpinBox->setObjectName(QStringLiteral("maxEnvelopeEdgeLengthDoubleSpinBox"));
        maxEnvelopeEdgeLengthDoubleSpinBox->setDecimals(6);
        maxEnvelopeEdgeLengthDoubleSpinBox->setMaximum(1e+09);

        formLayout->setWidget(1, QFormLayout::FieldRole, maxEnvelopeEdgeLengthDoubleSpinBox);


        verticalLayout_3->addLayout(formLayout);

        multiPassEnvelopeCheckBox = new QCheckBox(extractEnvelopesGroupBox);
        multiPassEnvelopeCheckBox->setObjectName(QStringLiteral("multiPassEnvelopeCheckBox"));

        verticalLayout_3->addWidget(multiPassEnvelopeCheckBox);

        envProjectPointsOnBestFitCheckBox = new QCheckBox(extractEnvelopesGroupBox);
        envProjectPointsOnBestFitCheckBox->setObjectName(QStringLiteral("envProjectPointsOnBestFitCheckBox"));

        verticalLayout_3->addWidget(envProjectPointsOnBestFitCheckBox);

        splitEnvelopeCheckBox = new QCheckBox(extractEnvelopesGroupBox);
        splitEnvelopeCheckBox->setObjectName(QStringLiteral("splitEnvelopeCheckBox"));

        verticalLayout_3->addWidget(splitEnvelopeCheckBox);

        envDebugModeCheckBox = new QCheckBox(extractEnvelopesGroupBox);
        envDebugModeCheckBox->setObjectName(QStringLiteral("envDebugModeCheckBox"));

        verticalLayout_3->addWidget(envDebugModeCheckBox);


        verticalLayout->addWidget(extractEnvelopesGroupBox);

        extractLevelSetGroupBox = new QGroupBox(ClippingBoxRepeatDlg);
        extractLevelSetGroupBox->setObjectName(QStringLiteral("extractLevelSetGroupBox"));
        extractLevelSetGroupBox->setCheckable(true);
        extractLevelSetGroupBox->setChecked(false);
        formLayout_2 = new QFormLayout(extractLevelSetGroupBox);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_4 = new QLabel(extractLevelSetGroupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        lsGridStepDoubleSpinBox = new QDoubleSpinBox(extractLevelSetGroupBox);
        lsGridStepDoubleSpinBox->setObjectName(QStringLiteral("lsGridStepDoubleSpinBox"));
        lsGridStepDoubleSpinBox->setDecimals(6);
        lsGridStepDoubleSpinBox->setMinimum(1e-06);
        lsGridStepDoubleSpinBox->setMaximum(100000);
        lsGridStepDoubleSpinBox->setValue(1);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lsGridStepDoubleSpinBox);

        label_11 = new QLabel(extractLevelSetGroupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_11);

        minLSVertexCountSpinBox = new QSpinBox(extractLevelSetGroupBox);
        minLSVertexCountSpinBox->setObjectName(QStringLiteral("minLSVertexCountSpinBox"));
        minLSVertexCountSpinBox->setMinimum(3);
        minLSVertexCountSpinBox->setMaximum(10000000);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, minLSVertexCountSpinBox);


        verticalLayout->addWidget(extractLevelSetGroupBox);

        otherOptionsGroupBox = new QGroupBox(ClippingBoxRepeatDlg);
        otherOptionsGroupBox->setObjectName(QStringLiteral("otherOptionsGroupBox"));
        formLayout_3 = new QFormLayout(otherOptionsGroupBox);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label = new QLabel(otherOptionsGroupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label);

        gapDoubleSpinBox = new QDoubleSpinBox(otherOptionsGroupBox);
        gapDoubleSpinBox->setObjectName(QStringLiteral("gapDoubleSpinBox"));
        gapDoubleSpinBox->setDecimals(6);
        gapDoubleSpinBox->setMaximum(1e+09);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, gapDoubleSpinBox);

        label_5 = new QLabel(otherOptionsGroupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_5);

        groupByTypeComboBox = new QComboBox(otherOptionsGroupBox);
        groupByTypeComboBox->setObjectName(QStringLiteral("groupByTypeComboBox"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, groupByTypeComboBox);


        verticalLayout->addWidget(otherOptionsGroupBox);

        verticalSpacer = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(ClippingBoxRepeatDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ClippingBoxRepeatDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), ClippingBoxRepeatDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ClippingBoxRepeatDlg, SLOT(reject()));

        envelopeTypeComboBox->setCurrentIndex(2);
        groupByTypeComboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(ClippingBoxRepeatDlg);
    } // setupUi

    void retranslateUi(QDialog *ClippingBoxRepeatDlg)
    {
        ClippingBoxRepeatDlg->setWindowTitle(QApplication::translate("ClippingBoxRepeatDlg", "Repeat", 0));
#ifndef QT_NO_TOOLTIP
        repeatDimGroupBox->setToolTip(QApplication::translate("ClippingBoxRepeatDlg", "The segmentation process will be repeated along the following dimensions (+/-)", 0));
#endif // QT_NO_TOOLTIP
        repeatDimGroupBox->setTitle(QApplication::translate("ClippingBoxRepeatDlg", "Repeat dimensions", 0));
        extractSliceEntitiesGroupBox->setTitle(QApplication::translate("ClippingBoxRepeatDlg", "Extract slice cloud(s) or mesh(es)", 0));
#ifndef QT_NO_TOOLTIP
        randomColorCheckBox->setToolTip(QApplication::translate("ClippingBoxRepeatDlg", "If checked, a random color will be assigned to each slice (warning: will overwrite any existing color!)", 0));
#endif // QT_NO_TOOLTIP
        randomColorCheckBox->setText(QApplication::translate("ClippingBoxRepeatDlg", "random colors per slice (will overwrite existing colors!)", 0));
#ifndef QT_NO_TOOLTIP
        extractEnvelopesGroupBox->setToolTip(QApplication::translate("ClippingBoxRepeatDlg", "Check that option if you wish to extract the envelope of each slice", 0));
#endif // QT_NO_TOOLTIP
        extractEnvelopesGroupBox->setTitle(QApplication::translate("ClippingBoxRepeatDlg", "Extract envelope(s)", 0));
        label_3->setText(QApplication::translate("ClippingBoxRepeatDlg", "Envelope type", 0));
        envelopeTypeComboBox->clear();
        envelopeTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("ClippingBoxRepeatDlg", "Lower", 0)
         << QApplication::translate("ClippingBoxRepeatDlg", "Upper", 0)
         << QApplication::translate("ClippingBoxRepeatDlg", "Full", 0)
        );
#ifndef QT_NO_TOOLTIP
        envelopeTypeComboBox->setToolTip(QApplication::translate("ClippingBoxRepeatDlg", "Section type (lower or upper part, or both)", 0));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("ClippingBoxRepeatDlg", "Max edge length", 0));
#ifndef QT_NO_TOOLTIP
        maxEnvelopeEdgeLengthDoubleSpinBox->setToolTip(QApplication::translate("ClippingBoxRepeatDlg", "Max edge length (if 0, generates a unique and closed contour = convex hull)", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        multiPassEnvelopeCheckBox->setToolTip(QApplication::translate("ClippingBoxRepeatDlg", "Multi-pass process where longer edges may be temporarily created to obtain a better fit... or a worst one ;)", 0));
#endif // QT_NO_TOOLTIP
        multiPassEnvelopeCheckBox->setText(QApplication::translate("ClippingBoxRepeatDlg", "multi-pass", 0));
#ifndef QT_NO_TOOLTIP
        envProjectPointsOnBestFitCheckBox->setToolTip(QApplication::translate("ClippingBoxRepeatDlg", "Before extracting the contour, points can be projected along the repeat dimension (if only one is defined) or on the best fit plane", 0));
#endif // QT_NO_TOOLTIP
        envProjectPointsOnBestFitCheckBox->setText(QApplication::translate("ClippingBoxRepeatDlg", "project slice(s) points on their best fit plane", 0));
#ifndef QT_NO_TOOLTIP
        splitEnvelopeCheckBox->setToolTip(QApplication::translate("ClippingBoxRepeatDlg", "split the generated contour(s) in smaller parts to avoid creating edges longer than the specified max edge length.", 0));
#endif // QT_NO_TOOLTIP
        splitEnvelopeCheckBox->setText(QApplication::translate("ClippingBoxRepeatDlg", "split envelope(s) on longer edges", 0));
#ifndef QT_NO_TOOLTIP
        envDebugModeCheckBox->setToolTip(QApplication::translate("ClippingBoxRepeatDlg", "Display a dialog with step-by-step execution of the algorithm (debug mode - very slow)", 0));
#endif // QT_NO_TOOLTIP
        envDebugModeCheckBox->setText(QApplication::translate("ClippingBoxRepeatDlg", "visual debug mode", 0));
#ifndef QT_NO_TOOLTIP
        extractLevelSetGroupBox->setToolTip(QApplication::translate("ClippingBoxRepeatDlg", "Extract the point contours (via a rasterization process)", 0));
#endif // QT_NO_TOOLTIP
        extractLevelSetGroupBox->setTitle(QApplication::translate("ClippingBoxRepeatDlg", "Extract contours", 0));
        label_4->setText(QApplication::translate("ClippingBoxRepeatDlg", "Grid step", 0));
        label_11->setText(QApplication::translate("ClippingBoxRepeatDlg", "Min. vertex count", 0));
#ifndef QT_NO_TOOLTIP
        minLSVertexCountSpinBox->setToolTip(QApplication::translate("ClippingBoxRepeatDlg", "Min vertex count per iso-line (to ignore the smallest ones)", 0));
#endif // QT_NO_TOOLTIP
        otherOptionsGroupBox->setTitle(QApplication::translate("ClippingBoxRepeatDlg", "Other options", 0));
        label->setText(QApplication::translate("ClippingBoxRepeatDlg", "Gap", 0));
#ifndef QT_NO_TOOLTIP
        gapDoubleSpinBox->setToolTip(QApplication::translate("ClippingBoxRepeatDlg", "Gap between the slices", 0));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("ClippingBoxRepeatDlg", "Group generated entities by", 0));
        groupByTypeComboBox->clear();
        groupByTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("ClippingBoxRepeatDlg", "Type", 0)
         << QApplication::translate("ClippingBoxRepeatDlg", "Origin entity", 0)
         << QApplication::translate("ClippingBoxRepeatDlg", "Slice", 0)
         << QApplication::translate("ClippingBoxRepeatDlg", "Origin entity, then slice", 0)
         << QApplication::translate("ClippingBoxRepeatDlg", "Slice, then origin entity", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class ClippingBoxRepeatDlg: public Ui_ClippingBoxRepeatDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIPPINGBOXREPEATDLG_H
