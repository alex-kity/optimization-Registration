/********************************************************************************
** Form generated from reading UI file 'pointPairRegistrationDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINTPAIRREGISTRATIONDLG_H
#define UI_POINTPAIRREGISTRATIONDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_pointPairRegistrationDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *showAlignedCheckBox;
    QToolButton *unstackAlignToolButton;
    QToolButton *typeAlignToolButton;
    QSpacerItem *horizontalSpacer;
    QToolButton *useSphereToolButton;
    QDoubleSpinBox *radiusDoubleSpinBox;
    QSpinBox *maxRmsSpinBox;
    QTableWidget *alignedPointsTableWidget;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *showReferenceCheckBox;
    QToolButton *unstackRefToolButton;
    QToolButton *typeRefToolButton;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *refPointsTableWidget;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *adjustScaleCheckBox;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QComboBox *rotComboBox;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *TxCheckBox;
    QCheckBox *TyCheckBox;
    QCheckBox *TzCheckBox;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *autoZoomCheckBox;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *alignToolButton;
    QToolButton *resetToolButton;
    QToolButton *validToolButton;
    QToolButton *cancelToolButton;

    void setupUi(QDialog *pointPairRegistrationDlg)
    {
        if (pointPairRegistrationDlg->objectName().isEmpty())
            pointPairRegistrationDlg->setObjectName(QStringLiteral("pointPairRegistrationDlg"));
        pointPairRegistrationDlg->resize(508, 380);
        verticalLayout = new QVBoxLayout(pointPairRegistrationDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        showAlignedCheckBox = new QCheckBox(pointPairRegistrationDlg);
        showAlignedCheckBox->setObjectName(QStringLiteral("showAlignedCheckBox"));
        showAlignedCheckBox->setStyleSheet(QStringLiteral("background-color: red; color: white;"));
        showAlignedCheckBox->setChecked(true);

        horizontalLayout->addWidget(showAlignedCheckBox);

        unstackAlignToolButton = new QToolButton(pointPairRegistrationDlg);
        unstackAlignToolButton->setObjectName(QStringLiteral("unstackAlignToolButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/CC/images/ccUnstack.png"), QSize(), QIcon::Normal, QIcon::Off);
        unstackAlignToolButton->setIcon(icon);

        horizontalLayout->addWidget(unstackAlignToolButton);

        typeAlignToolButton = new QToolButton(pointPairRegistrationDlg);
        typeAlignToolButton->setObjectName(QStringLiteral("typeAlignToolButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/CC/images/ccPencil.png"), QSize(), QIcon::Normal, QIcon::Off);
        typeAlignToolButton->setIcon(icon1);

        horizontalLayout->addWidget(typeAlignToolButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        useSphereToolButton = new QToolButton(pointPairRegistrationDlg);
        useSphereToolButton->setObjectName(QStringLiteral("useSphereToolButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/CC/images/smallSphere.png"), QSize(), QIcon::Normal, QIcon::Off);
        useSphereToolButton->setIcon(icon2);
        useSphereToolButton->setCheckable(true);

        horizontalLayout->addWidget(useSphereToolButton);

        radiusDoubleSpinBox = new QDoubleSpinBox(pointPairRegistrationDlg);
        radiusDoubleSpinBox->setObjectName(QStringLiteral("radiusDoubleSpinBox"));
        radiusDoubleSpinBox->setEnabled(false);
        radiusDoubleSpinBox->setPrefix(QStringLiteral("r = "));
        radiusDoubleSpinBox->setDecimals(3);
        radiusDoubleSpinBox->setMinimum(0.001);
        radiusDoubleSpinBox->setMaximum(1000);
        radiusDoubleSpinBox->setValue(20);

        horizontalLayout->addWidget(radiusDoubleSpinBox);

        maxRmsSpinBox = new QSpinBox(pointPairRegistrationDlg);
        maxRmsSpinBox->setObjectName(QStringLiteral("maxRmsSpinBox"));
        maxRmsSpinBox->setEnabled(false);
        maxRmsSpinBox->setSuffix(QStringLiteral("%"));
        maxRmsSpinBox->setPrefix(QStringLiteral("RMS < "));
        maxRmsSpinBox->setMinimum(1);
        maxRmsSpinBox->setMaximum(100);
        maxRmsSpinBox->setSingleStep(1);
        maxRmsSpinBox->setValue(10);

        horizontalLayout->addWidget(maxRmsSpinBox);


        verticalLayout->addLayout(horizontalLayout);

        alignedPointsTableWidget = new QTableWidget(pointPairRegistrationDlg);
        if (alignedPointsTableWidget->columnCount() < 5)
            alignedPointsTableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setText(QStringLiteral("X"));
        alignedPointsTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setText(QStringLiteral("Y"));
        alignedPointsTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setText(QStringLiteral("Z"));
        alignedPointsTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        alignedPointsTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        alignedPointsTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (alignedPointsTableWidget->rowCount() < 4)
            alignedPointsTableWidget->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setText(QStringLiteral("1"));
        alignedPointsTableWidget->setVerticalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setText(QStringLiteral("2"));
        alignedPointsTableWidget->setVerticalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setText(QStringLiteral("3"));
        alignedPointsTableWidget->setVerticalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setText(QStringLiteral("4"));
        alignedPointsTableWidget->setVerticalHeaderItem(3, __qtablewidgetitem8);
        alignedPointsTableWidget->setObjectName(QStringLiteral("alignedPointsTableWidget"));
        alignedPointsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        alignedPointsTableWidget->setProperty("showDropIndicator", QVariant(false));
        alignedPointsTableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        alignedPointsTableWidget->horizontalHeader()->setDefaultSectionSize(80);
        alignedPointsTableWidget->verticalHeader()->setDefaultSectionSize(18);

        verticalLayout->addWidget(alignedPointsTableWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        showReferenceCheckBox = new QCheckBox(pointPairRegistrationDlg);
        showReferenceCheckBox->setObjectName(QStringLiteral("showReferenceCheckBox"));
        showReferenceCheckBox->setStyleSheet(QStringLiteral("background-color: yellow;"));
        showReferenceCheckBox->setChecked(true);

        horizontalLayout_3->addWidget(showReferenceCheckBox);

        unstackRefToolButton = new QToolButton(pointPairRegistrationDlg);
        unstackRefToolButton->setObjectName(QStringLiteral("unstackRefToolButton"));
        unstackRefToolButton->setIcon(icon);

        horizontalLayout_3->addWidget(unstackRefToolButton);

        typeRefToolButton = new QToolButton(pointPairRegistrationDlg);
        typeRefToolButton->setObjectName(QStringLiteral("typeRefToolButton"));
        typeRefToolButton->setIcon(icon1);

        horizontalLayout_3->addWidget(typeRefToolButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        refPointsTableWidget = new QTableWidget(pointPairRegistrationDlg);
        if (refPointsTableWidget->columnCount() < 5)
            refPointsTableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setText(QStringLiteral("X"));
        refPointsTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setText(QStringLiteral("Y"));
        refPointsTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setText(QStringLiteral("Z"));
        refPointsTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        refPointsTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        refPointsTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem13);
        if (refPointsTableWidget->rowCount() < 4)
            refPointsTableWidget->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setText(QStringLiteral("1"));
        refPointsTableWidget->setVerticalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setText(QStringLiteral("2"));
        refPointsTableWidget->setVerticalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setText(QStringLiteral("3"));
        refPointsTableWidget->setVerticalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setText(QStringLiteral("4"));
        refPointsTableWidget->setVerticalHeaderItem(3, __qtablewidgetitem17);
        refPointsTableWidget->setObjectName(QStringLiteral("refPointsTableWidget"));
        refPointsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        refPointsTableWidget->setProperty("showDropIndicator", QVariant(false));
        refPointsTableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        refPointsTableWidget->horizontalHeader()->setDefaultSectionSize(80);
        refPointsTableWidget->verticalHeader()->setDefaultSectionSize(18);

        verticalLayout->addWidget(refPointsTableWidget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        adjustScaleCheckBox = new QCheckBox(pointPairRegistrationDlg);
        adjustScaleCheckBox->setObjectName(QStringLiteral("adjustScaleCheckBox"));

        horizontalLayout_4->addWidget(adjustScaleCheckBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        label = new QLabel(pointPairRegistrationDlg);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label);

        rotComboBox = new QComboBox(pointPairRegistrationDlg);
        rotComboBox->insertItems(0, QStringList()
         << QStringLiteral("XYZ")
         << QStringLiteral("X")
         << QStringLiteral("Y")
         << QStringLiteral("Z")
        );
        rotComboBox->setObjectName(QStringLiteral("rotComboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rotComboBox->sizePolicy().hasHeightForWidth());
        rotComboBox->setSizePolicy(sizePolicy1);
        rotComboBox->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_4->addWidget(rotComboBox);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        TxCheckBox = new QCheckBox(pointPairRegistrationDlg);
        TxCheckBox->setObjectName(QStringLiteral("TxCheckBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(TxCheckBox->sizePolicy().hasHeightForWidth());
        TxCheckBox->setSizePolicy(sizePolicy2);
        TxCheckBox->setText(QStringLiteral("Tx"));
        TxCheckBox->setChecked(true);

        horizontalLayout_4->addWidget(TxCheckBox);

        TyCheckBox = new QCheckBox(pointPairRegistrationDlg);
        TyCheckBox->setObjectName(QStringLiteral("TyCheckBox"));
        sizePolicy2.setHeightForWidth(TyCheckBox->sizePolicy().hasHeightForWidth());
        TyCheckBox->setSizePolicy(sizePolicy2);
        TyCheckBox->setText(QStringLiteral("Ty"));
        TyCheckBox->setChecked(true);

        horizontalLayout_4->addWidget(TyCheckBox);

        TzCheckBox = new QCheckBox(pointPairRegistrationDlg);
        TzCheckBox->setObjectName(QStringLiteral("TzCheckBox"));
        sizePolicy2.setHeightForWidth(TzCheckBox->sizePolicy().hasHeightForWidth());
        TzCheckBox->setSizePolicy(sizePolicy2);
        TzCheckBox->setText(QStringLiteral("Tz"));
        TzCheckBox->setChecked(true);

        horizontalLayout_4->addWidget(TzCheckBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        autoZoomCheckBox = new QCheckBox(pointPairRegistrationDlg);
        autoZoomCheckBox->setObjectName(QStringLiteral("autoZoomCheckBox"));
        autoZoomCheckBox->setChecked(true);

        horizontalLayout_2->addWidget(autoZoomCheckBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        alignToolButton = new QToolButton(pointPairRegistrationDlg);
        alignToolButton->setObjectName(QStringLiteral("alignToolButton"));
        alignToolButton->setEnabled(false);
        alignToolButton->setMinimumSize(QSize(0, 22));

        horizontalLayout_2->addWidget(alignToolButton);

        resetToolButton = new QToolButton(pointPairRegistrationDlg);
        resetToolButton->setObjectName(QStringLiteral("resetToolButton"));
        resetToolButton->setEnabled(false);

        horizontalLayout_2->addWidget(resetToolButton);

        validToolButton = new QToolButton(pointPairRegistrationDlg);
        validToolButton->setObjectName(QStringLiteral("validToolButton"));
        validToolButton->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/CC/images/smallValidate.png"), QSize(), QIcon::Normal, QIcon::Off);
        validToolButton->setIcon(icon3);

        horizontalLayout_2->addWidget(validToolButton);

        cancelToolButton = new QToolButton(pointPairRegistrationDlg);
        cancelToolButton->setObjectName(QStringLiteral("cancelToolButton"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/CC/images/smallCancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelToolButton->setIcon(icon4);

        horizontalLayout_2->addWidget(cancelToolButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(pointPairRegistrationDlg);
        QObject::connect(showReferenceCheckBox, SIGNAL(toggled(bool)), unstackRefToolButton, SLOT(setEnabled(bool)));
        QObject::connect(showAlignedCheckBox, SIGNAL(toggled(bool)), unstackAlignToolButton, SLOT(setEnabled(bool)));
        QObject::connect(useSphereToolButton, SIGNAL(toggled(bool)), radiusDoubleSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(useSphereToolButton, SIGNAL(toggled(bool)), maxRmsSpinBox, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(pointPairRegistrationDlg);
    } // setupUi

    void retranslateUi(QDialog *pointPairRegistrationDlg)
    {
        pointPairRegistrationDlg->setWindowTitle(QApplication::translate("pointPairRegistrationDlg", "Point list picking", 0));
        showAlignedCheckBox->setText(QApplication::translate("pointPairRegistrationDlg", "show 'to align' entities", 0));
#ifndef QT_NO_TOOLTIP
        useSphereToolButton->setToolTip(QApplication::translate("pointPairRegistrationDlg", "Pick spheres instead of single points (for clouds only)", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        radiusDoubleSpinBox->setToolTip(QApplication::translate("pointPairRegistrationDlg", "search radius (or the spheres radius if you know it)", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        maxRmsSpinBox->setToolTip(QApplication::translate("pointPairRegistrationDlg", "Max RMS (as a percentage of the radius)", 0));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem = alignedPointsTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem->setText(QApplication::translate("pointPairRegistrationDlg", "Error", 0));
        showReferenceCheckBox->setText(QApplication::translate("pointPairRegistrationDlg", "show 'reference' entities", 0));
        QTableWidgetItem *___qtablewidgetitem1 = refPointsTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem1->setText(QApplication::translate("pointPairRegistrationDlg", "Error", 0));
        adjustScaleCheckBox->setText(QApplication::translate("pointPairRegistrationDlg", "adjust scale", 0));
        label->setText(QApplication::translate("pointPairRegistrationDlg", "Rotation", 0));
#ifndef QT_NO_TOOLTIP
        rotComboBox->setToolTip(QApplication::translate("pointPairRegistrationDlg", "Constrains the rotation around a single axis (warning: experimental)", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        TxCheckBox->setToolTip(QApplication::translate("pointPairRegistrationDlg", "Constrains the translation along particular axes (warning: experimental)", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        TyCheckBox->setToolTip(QApplication::translate("pointPairRegistrationDlg", "Constrains the translation along particular axes (warning: experimental)", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        TzCheckBox->setToolTip(QApplication::translate("pointPairRegistrationDlg", "Constrains the translation along particular axes (warning: experimental)", 0));
#endif // QT_NO_TOOLTIP
        autoZoomCheckBox->setText(QApplication::translate("pointPairRegistrationDlg", "auto update zoom", 0));
        alignToolButton->setText(QApplication::translate("pointPairRegistrationDlg", "align", 0));
        resetToolButton->setText(QApplication::translate("pointPairRegistrationDlg", "reset", 0));
#ifndef QT_NO_STATUSTIP
        validToolButton->setStatusTip(QApplication::translate("pointPairRegistrationDlg", "Convert list to new cloud (and close dialog)", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        validToolButton->setWhatsThis(QApplication::translate("pointPairRegistrationDlg", "Convert list to new cloud (and close dialog)", 0));
#endif // QT_NO_WHATSTHIS
        validToolButton->setText(QApplication::translate("pointPairRegistrationDlg", "to cloud", 0));
#ifndef QT_NO_TOOLTIP
        cancelToolButton->setToolTip(QApplication::translate("pointPairRegistrationDlg", "Close dialog (list will be lost)", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        cancelToolButton->setStatusTip(QApplication::translate("pointPairRegistrationDlg", "Close dialog (list will be lost)", 0));
#endif // QT_NO_STATUSTIP
        cancelToolButton->setText(QApplication::translate("pointPairRegistrationDlg", "stop", 0));
    } // retranslateUi

};

namespace Ui {
    class pointPairRegistrationDlg: public Ui_pointPairRegistrationDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINTPAIRREGISTRATIONDLG_H
