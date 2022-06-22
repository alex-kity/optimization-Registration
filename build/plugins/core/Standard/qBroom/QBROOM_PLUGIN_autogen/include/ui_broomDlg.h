/********************************************************************************
** Form generated from reading UI file 'broomDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BROOMDLG_H
#define UI_BROOMDLG_H

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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BroomDialog
{
public:
    QHBoxLayout *horizontalLayout_2;
    QFrame *leftFrame;
    QVBoxLayout *verticalLayout;
    QLabel *caeLogoLabel;
    QGroupBox *broomGroupBox;
    QVBoxLayout *verticalLayout_3;
    QPushButton *repositionPushButton;
    QPushButton *automatePushButton;
    QCheckBox *stickCheckBox;
    QCheckBox *animateAutomationCheckBox;
    QGroupBox *broomDimGroupBox;
    QFormLayout *formLayout;
    QLabel *label_3;
    QDoubleSpinBox *broomLengthDoubleSpinBox;
    QLabel *label;
    QDoubleSpinBox *broomWidthDoubleSpinBox;
    QLabel *label_2;
    QDoubleSpinBox *broomThicknessDoubleSpinBox;
    QGroupBox *cleanAreaGroupBox;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *cleanHeightDoubleSpinBox;
    QComboBox *selectionModeComboBox;
    QPushButton *undoPushButton;
    QPushButton *undo10PushButton;
    QGroupBox *viewGroupBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *topViewToolButton;
    QToolButton *frontViewToolButton;
    QToolButton *leftViewToolButton;
    QToolButton *backViewToolButton;
    QToolButton *rightViewToolButton;
    QToolButton *bottomViewToolButton;
    QSpacerItem *horizontalSpacer_2;
    QFrame *lostTrackFrame;
    QVBoxLayout *verticalLayout_2;
    QLabel *imageLabel;
    QLabel *lostTrackLabel;
    QSpacerItem *verticalSpacer;
    QCheckBox *removeSelectedPointsCheckBox;
    QFrame *buttonsFrame;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *applyPushButton;
    QPushButton *validatePushButton;
    QPushButton *cancelPushButton;
    QFrame *viewFrame;

    void setupUi(QDialog *BroomDialog)
    {
        if (BroomDialog->objectName().isEmpty())
            BroomDialog->setObjectName(QStringLiteral("BroomDialog"));
        BroomDialog->resize(1093, 766);
        QIcon icon;
        icon.addFile(QStringLiteral(":/CC/plugin/qBroom/images/qBroom.png"), QSize(), QIcon::Normal, QIcon::Off);
        BroomDialog->setWindowIcon(icon);
        BroomDialog->setStyleSheet(QStringLiteral("QDialog{ background-color:white }"));
        horizontalLayout_2 = new QHBoxLayout(BroomDialog);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        leftFrame = new QFrame(BroomDialog);
        leftFrame->setObjectName(QStringLiteral("leftFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leftFrame->sizePolicy().hasHeightForWidth());
        leftFrame->setSizePolicy(sizePolicy);
        leftFrame->setMinimumSize(QSize(270, 0));
        leftFrame->setMaximumSize(QSize(270, 16777215));
        verticalLayout = new QVBoxLayout(leftFrame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        caeLogoLabel = new QLabel(leftFrame);
        caeLogoLabel->setObjectName(QStringLiteral("caeLogoLabel"));
        caeLogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/CC/plugin/qBroom/images/cea_logo_small.jpg")));
        caeLogoLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(caeLogoLabel);

        broomGroupBox = new QGroupBox(leftFrame);
        broomGroupBox->setObjectName(QStringLiteral("broomGroupBox"));
        broomGroupBox->setFlat(true);
        verticalLayout_3 = new QVBoxLayout(broomGroupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        repositionPushButton = new QPushButton(broomGroupBox);
        repositionPushButton->setObjectName(QStringLiteral("repositionPushButton"));

        verticalLayout_3->addWidget(repositionPushButton);

        automatePushButton = new QPushButton(broomGroupBox);
        automatePushButton->setObjectName(QStringLiteral("automatePushButton"));
        automatePushButton->setEnabled(false);

        verticalLayout_3->addWidget(automatePushButton);

        stickCheckBox = new QCheckBox(broomGroupBox);
        stickCheckBox->setObjectName(QStringLiteral("stickCheckBox"));
        stickCheckBox->setChecked(true);

        verticalLayout_3->addWidget(stickCheckBox);

        animateAutomationCheckBox = new QCheckBox(broomGroupBox);
        animateAutomationCheckBox->setObjectName(QStringLiteral("animateAutomationCheckBox"));

        verticalLayout_3->addWidget(animateAutomationCheckBox);


        verticalLayout->addWidget(broomGroupBox);

        broomDimGroupBox = new QGroupBox(leftFrame);
        broomDimGroupBox->setObjectName(QStringLiteral("broomDimGroupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(broomDimGroupBox->sizePolicy().hasHeightForWidth());
        broomDimGroupBox->setSizePolicy(sizePolicy1);
        broomDimGroupBox->setFlat(true);
        formLayout = new QFormLayout(broomDimGroupBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_3 = new QLabel(broomDimGroupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        broomLengthDoubleSpinBox = new QDoubleSpinBox(broomDimGroupBox);
        broomLengthDoubleSpinBox->setObjectName(QStringLiteral("broomLengthDoubleSpinBox"));
        broomLengthDoubleSpinBox->setDecimals(3);
        broomLengthDoubleSpinBox->setMinimum(-1e+06);
        broomLengthDoubleSpinBox->setMaximum(1e+06);
        broomLengthDoubleSpinBox->setValue(1);

        formLayout->setWidget(0, QFormLayout::FieldRole, broomLengthDoubleSpinBox);

        label = new QLabel(broomDimGroupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        broomWidthDoubleSpinBox = new QDoubleSpinBox(broomDimGroupBox);
        broomWidthDoubleSpinBox->setObjectName(QStringLiteral("broomWidthDoubleSpinBox"));
        broomWidthDoubleSpinBox->setSuffix(QStringLiteral("%"));
        broomWidthDoubleSpinBox->setDecimals(1);
        broomWidthDoubleSpinBox->setMinimum(1);
        broomWidthDoubleSpinBox->setMaximum(100000);
        broomWidthDoubleSpinBox->setValue(20);

        formLayout->setWidget(1, QFormLayout::FieldRole, broomWidthDoubleSpinBox);

        label_2 = new QLabel(broomDimGroupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        broomThicknessDoubleSpinBox = new QDoubleSpinBox(broomDimGroupBox);
        broomThicknessDoubleSpinBox->setObjectName(QStringLiteral("broomThicknessDoubleSpinBox"));
        broomThicknessDoubleSpinBox->setSuffix(QStringLiteral("%"));
        broomThicknessDoubleSpinBox->setDecimals(1);
        broomThicknessDoubleSpinBox->setMinimum(1);
        broomThicknessDoubleSpinBox->setMaximum(100000);
        broomThicknessDoubleSpinBox->setValue(5);

        formLayout->setWidget(2, QFormLayout::FieldRole, broomThicknessDoubleSpinBox);


        verticalLayout->addWidget(broomDimGroupBox);

        cleanAreaGroupBox = new QGroupBox(leftFrame);
        cleanAreaGroupBox->setObjectName(QStringLiteral("cleanAreaGroupBox"));
        sizePolicy1.setHeightForWidth(cleanAreaGroupBox->sizePolicy().hasHeightForWidth());
        cleanAreaGroupBox->setSizePolicy(sizePolicy1);
        cleanAreaGroupBox->setFlat(true);
        formLayout_2 = new QFormLayout(cleanAreaGroupBox);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_4 = new QLabel(cleanAreaGroupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(cleanAreaGroupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_5);

        cleanHeightDoubleSpinBox = new QDoubleSpinBox(cleanAreaGroupBox);
        cleanHeightDoubleSpinBox->setObjectName(QStringLiteral("cleanHeightDoubleSpinBox"));
        cleanHeightDoubleSpinBox->setDecimals(3);
        cleanHeightDoubleSpinBox->setMinimum(0.001);
        cleanHeightDoubleSpinBox->setMaximum(1e+06);
        cleanHeightDoubleSpinBox->setValue(1);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, cleanHeightDoubleSpinBox);

        selectionModeComboBox = new QComboBox(cleanAreaGroupBox);
        selectionModeComboBox->setObjectName(QStringLiteral("selectionModeComboBox"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, selectionModeComboBox);

        undoPushButton = new QPushButton(cleanAreaGroupBox);
        undoPushButton->setObjectName(QStringLiteral("undoPushButton"));
        undoPushButton->setEnabled(false);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, undoPushButton);

        undo10PushButton = new QPushButton(cleanAreaGroupBox);
        undo10PushButton->setObjectName(QStringLiteral("undo10PushButton"));
        undo10PushButton->setEnabled(false);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, undo10PushButton);


        verticalLayout->addWidget(cleanAreaGroupBox);

        viewGroupBox = new QGroupBox(leftFrame);
        viewGroupBox->setObjectName(QStringLiteral("viewGroupBox"));
        horizontalLayout = new QHBoxLayout(viewGroupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        topViewToolButton = new QToolButton(viewGroupBox);
        topViewToolButton->setObjectName(QStringLiteral("topViewToolButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/CC/plugin/qBroom/images/ccViewZpos.png"), QSize(), QIcon::Normal, QIcon::Off);
        topViewToolButton->setIcon(icon1);
        topViewToolButton->setAutoRaise(true);

        horizontalLayout->addWidget(topViewToolButton);

        frontViewToolButton = new QToolButton(viewGroupBox);
        frontViewToolButton->setObjectName(QStringLiteral("frontViewToolButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/CC/plugin/qBroom/images/ccViewYpos.png"), QSize(), QIcon::Normal, QIcon::Off);
        frontViewToolButton->setIcon(icon2);
        frontViewToolButton->setAutoRaise(true);

        horizontalLayout->addWidget(frontViewToolButton);

        leftViewToolButton = new QToolButton(viewGroupBox);
        leftViewToolButton->setObjectName(QStringLiteral("leftViewToolButton"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/CC/plugin/qBroom/images/ccViewXpos.png"), QSize(), QIcon::Normal, QIcon::Off);
        leftViewToolButton->setIcon(icon3);
        leftViewToolButton->setAutoRaise(true);

        horizontalLayout->addWidget(leftViewToolButton);

        backViewToolButton = new QToolButton(viewGroupBox);
        backViewToolButton->setObjectName(QStringLiteral("backViewToolButton"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/CC/plugin/qBroom/images/ccViewYneg.png"), QSize(), QIcon::Normal, QIcon::Off);
        backViewToolButton->setIcon(icon4);
        backViewToolButton->setAutoRaise(true);

        horizontalLayout->addWidget(backViewToolButton);

        rightViewToolButton = new QToolButton(viewGroupBox);
        rightViewToolButton->setObjectName(QStringLiteral("rightViewToolButton"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/CC/plugin/qBroom/images/ccViewXneg.png"), QSize(), QIcon::Normal, QIcon::Off);
        rightViewToolButton->setIcon(icon5);
        rightViewToolButton->setAutoRaise(true);

        horizontalLayout->addWidget(rightViewToolButton);

        bottomViewToolButton = new QToolButton(viewGroupBox);
        bottomViewToolButton->setObjectName(QStringLiteral("bottomViewToolButton"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/CC/plugin/qBroom/images/ccViewZneg.png"), QSize(), QIcon::Normal, QIcon::Off);
        bottomViewToolButton->setIcon(icon6);
        bottomViewToolButton->setAutoRaise(true);

        horizontalLayout->addWidget(bottomViewToolButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(viewGroupBox);

        lostTrackFrame = new QFrame(leftFrame);
        lostTrackFrame->setObjectName(QStringLiteral("lostTrackFrame"));
        lostTrackFrame->setFrameShape(QFrame::StyledPanel);
        lostTrackFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(lostTrackFrame);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        imageLabel = new QLabel(lostTrackFrame);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        imageLabel->setPixmap(QPixmap(QString::fromUtf8(":/CC/plugin/qBroom/images/warning.png")));
        imageLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(imageLabel);

        lostTrackLabel = new QLabel(lostTrackFrame);
        lostTrackLabel->setObjectName(QStringLiteral("lostTrackLabel"));
        lostTrackLabel->setStyleSheet(QStringLiteral("color:red;"));
        lostTrackLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lostTrackLabel);


        verticalLayout->addWidget(lostTrackFrame);

        verticalSpacer = new QSpacerItem(20, 35, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        removeSelectedPointsCheckBox = new QCheckBox(leftFrame);
        removeSelectedPointsCheckBox->setObjectName(QStringLiteral("removeSelectedPointsCheckBox"));
        removeSelectedPointsCheckBox->setChecked(true);

        verticalLayout->addWidget(removeSelectedPointsCheckBox);

        buttonsFrame = new QFrame(leftFrame);
        buttonsFrame->setObjectName(QStringLiteral("buttonsFrame"));
        buttonsFrame->setFrameShape(QFrame::StyledPanel);
        buttonsFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(buttonsFrame);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        applyPushButton = new QPushButton(buttonsFrame);
        applyPushButton->setObjectName(QStringLiteral("applyPushButton"));
        applyPushButton->setEnabled(false);

        horizontalLayout_3->addWidget(applyPushButton);

        validatePushButton = new QPushButton(buttonsFrame);
        validatePushButton->setObjectName(QStringLiteral("validatePushButton"));
        validatePushButton->setEnabled(false);

        horizontalLayout_3->addWidget(validatePushButton);

        cancelPushButton = new QPushButton(buttonsFrame);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));

        horizontalLayout_3->addWidget(cancelPushButton);


        verticalLayout->addWidget(buttonsFrame);


        horizontalLayout_2->addWidget(leftFrame);

        viewFrame = new QFrame(BroomDialog);
        viewFrame->setObjectName(QStringLiteral("viewFrame"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(viewFrame->sizePolicy().hasHeightForWidth());
        viewFrame->setSizePolicy(sizePolicy2);
        viewFrame->setMinimumSize(QSize(512, 512));
        viewFrame->setFrameShape(QFrame::StyledPanel);
        viewFrame->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(viewFrame);


        retranslateUi(BroomDialog);

        selectionModeComboBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(BroomDialog);
    } // setupUi

    void retranslateUi(QDialog *BroomDialog)
    {
        BroomDialog->setWindowTitle(QApplication::translate("BroomDialog", "CEA Broom Tool", 0));
        broomGroupBox->setTitle(QApplication::translate("BroomDialog", "Broom", 0));
        repositionPushButton->setText(QApplication::translate("BroomDialog", "Reposition", 0));
        automatePushButton->setText(QApplication::translate("BroomDialog", "Automate", 0));
        stickCheckBox->setText(QApplication::translate("BroomDialog", "stick to the cloud", 0));
#ifndef QT_NO_TOOLTIP
        animateAutomationCheckBox->setToolTip(QApplication::translate("BroomDialog", "For a visual feedback of the ongoing automation process (slower)", 0));
#endif // QT_NO_TOOLTIP
        animateAutomationCheckBox->setText(QApplication::translate("BroomDialog", "animated automation", 0));
        broomDimGroupBox->setTitle(QApplication::translate("BroomDialog", "Broom dimensions", 0));
        label_3->setText(QApplication::translate("BroomDialog", "length", 0));
        label->setText(QApplication::translate("BroomDialog", "width", 0));
        label_2->setText(QApplication::translate("BroomDialog", "thickness", 0));
        cleanAreaGroupBox->setTitle(QApplication::translate("BroomDialog", "Selection", 0));
        label_4->setText(QApplication::translate("BroomDialog", "mode", 0));
        label_5->setText(QApplication::translate("BroomDialog", "height", 0));
        selectionModeComboBox->clear();
        selectionModeComboBox->insertItems(0, QStringList()
         << QApplication::translate("BroomDialog", "inside", 0)
         << QApplication::translate("BroomDialog", "above", 0)
         << QApplication::translate("BroomDialog", "below", 0)
         << QApplication::translate("BroomDialog", "above and below", 0)
        );
        undoPushButton->setText(QApplication::translate("BroomDialog", "Undo", 0));
        undo10PushButton->setText(QApplication::translate("BroomDialog", "Undo 10 steps", 0));
        viewGroupBox->setTitle(QApplication::translate("BroomDialog", "View", 0));
        imageLabel->setText(QString());
        lostTrackLabel->setText(QApplication::translate("BroomDialog", "Lost track: failed to stick to the cloud!", 0));
        removeSelectedPointsCheckBox->setText(QApplication::translate("BroomDialog", "remove the selected points", 0));
        applyPushButton->setText(QApplication::translate("BroomDialog", "Apply", 0));
        validatePushButton->setText(QApplication::translate("BroomDialog", "Validate", 0));
        cancelPushButton->setText(QApplication::translate("BroomDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class BroomDialog: public Ui_BroomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BROOMDLG_H
