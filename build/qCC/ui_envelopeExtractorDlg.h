/********************************************************************************
** Form generated from reading UI file 'envelopeExtractorDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENVELOPEEXTRACTORDLG_H
#define UI_ENVELOPEEXTRACTORDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EnvelopeExtractorDlg
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *viewFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *messageLabel;
    QCheckBox *autoCheckBox;
    QPushButton *nextPushButton;
    QPushButton *skipPushButton;

    void setupUi(QDialog *EnvelopeExtractorDlg)
    {
        if (EnvelopeExtractorDlg->objectName().isEmpty())
            EnvelopeExtractorDlg->setObjectName(QStringLiteral("EnvelopeExtractorDlg"));
        EnvelopeExtractorDlg->resize(836, 682);
        verticalLayout = new QVBoxLayout(EnvelopeExtractorDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        viewFrame = new QFrame(EnvelopeExtractorDlg);
        viewFrame->setObjectName(QStringLiteral("viewFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(viewFrame->sizePolicy().hasHeightForWidth());
        viewFrame->setSizePolicy(sizePolicy);
        viewFrame->setMinimumSize(QSize(512, 512));
        viewFrame->setFrameShape(QFrame::StyledPanel);
        viewFrame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(viewFrame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(EnvelopeExtractorDlg);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        messageLabel = new QLabel(EnvelopeExtractorDlg);
        messageLabel->setObjectName(QStringLiteral("messageLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(messageLabel->sizePolicy().hasHeightForWidth());
        messageLabel->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(messageLabel);

        autoCheckBox = new QCheckBox(EnvelopeExtractorDlg);
        autoCheckBox->setObjectName(QStringLiteral("autoCheckBox"));

        horizontalLayout->addWidget(autoCheckBox);

        nextPushButton = new QPushButton(EnvelopeExtractorDlg);
        nextPushButton->setObjectName(QStringLiteral("nextPushButton"));

        horizontalLayout->addWidget(nextPushButton);

        skipPushButton = new QPushButton(EnvelopeExtractorDlg);
        skipPushButton->setObjectName(QStringLiteral("skipPushButton"));

        horizontalLayout->addWidget(skipPushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(EnvelopeExtractorDlg);

        QMetaObject::connectSlotsByName(EnvelopeExtractorDlg);
    } // setupUi

    void retranslateUi(QDialog *EnvelopeExtractorDlg)
    {
        EnvelopeExtractorDlg->setWindowTitle(QApplication::translate("EnvelopeExtractorDlg", "Envelope Extractor Visual Debug", 0));
        label->setText(QApplication::translate("EnvelopeExtractorDlg", "Message", 0));
        messageLabel->setText(QApplication::translate("EnvelopeExtractorDlg", "no message", 0));
        autoCheckBox->setText(QApplication::translate("EnvelopeExtractorDlg", "auto", 0));
        nextPushButton->setText(QApplication::translate("EnvelopeExtractorDlg", "Next", 0));
        skipPushButton->setText(QApplication::translate("EnvelopeExtractorDlg", "Skip", 0));
    } // retranslateUi

};

namespace Ui {
    class EnvelopeExtractorDlg: public Ui_EnvelopeExtractorDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENVELOPEEXTRACTORDLG_H
