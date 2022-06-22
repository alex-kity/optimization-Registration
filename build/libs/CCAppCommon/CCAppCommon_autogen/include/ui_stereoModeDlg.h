/********************************************************************************
** Form generated from reading UI file 'stereoModeDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEREOMODEDLG_H
#define UI_STEREOMODEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StereoModeDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *glassTypeComboBox;
    QTextEdit *warningTextEdit;
    QGroupBox *paramsGroupBox;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QSpinBox *screenWidthSpinBox;
    QLabel *label_5;
    QLabel *label_6;
    QSpinBox *eyeDistanceSpinBox;
    QSpinBox *screenDiistanceSpinBox;
    QLabel *label_2;
    QSlider *stereoStrengthHorizontalSlider;
    QCheckBox *autoFocalCheckBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *StereoModeDialog)
    {
        if (StereoModeDialog->objectName().isEmpty())
            StereoModeDialog->setObjectName(QStringLiteral("StereoModeDialog"));
        StereoModeDialog->resize(600, 600);
        verticalLayout_2 = new QVBoxLayout(StereoModeDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(StereoModeDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        glassTypeComboBox = new QComboBox(StereoModeDialog);
        QIcon icon;
        icon.addFile(QStringLiteral(":/CC/images/ccStereo.png"), QSize(), QIcon::Normal, QIcon::Off);
        glassTypeComboBox->addItem(icon, QString());
        glassTypeComboBox->addItem(icon, QString());
        glassTypeComboBox->addItem(icon, QString());
        glassTypeComboBox->addItem(icon, QString());
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/CC/images/nvidia.png"), QSize(), QIcon::Normal, QIcon::Off);
        glassTypeComboBox->addItem(icon1, QString());
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/CC/images/oculus.png"), QSize(), QIcon::Normal, QIcon::Off);
        glassTypeComboBox->addItem(icon2, QString());
        glassTypeComboBox->addItem(icon, QString());
        glassTypeComboBox->setObjectName(QStringLiteral("glassTypeComboBox"));

        horizontalLayout->addWidget(glassTypeComboBox);


        verticalLayout_2->addLayout(horizontalLayout);

        warningTextEdit = new QTextEdit(StereoModeDialog);
        warningTextEdit->setObjectName(QStringLiteral("warningTextEdit"));

        verticalLayout_2->addWidget(warningTextEdit);

        paramsGroupBox = new QGroupBox(StereoModeDialog);
        paramsGroupBox->setObjectName(QStringLiteral("paramsGroupBox"));
        verticalLayout = new QVBoxLayout(paramsGroupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(paramsGroupBox);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        screenWidthSpinBox = new QSpinBox(frame);
        screenWidthSpinBox->setObjectName(QStringLiteral("screenWidthSpinBox"));
        screenWidthSpinBox->setMinimum(10);
        screenWidthSpinBox->setMaximum(100000);
        screenWidthSpinBox->setSingleStep(10);

        gridLayout->addWidget(screenWidthSpinBox, 0, 1, 1, 1);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        eyeDistanceSpinBox = new QSpinBox(frame);
        eyeDistanceSpinBox->setObjectName(QStringLiteral("eyeDistanceSpinBox"));
        eyeDistanceSpinBox->setMinimum(1);
        eyeDistanceSpinBox->setMaximum(1000);
        eyeDistanceSpinBox->setValue(64);

        gridLayout->addWidget(eyeDistanceSpinBox, 2, 1, 1, 1);

        screenDiistanceSpinBox = new QSpinBox(frame);
        screenDiistanceSpinBox->setObjectName(QStringLiteral("screenDiistanceSpinBox"));
        screenDiistanceSpinBox->setMinimum(10);
        screenDiistanceSpinBox->setMaximum(1000000);
        screenDiistanceSpinBox->setSingleStep(50);
        screenDiistanceSpinBox->setValue(800);

        gridLayout->addWidget(screenDiistanceSpinBox, 1, 1, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        stereoStrengthHorizontalSlider = new QSlider(frame);
        stereoStrengthHorizontalSlider->setObjectName(QStringLiteral("stereoStrengthHorizontalSlider"));
        stereoStrengthHorizontalSlider->setMinimum(1);
        stereoStrengthHorizontalSlider->setMaximum(100);
        stereoStrengthHorizontalSlider->setValue(50);
        stereoStrengthHorizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(stereoStrengthHorizontalSlider, 3, 1, 1, 1);


        verticalLayout->addWidget(frame);

        autoFocalCheckBox = new QCheckBox(paramsGroupBox);
        autoFocalCheckBox->setObjectName(QStringLiteral("autoFocalCheckBox"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(autoFocalCheckBox->sizePolicy().hasHeightForWidth());
        autoFocalCheckBox->setSizePolicy(sizePolicy);
        autoFocalCheckBox->setChecked(true);

        verticalLayout->addWidget(autoFocalCheckBox);


        verticalLayout_2->addWidget(paramsGroupBox);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(StereoModeDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(StereoModeDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), StereoModeDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), StereoModeDialog, SLOT(reject()));

        glassTypeComboBox->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(StereoModeDialog);
    } // setupUi

    void retranslateUi(QDialog *StereoModeDialog)
    {
        StereoModeDialog->setWindowTitle(QApplication::translate("StereoModeDialog", "Stereo mode", 0));
        label->setText(QApplication::translate("StereoModeDialog", "Glasses", 0));
        glassTypeComboBox->setItemText(0, QApplication::translate("StereoModeDialog", "Red-Blue", 0));
        glassTypeComboBox->setItemText(1, QApplication::translate("StereoModeDialog", "Blue-Red", 0));
        glassTypeComboBox->setItemText(2, QApplication::translate("StereoModeDialog", "Red-Cyan", 0));
        glassTypeComboBox->setItemText(3, QApplication::translate("StereoModeDialog", "Cyan-Red", 0));
        glassTypeComboBox->setItemText(4, QApplication::translate("StereoModeDialog", "NVidia Vision", 0));
        glassTypeComboBox->setItemText(5, QApplication::translate("StereoModeDialog", "Oculus", 0));
        glassTypeComboBox->setItemText(6, QApplication::translate("StereoModeDialog", "Generic stereo display", 0));

        warningTextEdit->setHtml(QApplication::translate("StereoModeDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">To make this mode work properly make sure that:</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- the NVidia Vision IR emitter is plugged and enabled (dim green light)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- 3D stereo mode is activated in the NVidia Control Pannel</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"
                        "\">- the screen frequency is set to 120Hz</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- the glasses are switched on</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Note: the current 3D view will be automatically displayed in exclusive full screen mode - press F11 to quit this mode</p></body></html>", 0));
        paramsGroupBox->setTitle(QApplication::translate("StereoModeDialog", "Parameters", 0));
        label_4->setText(QApplication::translate("StereoModeDialog", "Screen width", 0));
        screenWidthSpinBox->setSuffix(QApplication::translate("StereoModeDialog", " mm", 0));
        label_5->setText(QApplication::translate("StereoModeDialog", "Screen distance", 0));
        label_6->setText(QApplication::translate("StereoModeDialog", "Interocular distance", 0));
        eyeDistanceSpinBox->setSuffix(QApplication::translate("StereoModeDialog", " mm", 0));
        screenDiistanceSpinBox->setSuffix(QApplication::translate("StereoModeDialog", " mm", 0));
        label_2->setText(QApplication::translate("StereoModeDialog", "Stereo strength", 0));
        autoFocalCheckBox->setText(QApplication::translate("StereoModeDialog", "auto set F.O.V.", 0));
    } // retranslateUi

};

namespace Ui {
    class StereoModeDialog: public Ui_StereoModeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEREOMODEDLG_H
