/********************************************************************************
** Form generated from reading UI file 'graphicalTransformationDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICALTRANSFORMATIONDLG_H
#define UI_GRAPHICALTRANSFORMATIONDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GraphicalTransformationDlg
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *pauseButton;
    QToolButton *razButton;
    QToolButton *okButton;
    QToolButton *cancelButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *rotComboBox;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *TxCheckBox;
    QCheckBox *TyCheckBox;
    QCheckBox *TzCheckBox;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *advPushButton;
    QHBoxLayout *horizontalLayout_5;
    QLabel *translateLabel;
    QComboBox *advTranslateComboBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *rotateLabel;
    QComboBox *advRotateComboBox;
    QLabel *rotAxisLabel;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *objCenterRadio;
    QRadioButton *refAxisRadio;

    void setupUi(QDialog *GraphicalTransformationDlg)
    {
        if (GraphicalTransformationDlg->objectName().isEmpty())
            GraphicalTransformationDlg->setObjectName(QStringLiteral("GraphicalTransformationDlg"));
        GraphicalTransformationDlg->resize(250, 235);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GraphicalTransformationDlg->sizePolicy().hasHeightForWidth());
        GraphicalTransformationDlg->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(GraphicalTransformationDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        frame = new QFrame(GraphicalTransformationDlg);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pauseButton = new QToolButton(frame);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setMinimumSize(QSize(25, 25));
        QIcon icon;
        icon.addFile(QStringLiteral(":/CC/images/smallPause.png"), QSize(), QIcon::Normal, QIcon::Off);
        pauseButton->setIcon(icon);
        pauseButton->setCheckable(true);
        pauseButton->setChecked(false);

        horizontalLayout->addWidget(pauseButton);

        razButton = new QToolButton(frame);
        razButton->setObjectName(QStringLiteral("razButton"));
        razButton->setMinimumSize(QSize(25, 25));
        razButton->setText(QStringLiteral("..."));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/CC/images/smallReset.png"), QSize(), QIcon::Normal, QIcon::Off);
        razButton->setIcon(icon1);

        horizontalLayout->addWidget(razButton);

        okButton = new QToolButton(frame);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setMinimumSize(QSize(25, 25));
        okButton->setText(QStringLiteral("..."));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/CC/images/smallValidate.png"), QSize(), QIcon::Normal, QIcon::Off);
        okButton->setIcon(icon2);

        horizontalLayout->addWidget(okButton);

        cancelButton = new QToolButton(frame);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setMinimumSize(QSize(25, 25));
        cancelButton->setText(QStringLiteral("..."));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/CC/images/smallCancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon3);

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addWidget(frame);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(GraphicalTransformationDlg);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label);

        rotComboBox = new QComboBox(GraphicalTransformationDlg);
        rotComboBox->addItem(QStringLiteral("XYZ"));
        rotComboBox->addItem(QStringLiteral("X"));
        rotComboBox->addItem(QStringLiteral("Y"));
        rotComboBox->addItem(QStringLiteral("Z"));
        rotComboBox->addItem(QString());
        rotComboBox->setObjectName(QStringLiteral("rotComboBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(rotComboBox->sizePolicy().hasHeightForWidth());
        rotComboBox->setSizePolicy(sizePolicy3);
        rotComboBox->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_2->addWidget(rotComboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        TxCheckBox = new QCheckBox(GraphicalTransformationDlg);
        TxCheckBox->setObjectName(QStringLiteral("TxCheckBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(TxCheckBox->sizePolicy().hasHeightForWidth());
        TxCheckBox->setSizePolicy(sizePolicy4);
        TxCheckBox->setText(QStringLiteral("Tx"));
        TxCheckBox->setChecked(true);

        horizontalLayout_3->addWidget(TxCheckBox);

        TyCheckBox = new QCheckBox(GraphicalTransformationDlg);
        TyCheckBox->setObjectName(QStringLiteral("TyCheckBox"));
        sizePolicy4.setHeightForWidth(TyCheckBox->sizePolicy().hasHeightForWidth());
        TyCheckBox->setSizePolicy(sizePolicy4);
        TyCheckBox->setText(QStringLiteral("Ty"));
        TyCheckBox->setChecked(true);

        horizontalLayout_3->addWidget(TyCheckBox);

        TzCheckBox = new QCheckBox(GraphicalTransformationDlg);
        TzCheckBox->setObjectName(QStringLiteral("TzCheckBox"));
        sizePolicy4.setHeightForWidth(TzCheckBox->sizePolicy().hasHeightForWidth());
        TzCheckBox->setSizePolicy(sizePolicy4);
        TzCheckBox->setText(QStringLiteral("Tz"));
        TzCheckBox->setChecked(true);

        horizontalLayout_3->addWidget(TzCheckBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        advPushButton = new QPushButton(GraphicalTransformationDlg);
        advPushButton->setObjectName(QStringLiteral("advPushButton"));
        advPushButton->setCheckable(true);

        horizontalLayout_4->addWidget(advPushButton);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        translateLabel = new QLabel(GraphicalTransformationDlg);
        translateLabel->setObjectName(QStringLiteral("translateLabel"));

        horizontalLayout_5->addWidget(translateLabel);

        advTranslateComboBox = new QComboBox(GraphicalTransformationDlg);
        advTranslateComboBox->setObjectName(QStringLiteral("advTranslateComboBox"));
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(advTranslateComboBox->sizePolicy().hasHeightForWidth());
        advTranslateComboBox->setSizePolicy(sizePolicy5);

        horizontalLayout_5->addWidget(advTranslateComboBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        rotateLabel = new QLabel(GraphicalTransformationDlg);
        rotateLabel->setObjectName(QStringLiteral("rotateLabel"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(rotateLabel->sizePolicy().hasHeightForWidth());
        rotateLabel->setSizePolicy(sizePolicy6);

        horizontalLayout_6->addWidget(rotateLabel);

        advRotateComboBox = new QComboBox(GraphicalTransformationDlg);
        advRotateComboBox->setObjectName(QStringLiteral("advRotateComboBox"));
        sizePolicy5.setHeightForWidth(advRotateComboBox->sizePolicy().hasHeightForWidth());
        advRotateComboBox->setSizePolicy(sizePolicy5);

        horizontalLayout_6->addWidget(advRotateComboBox);


        verticalLayout->addLayout(horizontalLayout_6);

        rotAxisLabel = new QLabel(GraphicalTransformationDlg);
        rotAxisLabel->setObjectName(QStringLiteral("rotAxisLabel"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(rotAxisLabel->sizePolicy().hasHeightForWidth());
        rotAxisLabel->setSizePolicy(sizePolicy7);

        verticalLayout->addWidget(rotAxisLabel);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        objCenterRadio = new QRadioButton(GraphicalTransformationDlg);
        objCenterRadio->setObjectName(QStringLiteral("objCenterRadio"));
        sizePolicy7.setHeightForWidth(objCenterRadio->sizePolicy().hasHeightForWidth());
        objCenterRadio->setSizePolicy(sizePolicy7);

        horizontalLayout_7->addWidget(objCenterRadio);

        refAxisRadio = new QRadioButton(GraphicalTransformationDlg);
        refAxisRadio->setObjectName(QStringLiteral("refAxisRadio"));
        sizePolicy7.setHeightForWidth(refAxisRadio->sizePolicy().hasHeightForWidth());
        refAxisRadio->setSizePolicy(sizePolicy7);

        horizontalLayout_7->addWidget(refAxisRadio);


        verticalLayout->addLayout(horizontalLayout_7);


        retranslateUi(GraphicalTransformationDlg);

        QMetaObject::connectSlotsByName(GraphicalTransformationDlg);
    } // setupUi

    void retranslateUi(QDialog *GraphicalTransformationDlg)
    {
        GraphicalTransformationDlg->setWindowTitle(QApplication::translate("GraphicalTransformationDlg", "Graphical Transformation", 0));
#ifndef QT_NO_TOOLTIP
        pauseButton->setToolTip(QApplication::translate("GraphicalTransformationDlg", "Pause segmentation", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pauseButton->setStatusTip(QApplication::translate("GraphicalTransformationDlg", "Pause transformation (allow rotation/panning of 3D view)", 0));
#endif // QT_NO_STATUSTIP
        pauseButton->setText(QApplication::translate("GraphicalTransformationDlg", "pause", 0));
        label->setText(QApplication::translate("GraphicalTransformationDlg", "Rotation", 0));
        rotComboBox->setItemText(4, QApplication::translate("GraphicalTransformationDlg", "None", 0));

        advPushButton->setText(QApplication::translate("GraphicalTransformationDlg", "Advanced", 0));
        translateLabel->setText(QApplication::translate("GraphicalTransformationDlg", "Translate Along:", 0));
        advTranslateComboBox->clear();
        advTranslateComboBox->insertItems(0, QStringList()
         << QApplication::translate("GraphicalTransformationDlg", "Origin", 0)
        );
        rotateLabel->setText(QApplication::translate("GraphicalTransformationDlg", "Rotate Around:", 0));
        advRotateComboBox->clear();
        advRotateComboBox->insertItems(0, QStringList()
         << QApplication::translate("GraphicalTransformationDlg", "Origin", 0)
        );
        rotAxisLabel->setText(QApplication::translate("GraphicalTransformationDlg", "Rotation Axis Selection:", 0));
        objCenterRadio->setText(QApplication::translate("GraphicalTransformationDlg", "Object Center", 0));
        refAxisRadio->setText(QApplication::translate("GraphicalTransformationDlg", "Reference Axis", 0));
    } // retranslateUi

};

namespace Ui {
    class GraphicalTransformationDlg: public Ui_GraphicalTransformationDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICALTRANSFORMATIONDLG_H
