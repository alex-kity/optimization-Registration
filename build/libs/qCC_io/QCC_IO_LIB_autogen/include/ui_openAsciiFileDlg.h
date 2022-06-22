/********************************************************************************
** Form generated from reading UI file 'openAsciiFileDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENASCIIFILEDLG_H
#define UI_OPENASCIIFILEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AsciiOpenDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEditFileName;
    QLabel *label;
    QLabel *headerLabel;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEditSeparator;
    QLabel *asciiCodeLabel;
    QHBoxLayout *hboxLayout;
    QToolButton *toolButtonShortcutSpace;
    QToolButton *toolButtonShortcutComma;
    QToolButton *toolButtonShortcutSemicolon;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *commaDecimalCheckBox;
    QCheckBox *show2DLabelsCheckBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpinBox *spinBoxSkipLines;
    QLabel *commentLinesSkippedLabel;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *extractSFNamesFrom1stLineCheckBox;
    QSpacerItem *horizontalSpacer_4;
    QWidget *buttonWidget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QDoubleSpinBox *maxCloudSizeDoubleSpinBox;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *applyButton;
    QPushButton *applyAllButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *AsciiOpenDialog)
    {
        if (AsciiOpenDialog->objectName().isEmpty())
            AsciiOpenDialog->setObjectName(QStringLiteral("AsciiOpenDialog"));
        AsciiOpenDialog->resize(1008, 657);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AsciiOpenDialog->sizePolicy().hasHeightForWidth());
        AsciiOpenDialog->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(AsciiOpenDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(AsciiOpenDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEditFileName = new QLineEdit(AsciiOpenDialog);
        lineEditFileName->setObjectName(QStringLiteral("lineEditFileName"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditFileName->sizePolicy().hasHeightForWidth());
        lineEditFileName->setSizePolicy(sizePolicy1);
        lineEditFileName->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEditFileName);


        verticalLayout->addLayout(horizontalLayout_2);

        label = new QLabel(AsciiOpenDialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        headerLabel = new QLabel(AsciiOpenDialog);
        headerLabel->setObjectName(QStringLiteral("headerLabel"));
        headerLabel->setStyleSheet(QStringLiteral("color: grey;"));

        verticalLayout->addWidget(headerLabel);

        scrollArea = new QScrollArea(AsciiOpenDialog);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 990, 486));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(scrollAreaWidgetContents);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget->setCornerButtonEnabled(false);
        tableWidget->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(tableWidget);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(AsciiOpenDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEditSeparator = new QLineEdit(AsciiOpenDialog);
        lineEditSeparator->setObjectName(QStringLiteral("lineEditSeparator"));
        sizePolicy.setHeightForWidth(lineEditSeparator->sizePolicy().hasHeightForWidth());
        lineEditSeparator->setSizePolicy(sizePolicy);
        lineEditSeparator->setMaximumSize(QSize(30, 16777215));
        lineEditSeparator->setMaxLength(1);

        horizontalLayout->addWidget(lineEditSeparator);

        asciiCodeLabel = new QLabel(AsciiOpenDialog);
        asciiCodeLabel->setObjectName(QStringLiteral("asciiCodeLabel"));

        horizontalLayout->addWidget(asciiCodeLabel);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        toolButtonShortcutSpace = new QToolButton(AsciiOpenDialog);
        toolButtonShortcutSpace->setObjectName(QStringLiteral("toolButtonShortcutSpace"));

        hboxLayout->addWidget(toolButtonShortcutSpace);

        toolButtonShortcutComma = new QToolButton(AsciiOpenDialog);
        toolButtonShortcutComma->setObjectName(QStringLiteral("toolButtonShortcutComma"));
        toolButtonShortcutComma->setText(QStringLiteral(","));

        hboxLayout->addWidget(toolButtonShortcutComma);

        toolButtonShortcutSemicolon = new QToolButton(AsciiOpenDialog);
        toolButtonShortcutSemicolon->setObjectName(QStringLiteral("toolButtonShortcutSemicolon"));
        toolButtonShortcutSemicolon->setText(QStringLiteral(";"));

        hboxLayout->addWidget(toolButtonShortcutSemicolon);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(horizontalSpacer_2);

        commaDecimalCheckBox = new QCheckBox(AsciiOpenDialog);
        commaDecimalCheckBox->setObjectName(QStringLiteral("commaDecimalCheckBox"));

        hboxLayout->addWidget(commaDecimalCheckBox);

        show2DLabelsCheckBox = new QCheckBox(AsciiOpenDialog);
        show2DLabelsCheckBox->setObjectName(QStringLiteral("show2DLabelsCheckBox"));

        hboxLayout->addWidget(show2DLabelsCheckBox);


        horizontalLayout->addLayout(hboxLayout);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(AsciiOpenDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        spinBoxSkipLines = new QSpinBox(AsciiOpenDialog);
        spinBoxSkipLines->setObjectName(QStringLiteral("spinBoxSkipLines"));
        spinBoxSkipLines->setMaximum(999);

        horizontalLayout_3->addWidget(spinBoxSkipLines);

        commentLinesSkippedLabel = new QLabel(AsciiOpenDialog);
        commentLinesSkippedLabel->setObjectName(QStringLiteral("commentLinesSkippedLabel"));

        horizontalLayout_3->addWidget(commentLinesSkippedLabel);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        extractSFNamesFrom1stLineCheckBox = new QCheckBox(AsciiOpenDialog);
        extractSFNamesFrom1stLineCheckBox->setObjectName(QStringLiteral("extractSFNamesFrom1stLineCheckBox"));
        extractSFNamesFrom1stLineCheckBox->setEnabled(false);

        horizontalLayout_3->addWidget(extractSFNamesFrom1stLineCheckBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_3);

        buttonWidget = new QWidget(AsciiOpenDialog);
        buttonWidget->setObjectName(QStringLiteral("buttonWidget"));
        horizontalLayout_5 = new QHBoxLayout(buttonWidget);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(buttonWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        maxCloudSizeDoubleSpinBox = new QDoubleSpinBox(buttonWidget);
        maxCloudSizeDoubleSpinBox->setObjectName(QStringLiteral("maxCloudSizeDoubleSpinBox"));
        maxCloudSizeDoubleSpinBox->setDecimals(2);
        maxCloudSizeDoubleSpinBox->setMinimum(0.01);
        maxCloudSizeDoubleSpinBox->setMaximum(1e+06);
        maxCloudSizeDoubleSpinBox->setValue(128);

        horizontalLayout_5->addWidget(maxCloudSizeDoubleSpinBox);

        horizontalSpacer_5 = new QSpacerItem(157, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        applyButton = new QPushButton(buttonWidget);
        applyButton->setObjectName(QStringLiteral("applyButton"));

        horizontalLayout_5->addWidget(applyButton);

        applyAllButton = new QPushButton(buttonWidget);
        applyAllButton->setObjectName(QStringLiteral("applyAllButton"));

        horizontalLayout_5->addWidget(applyAllButton);

        cancelButton = new QPushButton(buttonWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_5->addWidget(cancelButton);


        verticalLayout->addWidget(buttonWidget);


        retranslateUi(AsciiOpenDialog);

        QMetaObject::connectSlotsByName(AsciiOpenDialog);
    } // setupUi

    void retranslateUi(QDialog *AsciiOpenDialog)
    {
        AsciiOpenDialog->setWindowTitle(QApplication::translate("AsciiOpenDialog", "Open Ascii File", 0));
        label_3->setText(QApplication::translate("AsciiOpenDialog", "Source", 0));
        label->setText(QApplication::translate("AsciiOpenDialog", "Choose an attribute for each column:", 0));
        headerLabel->setText(QApplication::translate("AsciiOpenDialog", "Header:", 0));
        label_2->setText(QApplication::translate("AsciiOpenDialog", "Separator", 0));
        asciiCodeLabel->setText(QApplication::translate("AsciiOpenDialog", "(ASCII code:%i)", 0));
#ifndef QT_NO_TOOLTIP
        toolButtonShortcutSpace->setToolTip(QApplication::translate("AsciiOpenDialog", "space", 0));
#endif // QT_NO_TOOLTIP
        toolButtonShortcutSpace->setText(QApplication::translate("AsciiOpenDialog", "whitespace ", 0));
#ifndef QT_NO_TOOLTIP
        toolButtonShortcutComma->setToolTip(QApplication::translate("AsciiOpenDialog", "comma", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        toolButtonShortcutSemicolon->setToolTip(QApplication::translate("AsciiOpenDialog", "semicolon", 0));
#endif // QT_NO_TOOLTIP
        commaDecimalCheckBox->setText(QApplication::translate("AsciiOpenDialog", "use comma as decimal character", 0));
#ifndef QT_NO_TOOLTIP
        show2DLabelsCheckBox->setToolTip(QApplication::translate("AsciiOpenDialog", "Show labels in 2D (not recommended over 50).\n"
"Otherwise labels are shown in 3D.", 0));
#endif // QT_NO_TOOLTIP
        show2DLabelsCheckBox->setText(QApplication::translate("AsciiOpenDialog", "Show labels in 2D", 0));
        label_4->setText(QApplication::translate("AsciiOpenDialog", "Skip lines", 0));
        commentLinesSkippedLabel->setText(QApplication::translate("AsciiOpenDialog", "+ comment/header lines skipped: 0", 0));
        extractSFNamesFrom1stLineCheckBox->setText(QApplication::translate("AsciiOpenDialog", "extract scalar field names from first line", 0));
        label_5->setText(QApplication::translate("AsciiOpenDialog", "Max number of points per cloud", 0));
        maxCloudSizeDoubleSpinBox->setSuffix(QApplication::translate("AsciiOpenDialog", " Million", 0));
        applyButton->setText(QApplication::translate("AsciiOpenDialog", "Apply", 0));
        applyAllButton->setText(QApplication::translate("AsciiOpenDialog", "Apply all", 0));
        cancelButton->setText(QApplication::translate("AsciiOpenDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class AsciiOpenDialog: public Ui_AsciiOpenDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENASCIIFILEDLG_H
