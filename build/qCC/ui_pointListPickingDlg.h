/********************************************************************************
** Form generated from reading UI file 'pointListPickingDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINTLISTPICKINGDLG_H
#define UI_POINTLISTPICKINGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PointListPickingDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *revertToolButton;
    QToolButton *exportToolButton;
    QToolButton *validToolButton;
    QToolButton *cancelToolButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLineEdit *countLineEdit;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *markerSizeSpinBox;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QSpinBox *startIndexSpinBox;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *showGlobalCoordsCheckBox;

    void setupUi(QDialog *PointListPickingDlg)
    {
        if (PointListPickingDlg->objectName().isEmpty())
            PointListPickingDlg->setObjectName(QStringLiteral("PointListPickingDlg"));
        PointListPickingDlg->resize(500, 227);
        PointListPickingDlg->setMinimumSize(QSize(500, 0));
        verticalLayout = new QVBoxLayout(PointListPickingDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        revertToolButton = new QToolButton(PointListPickingDlg);
        revertToolButton->setObjectName(QStringLiteral("revertToolButton"));
        revertToolButton->setEnabled(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/CC/images/smallReset.png"), QSize(), QIcon::Normal, QIcon::Off);
        revertToolButton->setIcon(icon);

        horizontalLayout->addWidget(revertToolButton);

        exportToolButton = new QToolButton(PointListPickingDlg);
        exportToolButton->setObjectName(QStringLiteral("exportToolButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/CC/images/ccSave.png"), QSize(), QIcon::Normal, QIcon::Off);
        exportToolButton->setIcon(icon1);
        exportToolButton->setPopupMode(QToolButton::MenuButtonPopup);

        horizontalLayout->addWidget(exportToolButton);

        validToolButton = new QToolButton(PointListPickingDlg);
        validToolButton->setObjectName(QStringLiteral("validToolButton"));
        validToolButton->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/CC/images/smallValidate.png"), QSize(), QIcon::Normal, QIcon::Off);
        validToolButton->setIcon(icon2);

        horizontalLayout->addWidget(validToolButton);

        cancelToolButton = new QToolButton(PointListPickingDlg);
        cancelToolButton->setObjectName(QStringLiteral("cancelToolButton"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/CC/images/smallCancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelToolButton->setIcon(icon3);

        horizontalLayout->addWidget(cancelToolButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(PointListPickingDlg);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        countLineEdit = new QLineEdit(PointListPickingDlg);
        countLineEdit->setObjectName(QStringLiteral("countLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(countLineEdit->sizePolicy().hasHeightForWidth());
        countLineEdit->setSizePolicy(sizePolicy);
        countLineEdit->setMaximumSize(QSize(40, 16777215));
        countLineEdit->setText(QStringLiteral("0"));
        countLineEdit->setMaxLength(255);
        countLineEdit->setFrame(false);
        countLineEdit->setReadOnly(true);

        horizontalLayout->addWidget(countLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(PointListPickingDlg);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setText(QStringLiteral("X"));
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setText(QStringLiteral("Y"));
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setText(QStringLiteral("Z"));
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setProperty("showDropIndicator", QVariant(false));
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget->horizontalHeader()->setDefaultSectionSize(115);
        tableWidget->verticalHeader()->setDefaultSectionSize(18);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(PointListPickingDlg);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        markerSizeSpinBox = new QSpinBox(PointListPickingDlg);
        markerSizeSpinBox->setObjectName(QStringLiteral("markerSizeSpinBox"));
        markerSizeSpinBox->setMinimum(1);
        markerSizeSpinBox->setMaximum(99);
        markerSizeSpinBox->setValue(4);

        horizontalLayout_2->addWidget(markerSizeSpinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_3 = new QLabel(PointListPickingDlg);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        startIndexSpinBox = new QSpinBox(PointListPickingDlg);
        startIndexSpinBox->setObjectName(QStringLiteral("startIndexSpinBox"));
        startIndexSpinBox->setMaximum(10000);
        startIndexSpinBox->setSingleStep(1);
        startIndexSpinBox->setValue(1);

        horizontalLayout_2->addWidget(startIndexSpinBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        showGlobalCoordsCheckBox = new QCheckBox(PointListPickingDlg);
        showGlobalCoordsCheckBox->setObjectName(QStringLiteral("showGlobalCoordsCheckBox"));
        showGlobalCoordsCheckBox->setEnabled(false);

        horizontalLayout_2->addWidget(showGlobalCoordsCheckBox);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(PointListPickingDlg);

        QMetaObject::connectSlotsByName(PointListPickingDlg);
    } // setupUi

    void retranslateUi(QDialog *PointListPickingDlg)
    {
        PointListPickingDlg->setWindowTitle(QApplication::translate("PointListPickingDlg", "Point list picking", 0));
#ifndef QT_NO_STATUSTIP
        revertToolButton->setStatusTip(QApplication::translate("PointListPickingDlg", "Remove last entry", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        revertToolButton->setWhatsThis(QApplication::translate("PointListPickingDlg", "Remove last entry", 0));
#endif // QT_NO_WHATSTHIS
        revertToolButton->setText(QApplication::translate("PointListPickingDlg", "remove last", 0));
#ifndef QT_NO_TOOLTIP
        exportToolButton->setToolTip(QApplication::translate("PointListPickingDlg", "export to ASCII file", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        exportToolButton->setStatusTip(QApplication::translate("PointListPickingDlg", "export to ASCII file", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        validToolButton->setStatusTip(QApplication::translate("PointListPickingDlg", "Convert list to new cloud (and close dialog)", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        validToolButton->setWhatsThis(QApplication::translate("PointListPickingDlg", "Convert list to new cloud (and close dialog)", 0));
#endif // QT_NO_WHATSTHIS
        validToolButton->setText(QApplication::translate("PointListPickingDlg", "to cloud", 0));
#ifndef QT_NO_TOOLTIP
        cancelToolButton->setToolTip(QApplication::translate("PointListPickingDlg", "Close dialog (list will be lost)", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        cancelToolButton->setStatusTip(QApplication::translate("PointListPickingDlg", "Close dialog (list will be lost)", 0));
#endif // QT_NO_STATUSTIP
        cancelToolButton->setText(QApplication::translate("PointListPickingDlg", "stop", 0));
        label_2->setText(QApplication::translate("PointListPickingDlg", "count", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PointListPickingDlg", "Index", 0));
        label->setText(QApplication::translate("PointListPickingDlg", "marker size", 0));
        label_3->setText(QApplication::translate("PointListPickingDlg", "start index", 0));
#ifndef QT_NO_TOOLTIP
        showGlobalCoordsCheckBox->setToolTip(QApplication::translate("PointListPickingDlg", "Show global coordinates (instead of shifted ones)", 0));
#endif // QT_NO_TOOLTIP
        showGlobalCoordsCheckBox->setText(QApplication::translate("PointListPickingDlg", "show global coordinates", 0));
    } // retranslateUi

};

namespace Ui {
    class PointListPickingDlg: public Ui_PointListPickingDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINTLISTPICKINGDLG_H
