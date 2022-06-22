/********************************************************************************
** Form generated from reading UI file 'sectionExtractionSubDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECTIONEXTRACTIONSUBDLG_H
#define UI_SECTIONEXTRACTIONSUBDLG_H

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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SectionExtractionSubDlg
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QFormLayout *formLayout_2;
    QLabel *label_5;
    QLabel *activeSectionsLabel;
    QLabel *label;
    QDoubleSpinBox *thicknessDoubleSpinBox;
    QGroupBox *extractCloudsGroupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QGroupBox *extractEnvelopesGroupBox;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_2;
    QFormLayout *formLayout;
    QLabel *label_3;
    QComboBox *envelopeTypeComboBox;
    QLabel *label_2;
    QDoubleSpinBox *maxEdgeLengthDoubleSpinBox;
    QCheckBox *multiPassCheckBox;
    QCheckBox *splitEnvelopeCheckBox;
    QCheckBox *debugModeCheckBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SectionExtractionSubDlg)
    {
        if (SectionExtractionSubDlg->objectName().isEmpty())
            SectionExtractionSubDlg->setObjectName(QStringLiteral("SectionExtractionSubDlg"));
        SectionExtractionSubDlg->resize(329, 392);
        verticalLayout = new QVBoxLayout(SectionExtractionSubDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(SectionExtractionSubDlg);
        frame->setObjectName(QStringLiteral("frame"));
        formLayout_2 = new QFormLayout(frame);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_5);

        activeSectionsLabel = new QLabel(frame);
        activeSectionsLabel->setObjectName(QStringLiteral("activeSectionsLabel"));
        activeSectionsLabel->setText(QStringLiteral("0"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, activeSectionsLabel);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label);

        thicknessDoubleSpinBox = new QDoubleSpinBox(frame);
        thicknessDoubleSpinBox->setObjectName(QStringLiteral("thicknessDoubleSpinBox"));
        thicknessDoubleSpinBox->setDecimals(6);
        thicknessDoubleSpinBox->setMaximum(1e+09);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, thicknessDoubleSpinBox);


        verticalLayout->addWidget(frame);

        extractCloudsGroupBox = new QGroupBox(SectionExtractionSubDlg);
        extractCloudsGroupBox->setObjectName(QStringLiteral("extractCloudsGroupBox"));
        extractCloudsGroupBox->setCheckable(true);
        extractCloudsGroupBox->setChecked(false);
        verticalLayout_2 = new QVBoxLayout(extractCloudsGroupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_4 = new QLabel(extractCloudsGroupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);


        verticalLayout->addWidget(extractCloudsGroupBox);

        extractEnvelopesGroupBox = new QGroupBox(SectionExtractionSubDlg);
        extractEnvelopesGroupBox->setObjectName(QStringLiteral("extractEnvelopesGroupBox"));
        extractEnvelopesGroupBox->setCheckable(true);
        extractEnvelopesGroupBox->setChecked(true);
        verticalLayout_3 = new QVBoxLayout(extractEnvelopesGroupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        frame_2 = new QFrame(extractEnvelopesGroupBox);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMinimumSize(QSize(0, 50));
        formLayout = new QFormLayout(frame_2);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        envelopeTypeComboBox = new QComboBox(frame_2);
        envelopeTypeComboBox->setObjectName(QStringLiteral("envelopeTypeComboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, envelopeTypeComboBox);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        maxEdgeLengthDoubleSpinBox = new QDoubleSpinBox(frame_2);
        maxEdgeLengthDoubleSpinBox->setObjectName(QStringLiteral("maxEdgeLengthDoubleSpinBox"));
        maxEdgeLengthDoubleSpinBox->setDecimals(6);
        maxEdgeLengthDoubleSpinBox->setMaximum(1e+09);

        formLayout->setWidget(1, QFormLayout::FieldRole, maxEdgeLengthDoubleSpinBox);


        verticalLayout_3->addWidget(frame_2);

        multiPassCheckBox = new QCheckBox(extractEnvelopesGroupBox);
        multiPassCheckBox->setObjectName(QStringLiteral("multiPassCheckBox"));

        verticalLayout_3->addWidget(multiPassCheckBox);

        splitEnvelopeCheckBox = new QCheckBox(extractEnvelopesGroupBox);
        splitEnvelopeCheckBox->setObjectName(QStringLiteral("splitEnvelopeCheckBox"));

        verticalLayout_3->addWidget(splitEnvelopeCheckBox);

        debugModeCheckBox = new QCheckBox(extractEnvelopesGroupBox);
        debugModeCheckBox->setObjectName(QStringLiteral("debugModeCheckBox"));

        verticalLayout_3->addWidget(debugModeCheckBox);


        verticalLayout->addWidget(extractEnvelopesGroupBox);

        verticalSpacer = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(SectionExtractionSubDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SectionExtractionSubDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), SectionExtractionSubDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SectionExtractionSubDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(SectionExtractionSubDlg);
    } // setupUi

    void retranslateUi(QDialog *SectionExtractionSubDlg)
    {
        SectionExtractionSubDlg->setWindowTitle(QApplication::translate("SectionExtractionSubDlg", "Extract Sections", 0));
        label_5->setText(QApplication::translate("SectionExtractionSubDlg", "Active section(s)", 0));
        label->setText(QApplication::translate("SectionExtractionSubDlg", "Sections thickness", 0));
#ifndef QT_NO_TOOLTIP
        thicknessDoubleSpinBox->setToolTip(QApplication::translate("SectionExtractionSubDlg", "Thickness of each section (depends on the cloud density)", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        extractCloudsGroupBox->setToolTip(QApplication::translate("SectionExtractionSubDlg", "To extract each section as a point cloud", 0));
#endif // QT_NO_TOOLTIP
        extractCloudsGroupBox->setTitle(QApplication::translate("SectionExtractionSubDlg", "Extract section cloud(s)", 0));
        label_4->setText(QApplication::translate("SectionExtractionSubDlg", "No parameter", 0));
#ifndef QT_NO_TOOLTIP
        extractEnvelopesGroupBox->setToolTip(QApplication::translate("SectionExtractionSubDlg", "To extract the contour of each section as a polyline", 0));
#endif // QT_NO_TOOLTIP
        extractEnvelopesGroupBox->setTitle(QApplication::translate("SectionExtractionSubDlg", "Extract section profile(s)", 0));
        label_3->setText(QApplication::translate("SectionExtractionSubDlg", "type", 0));
        envelopeTypeComboBox->clear();
        envelopeTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("SectionExtractionSubDlg", "Lower", 0)
         << QApplication::translate("SectionExtractionSubDlg", "Upper", 0)
         << QApplication::translate("SectionExtractionSubDlg", "Both", 0)
        );
#ifndef QT_NO_TOOLTIP
        envelopeTypeComboBox->setToolTip(QApplication::translate("SectionExtractionSubDlg", "Section type (lower or upper part, or both)", 0));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("SectionExtractionSubDlg", "max edge length", 0));
#ifndef QT_NO_TOOLTIP
        maxEdgeLengthDoubleSpinBox->setToolTip(QApplication::translate("SectionExtractionSubDlg", "Max output polyline edge length (the smaller, the closer to the points the contour will be).\n"
"Warning: if 0, generates the convex hull.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        multiPassCheckBox->setToolTip(QApplication::translate("SectionExtractionSubDlg", "Multi-pass process where longer edges may be temporarily created to obtain a better fit... or a worst one ;)", 0));
#endif // QT_NO_TOOLTIP
        multiPassCheckBox->setText(QApplication::translate("SectionExtractionSubDlg", "multi-pass", 0));
#ifndef QT_NO_TOOLTIP
        splitEnvelopeCheckBox->setToolTip(QApplication::translate("SectionExtractionSubDlg", "split the generated profile(s) in smaller parts to avoid creating too long edges (10 times the specified max edge length).\n"
"Warning: may not be compatible with Mascaret export.", 0));
#endif // QT_NO_TOOLTIP
        splitEnvelopeCheckBox->setText(QApplication::translate("SectionExtractionSubDlg", "split profile on longer edges", 0));
#ifndef QT_NO_TOOLTIP
        debugModeCheckBox->setToolTip(QApplication::translate("SectionExtractionSubDlg", "Display a dialog with step-by-step execution of the algorithm (debug mode - very slow)", 0));
#endif // QT_NO_TOOLTIP
        debugModeCheckBox->setText(QApplication::translate("SectionExtractionSubDlg", "visual debug mode", 0));
    } // retranslateUi

};

namespace Ui {
    class SectionExtractionSubDlg: public Ui_SectionExtractionSubDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECTIONEXTRACTIONSUBDLG_H
