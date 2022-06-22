/********************************************************************************
** Form generated from reading UI file 'colorFromScalarDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORFROMSCALARDLG_H
#define UI_COLORFROMSCALARDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ColorFromScalarDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QRadioButton *toggleRGB;
    QRadioButton *toggleHSV;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *mRedGroupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *mRedLabel;
    QSpacerItem *horizontalSpacer;
    QComboBox *channelComboR;
    QLabel *MinLabelR;
    QDoubleSpinBox *minInputSpinBoxR;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *fixR;
    QCheckBox *reverseR;
    QSpacerItem *horizontalSpacer_6;
    QLabel *MaxLabelR;
    QDoubleSpinBox *maxInputSpinBoxR;
    QFrame *histoFrameR;
    QGroupBox *mGreenGroupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *mGreenLabel;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *channelComboG;
    QLabel *MinLabelG;
    QDoubleSpinBox *minInputSpinBoxG;
    QSpacerItem *horizontalSpacer_10;
    QCheckBox *fixG;
    QCheckBox *reverseG;
    QSpacerItem *horizontalSpacer_8;
    QLabel *MaxLabelG;
    QDoubleSpinBox *maxInputSpinBoxG;
    QFrame *histoFrameG;
    QGroupBox *mBlueGroupBox;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *mBlueLabel;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *channelComboB;
    QLabel *MinLabelB;
    QDoubleSpinBox *minInputSpinBoxB;
    QSpacerItem *horizontalSpacer_7;
    QCheckBox *fixB;
    QCheckBox *reverseB;
    QSpacerItem *horizontalSpacer_9;
    QLabel *MaxLabelB;
    QDoubleSpinBox *maxInputSpinBoxB;
    QFrame *histoFrameB;
    QGroupBox *mAlphaGroupBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *mAlphaLabel;
    QSpacerItem *horizontalSpacer_11;
    QComboBox *channelComboA;
    QLabel *MinLabelA;
    QDoubleSpinBox *minInputSpinBoxA;
    QSpacerItem *horizontalSpacer_15;
    QCheckBox *fixA;
    QCheckBox *reverseA;
    QSpacerItem *horizontalSpacer_16;
    QLabel *MaxLabelA;
    QDoubleSpinBox *maxInputSpinBoxA;
    QFrame *histoFrameA;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ColorFromScalarDialog)
    {
        if (ColorFromScalarDialog->objectName().isEmpty())
            ColorFromScalarDialog->setObjectName(QStringLiteral("ColorFromScalarDialog"));
        ColorFromScalarDialog->resize(620, 800);
        verticalLayout = new QVBoxLayout(ColorFromScalarDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(6, -1, -1, -1);
        label = new QLabel(ColorFromScalarDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        toggleRGB = new QRadioButton(ColorFromScalarDialog);
        toggleRGB->setObjectName(QStringLiteral("toggleRGB"));
        toggleRGB->setChecked(true);

        horizontalLayout->addWidget(toggleRGB);

        toggleHSV = new QRadioButton(ColorFromScalarDialog);
        toggleHSV->setObjectName(QStringLiteral("toggleHSV"));

        horizontalLayout->addWidget(toggleHSV);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        mRedGroupBox = new QGroupBox(ColorFromScalarDialog);
        mRedGroupBox->setObjectName(QStringLiteral("mRedGroupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mRedGroupBox->sizePolicy().hasHeightForWidth());
        mRedGroupBox->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        mRedGroupBox->setFont(font);
        verticalLayout_2 = new QVBoxLayout(mRedGroupBox);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(6, 0, 6, 6);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        mRedLabel = new QLabel(mRedGroupBox);
        mRedLabel->setObjectName(QStringLiteral("mRedLabel"));
        QFont font1;
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        mRedLabel->setFont(font1);

        horizontalLayout_2->addWidget(mRedLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        channelComboR = new QComboBox(mRedGroupBox);
        channelComboR->setObjectName(QStringLiteral("channelComboR"));

        horizontalLayout_2->addWidget(channelComboR);

        MinLabelR = new QLabel(mRedGroupBox);
        MinLabelR->setObjectName(QStringLiteral("MinLabelR"));

        horizontalLayout_2->addWidget(MinLabelR);

        minInputSpinBoxR = new QDoubleSpinBox(mRedGroupBox);
        minInputSpinBoxR->setObjectName(QStringLiteral("minInputSpinBoxR"));

        horizontalLayout_2->addWidget(minInputSpinBoxR);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        fixR = new QCheckBox(mRedGroupBox);
        fixR->setObjectName(QStringLiteral("fixR"));

        horizontalLayout_2->addWidget(fixR);

        reverseR = new QCheckBox(mRedGroupBox);
        reverseR->setObjectName(QStringLiteral("reverseR"));

        horizontalLayout_2->addWidget(reverseR);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        MaxLabelR = new QLabel(mRedGroupBox);
        MaxLabelR->setObjectName(QStringLiteral("MaxLabelR"));

        horizontalLayout_2->addWidget(MaxLabelR);

        maxInputSpinBoxR = new QDoubleSpinBox(mRedGroupBox);
        maxInputSpinBoxR->setObjectName(QStringLiteral("maxInputSpinBoxR"));

        horizontalLayout_2->addWidget(maxInputSpinBoxR);


        verticalLayout_2->addLayout(horizontalLayout_2);

        histoFrameR = new QFrame(mRedGroupBox);
        histoFrameR->setObjectName(QStringLiteral("histoFrameR"));
        sizePolicy.setHeightForWidth(histoFrameR->sizePolicy().hasHeightForWidth());
        histoFrameR->setSizePolicy(sizePolicy);
        histoFrameR->setFrameShape(QFrame::StyledPanel);

        verticalLayout_2->addWidget(histoFrameR);


        verticalLayout->addWidget(mRedGroupBox);

        mGreenGroupBox = new QGroupBox(ColorFromScalarDialog);
        mGreenGroupBox->setObjectName(QStringLiteral("mGreenGroupBox"));
        verticalLayout_3 = new QVBoxLayout(mGreenGroupBox);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(6, 0, 6, 6);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        mGreenLabel = new QLabel(mGreenGroupBox);
        mGreenLabel->setObjectName(QStringLiteral("mGreenLabel"));
        mGreenLabel->setFont(font1);

        horizontalLayout_4->addWidget(mGreenLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        channelComboG = new QComboBox(mGreenGroupBox);
        channelComboG->setObjectName(QStringLiteral("channelComboG"));

        horizontalLayout_4->addWidget(channelComboG);

        MinLabelG = new QLabel(mGreenGroupBox);
        MinLabelG->setObjectName(QStringLiteral("MinLabelG"));

        horizontalLayout_4->addWidget(MinLabelG);

        minInputSpinBoxG = new QDoubleSpinBox(mGreenGroupBox);
        minInputSpinBoxG->setObjectName(QStringLiteral("minInputSpinBoxG"));

        horizontalLayout_4->addWidget(minInputSpinBoxG);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        fixG = new QCheckBox(mGreenGroupBox);
        fixG->setObjectName(QStringLiteral("fixG"));

        horizontalLayout_4->addWidget(fixG);

        reverseG = new QCheckBox(mGreenGroupBox);
        reverseG->setObjectName(QStringLiteral("reverseG"));

        horizontalLayout_4->addWidget(reverseG);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        MaxLabelG = new QLabel(mGreenGroupBox);
        MaxLabelG->setObjectName(QStringLiteral("MaxLabelG"));

        horizontalLayout_4->addWidget(MaxLabelG);

        maxInputSpinBoxG = new QDoubleSpinBox(mGreenGroupBox);
        maxInputSpinBoxG->setObjectName(QStringLiteral("maxInputSpinBoxG"));

        horizontalLayout_4->addWidget(maxInputSpinBoxG);


        verticalLayout_3->addLayout(horizontalLayout_4);

        histoFrameG = new QFrame(mGreenGroupBox);
        histoFrameG->setObjectName(QStringLiteral("histoFrameG"));
        sizePolicy.setHeightForWidth(histoFrameG->sizePolicy().hasHeightForWidth());
        histoFrameG->setSizePolicy(sizePolicy);
        histoFrameG->setFrameShape(QFrame::StyledPanel);
        histoFrameG->setFrameShadow(QFrame::Raised);

        verticalLayout_3->addWidget(histoFrameG);


        verticalLayout->addWidget(mGreenGroupBox);

        mBlueGroupBox = new QGroupBox(ColorFromScalarDialog);
        mBlueGroupBox->setObjectName(QStringLiteral("mBlueGroupBox"));
        verticalLayout_4 = new QVBoxLayout(mBlueGroupBox);
        verticalLayout_4->setSpacing(3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(6, 0, 6, 6);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        mBlueLabel = new QLabel(mBlueGroupBox);
        mBlueLabel->setObjectName(QStringLiteral("mBlueLabel"));
        mBlueLabel->setFont(font1);

        horizontalLayout_5->addWidget(mBlueLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        channelComboB = new QComboBox(mBlueGroupBox);
        channelComboB->setObjectName(QStringLiteral("channelComboB"));

        horizontalLayout_5->addWidget(channelComboB);

        MinLabelB = new QLabel(mBlueGroupBox);
        MinLabelB->setObjectName(QStringLiteral("MinLabelB"));

        horizontalLayout_5->addWidget(MinLabelB);

        minInputSpinBoxB = new QDoubleSpinBox(mBlueGroupBox);
        minInputSpinBoxB->setObjectName(QStringLiteral("minInputSpinBoxB"));

        horizontalLayout_5->addWidget(minInputSpinBoxB);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        fixB = new QCheckBox(mBlueGroupBox);
        fixB->setObjectName(QStringLiteral("fixB"));

        horizontalLayout_5->addWidget(fixB);

        reverseB = new QCheckBox(mBlueGroupBox);
        reverseB->setObjectName(QStringLiteral("reverseB"));

        horizontalLayout_5->addWidget(reverseB);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        MaxLabelB = new QLabel(mBlueGroupBox);
        MaxLabelB->setObjectName(QStringLiteral("MaxLabelB"));

        horizontalLayout_5->addWidget(MaxLabelB);

        maxInputSpinBoxB = new QDoubleSpinBox(mBlueGroupBox);
        maxInputSpinBoxB->setObjectName(QStringLiteral("maxInputSpinBoxB"));

        horizontalLayout_5->addWidget(maxInputSpinBoxB);


        verticalLayout_4->addLayout(horizontalLayout_5);

        histoFrameB = new QFrame(mBlueGroupBox);
        histoFrameB->setObjectName(QStringLiteral("histoFrameB"));
        sizePolicy.setHeightForWidth(histoFrameB->sizePolicy().hasHeightForWidth());
        histoFrameB->setSizePolicy(sizePolicy);
        histoFrameB->setFrameShape(QFrame::StyledPanel);
        histoFrameB->setFrameShadow(QFrame::Raised);

        verticalLayout_4->addWidget(histoFrameB);


        verticalLayout->addWidget(mBlueGroupBox);

        mAlphaGroupBox = new QGroupBox(ColorFromScalarDialog);
        mAlphaGroupBox->setObjectName(QStringLiteral("mAlphaGroupBox"));
        verticalLayout_5 = new QVBoxLayout(mAlphaGroupBox);
        verticalLayout_5->setSpacing(3);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(6, 0, 6, 6);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        mAlphaLabel = new QLabel(mAlphaGroupBox);
        mAlphaLabel->setObjectName(QStringLiteral("mAlphaLabel"));
        mAlphaLabel->setFont(font1);

        horizontalLayout_7->addWidget(mAlphaLabel);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_11);

        channelComboA = new QComboBox(mAlphaGroupBox);
        channelComboA->setObjectName(QStringLiteral("channelComboA"));

        horizontalLayout_7->addWidget(channelComboA);

        MinLabelA = new QLabel(mAlphaGroupBox);
        MinLabelA->setObjectName(QStringLiteral("MinLabelA"));

        horizontalLayout_7->addWidget(MinLabelA);

        minInputSpinBoxA = new QDoubleSpinBox(mAlphaGroupBox);
        minInputSpinBoxA->setObjectName(QStringLiteral("minInputSpinBoxA"));

        horizontalLayout_7->addWidget(minInputSpinBoxA);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_15);

        fixA = new QCheckBox(mAlphaGroupBox);
        fixA->setObjectName(QStringLiteral("fixA"));
        fixA->setChecked(false);

        horizontalLayout_7->addWidget(fixA);

        reverseA = new QCheckBox(mAlphaGroupBox);
        reverseA->setObjectName(QStringLiteral("reverseA"));

        horizontalLayout_7->addWidget(reverseA);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_16);

        MaxLabelA = new QLabel(mAlphaGroupBox);
        MaxLabelA->setObjectName(QStringLiteral("MaxLabelA"));

        horizontalLayout_7->addWidget(MaxLabelA);

        maxInputSpinBoxA = new QDoubleSpinBox(mAlphaGroupBox);
        maxInputSpinBoxA->setObjectName(QStringLiteral("maxInputSpinBoxA"));

        horizontalLayout_7->addWidget(maxInputSpinBoxA);


        verticalLayout_5->addLayout(horizontalLayout_7);

        histoFrameA = new QFrame(mAlphaGroupBox);
        histoFrameA->setObjectName(QStringLiteral("histoFrameA"));
        sizePolicy.setHeightForWidth(histoFrameA->sizePolicy().hasHeightForWidth());
        histoFrameA->setSizePolicy(sizePolicy);
        histoFrameA->setFrameShape(QFrame::StyledPanel);
        histoFrameA->setFrameShadow(QFrame::Raised);

        verticalLayout_5->addWidget(histoFrameA);


        verticalLayout->addWidget(mAlphaGroupBox);

        buttonBox = new QDialogButtonBox(ColorFromScalarDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Close);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ColorFromScalarDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ColorFromScalarDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ColorFromScalarDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ColorFromScalarDialog);
    } // setupUi

    void retranslateUi(QDialog *ColorFromScalarDialog)
    {
        ColorFromScalarDialog->setWindowTitle(QApplication::translate("ColorFromScalarDialog", "Color From Scalar Fields", 0));
        label->setText(QApplication::translate("ColorFromScalarDialog", "Mapping type:", 0));
        toggleRGB->setText(QApplication::translate("ColorFromScalarDialog", "To RGB", 0));
        toggleHSV->setText(QApplication::translate("ColorFromScalarDialog", "To HSV", 0));
        mRedLabel->setText(QApplication::translate("ColorFromScalarDialog", "Red", 0));
        channelComboR->clear();
        channelComboR->insertItems(0, QStringList()
         << QApplication::translate("ColorFromScalarDialog", "RGB", 0)
         << QApplication::translate("ColorFromScalarDialog", "Red", 0)
         << QApplication::translate("ColorFromScalarDialog", "Green", 0)
         << QApplication::translate("ColorFromScalarDialog", "Blue", 0)
        );
        channelComboR->setCurrentText(QApplication::translate("ColorFromScalarDialog", "RGB", 0));
        MinLabelR->setText(QApplication::translate("ColorFromScalarDialog", "Minimum:", 0));
        fixR->setText(QApplication::translate("ColorFromScalarDialog", "Fix", 0));
        reverseR->setText(QApplication::translate("ColorFromScalarDialog", "Reverse", 0));
        MaxLabelR->setText(QApplication::translate("ColorFromScalarDialog", "Maximum:", 0));
        mGreenGroupBox->setTitle(QString());
        mGreenLabel->setText(QApplication::translate("ColorFromScalarDialog", "Green", 0));
        channelComboG->clear();
        channelComboG->insertItems(0, QStringList()
         << QApplication::translate("ColorFromScalarDialog", "RGB", 0)
         << QApplication::translate("ColorFromScalarDialog", "Red", 0)
         << QApplication::translate("ColorFromScalarDialog", "Green", 0)
         << QApplication::translate("ColorFromScalarDialog", "Blue", 0)
        );
        channelComboG->setCurrentText(QApplication::translate("ColorFromScalarDialog", "RGB", 0));
        MinLabelG->setText(QApplication::translate("ColorFromScalarDialog", "Minimum:", 0));
        fixG->setText(QApplication::translate("ColorFromScalarDialog", "Fix", 0));
        reverseG->setText(QApplication::translate("ColorFromScalarDialog", "Reverse", 0));
        MaxLabelG->setText(QApplication::translate("ColorFromScalarDialog", "Maximum:", 0));
        mBlueGroupBox->setTitle(QString());
        mBlueLabel->setText(QApplication::translate("ColorFromScalarDialog", "Blue", 0));
        channelComboB->clear();
        channelComboB->insertItems(0, QStringList()
         << QApplication::translate("ColorFromScalarDialog", "RGB", 0)
         << QApplication::translate("ColorFromScalarDialog", "Red", 0)
         << QApplication::translate("ColorFromScalarDialog", "Green", 0)
         << QApplication::translate("ColorFromScalarDialog", "Blue", 0)
        );
        channelComboB->setCurrentText(QApplication::translate("ColorFromScalarDialog", "RGB", 0));
        MinLabelB->setText(QApplication::translate("ColorFromScalarDialog", "Minimum:", 0));
        fixB->setText(QApplication::translate("ColorFromScalarDialog", "Fix", 0));
        reverseB->setText(QApplication::translate("ColorFromScalarDialog", "Reverse", 0));
        MaxLabelB->setText(QApplication::translate("ColorFromScalarDialog", "Maximum:", 0));
        mAlphaGroupBox->setTitle(QString());
        mAlphaLabel->setText(QApplication::translate("ColorFromScalarDialog", "Alpha", 0));
        channelComboA->clear();
        channelComboA->insertItems(0, QStringList()
         << QApplication::translate("ColorFromScalarDialog", "RGB", 0)
         << QApplication::translate("ColorFromScalarDialog", "Red", 0)
         << QApplication::translate("ColorFromScalarDialog", "Green", 0)
         << QApplication::translate("ColorFromScalarDialog", "Blue", 0)
        );
        channelComboA->setCurrentText(QApplication::translate("ColorFromScalarDialog", "RGB", 0));
        MinLabelA->setText(QApplication::translate("ColorFromScalarDialog", "Minimum:", 0));
        fixA->setText(QApplication::translate("ColorFromScalarDialog", "Fix", 0));
        reverseA->setText(QApplication::translate("ColorFromScalarDialog", "Reverse", 0));
        MaxLabelA->setText(QApplication::translate("ColorFromScalarDialog", "Maximum:", 0));
    } // retranslateUi

};

namespace Ui {
    class ColorFromScalarDialog: public Ui_ColorFromScalarDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORFROMSCALARDLG_H
