/********************************************************************************
** Form generated from reading UI file 'SgsTagging.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SGSTAGGING_H
#define UI_SGSTAGGING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SgsTagging
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *orientationTabWidget;
    QWidget *dipTab;
    QGridLayout *gridLayout_4;
    QLabel *label_3;
    QDoubleSpinBox *dipDoubleSpinBox;
    QLabel *label_4;
    QDoubleSpinBox *dipDirDoubleSpinBox;
    QCheckBox *upwardCheckBox;
    QWidget *normTab;
    QVBoxLayout *verticalLayout_2;
    QDoubleSpinBox *nxDoubleSpinBox;
    QDoubleSpinBox *nyDoubleSpinBox;
    QDoubleSpinBox *nzDoubleSpinBox;
    QGroupBox *dimGroupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QDoubleSpinBox *wDoubleSpinBox;
    QLabel *label_2;
    QDoubleSpinBox *hDoubleSpinBox;
    QGroupBox *centerGroupBox;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *cxAxisDoubleSpinBox;
    QToolButton *pickCenterToolButton;
    QDoubleSpinBox *cyAxisDoubleSpinBox;
    QDoubleSpinBox *czAxisDoubleSpinBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SgsTagging)
    {
        if (SgsTagging->objectName().isEmpty())
            SgsTagging->setObjectName(QStringLiteral("SgsTagging"));
        SgsTagging->resize(300, 499);
        verticalLayout = new QVBoxLayout(SgsTagging);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        orientationTabWidget = new QTabWidget(SgsTagging);
        orientationTabWidget->setObjectName(QStringLiteral("orientationTabWidget"));
        dipTab = new QWidget();
        dipTab->setObjectName(QStringLiteral("dipTab"));
        gridLayout_4 = new QGridLayout(dipTab);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_3 = new QLabel(dipTab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_4->addWidget(label_3, 0, 0, 1, 1);

        dipDoubleSpinBox = new QDoubleSpinBox(dipTab);
        dipDoubleSpinBox->setObjectName(QStringLiteral("dipDoubleSpinBox"));
        dipDoubleSpinBox->setSuffix(QString::fromUtf8("\302\260"));
        dipDoubleSpinBox->setDecimals(4);
        dipDoubleSpinBox->setMinimum(0);
        dipDoubleSpinBox->setMaximum(90);

        gridLayout_4->addWidget(dipDoubleSpinBox, 0, 1, 1, 1);

        label_4 = new QLabel(dipTab);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_4->addWidget(label_4, 1, 0, 1, 1);

        dipDirDoubleSpinBox = new QDoubleSpinBox(dipTab);
        dipDirDoubleSpinBox->setObjectName(QStringLiteral("dipDirDoubleSpinBox"));
        dipDirDoubleSpinBox->setSuffix(QString::fromUtf8("\302\260"));
        dipDirDoubleSpinBox->setDecimals(4);
        dipDirDoubleSpinBox->setMinimum(0);
        dipDirDoubleSpinBox->setMaximum(360);

        gridLayout_4->addWidget(dipDirDoubleSpinBox, 1, 1, 1, 1);

        upwardCheckBox = new QCheckBox(dipTab);
        upwardCheckBox->setObjectName(QStringLiteral("upwardCheckBox"));
        upwardCheckBox->setChecked(true);

        gridLayout_4->addWidget(upwardCheckBox, 2, 0, 1, 1);

        orientationTabWidget->addTab(dipTab, QString());
        normTab = new QWidget();
        normTab->setObjectName(QStringLiteral("normTab"));
        verticalLayout_2 = new QVBoxLayout(normTab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        nxDoubleSpinBox = new QDoubleSpinBox(normTab);
        nxDoubleSpinBox->setObjectName(QStringLiteral("nxDoubleSpinBox"));
        nxDoubleSpinBox->setPrefix(QStringLiteral("Nx = "));
        nxDoubleSpinBox->setDecimals(8);
        nxDoubleSpinBox->setMinimum(-1e+06);
        nxDoubleSpinBox->setMaximum(1e+06);

        verticalLayout_2->addWidget(nxDoubleSpinBox);

        nyDoubleSpinBox = new QDoubleSpinBox(normTab);
        nyDoubleSpinBox->setObjectName(QStringLiteral("nyDoubleSpinBox"));
        nyDoubleSpinBox->setPrefix(QStringLiteral("Ny = "));
        nyDoubleSpinBox->setDecimals(8);
        nyDoubleSpinBox->setMinimum(-1e+06);
        nyDoubleSpinBox->setMaximum(1e+06);

        verticalLayout_2->addWidget(nyDoubleSpinBox);

        nzDoubleSpinBox = new QDoubleSpinBox(normTab);
        nzDoubleSpinBox->setObjectName(QStringLiteral("nzDoubleSpinBox"));
        nzDoubleSpinBox->setPrefix(QStringLiteral("Nz = "));
        nzDoubleSpinBox->setDecimals(8);
        nzDoubleSpinBox->setMinimum(-1e+06);
        nzDoubleSpinBox->setMaximum(1e+06);

        verticalLayout_2->addWidget(nzDoubleSpinBox);

        orientationTabWidget->addTab(normTab, QString());

        verticalLayout->addWidget(orientationTabWidget);

        dimGroupBox = new QGroupBox(SgsTagging);
        dimGroupBox->setObjectName(QStringLiteral("dimGroupBox"));
        dimGroupBox->setFlat(true);
        gridLayout_2 = new QGridLayout(dimGroupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(dimGroupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        wDoubleSpinBox = new QDoubleSpinBox(dimGroupBox);
        wDoubleSpinBox->setObjectName(QStringLiteral("wDoubleSpinBox"));
        wDoubleSpinBox->setDecimals(8);
        wDoubleSpinBox->setMinimum(1e-06);
        wDoubleSpinBox->setMaximum(1e+06);
        wDoubleSpinBox->setValue(10);

        gridLayout_2->addWidget(wDoubleSpinBox, 0, 1, 1, 1);

        label_2 = new QLabel(dimGroupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        hDoubleSpinBox = new QDoubleSpinBox(dimGroupBox);
        hDoubleSpinBox->setObjectName(QStringLiteral("hDoubleSpinBox"));
        hDoubleSpinBox->setDecimals(8);
        hDoubleSpinBox->setMinimum(1e-06);
        hDoubleSpinBox->setMaximum(1e+06);
        hDoubleSpinBox->setValue(10);

        gridLayout_2->addWidget(hDoubleSpinBox, 1, 1, 1, 1);


        verticalLayout->addWidget(dimGroupBox);

        centerGroupBox = new QGroupBox(SgsTagging);
        centerGroupBox->setObjectName(QStringLiteral("centerGroupBox"));
        centerGroupBox->setFlat(true);
        gridLayout_3 = new QGridLayout(centerGroupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        cxAxisDoubleSpinBox = new QDoubleSpinBox(centerGroupBox);
        cxAxisDoubleSpinBox->setObjectName(QStringLiteral("cxAxisDoubleSpinBox"));
        cxAxisDoubleSpinBox->setPrefix(QStringLiteral("X: "));
        cxAxisDoubleSpinBox->setDecimals(8);
        cxAxisDoubleSpinBox->setMinimum(-1e+09);
        cxAxisDoubleSpinBox->setMaximum(1e+09);

        gridLayout_3->addWidget(cxAxisDoubleSpinBox, 0, 1, 1, 1);

        pickCenterToolButton = new QToolButton(centerGroupBox);
        pickCenterToolButton->setObjectName(QStringLiteral("pickCenterToolButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/CC/images/ccPointPicking.png"), QSize(), QIcon::Normal, QIcon::Off);
        pickCenterToolButton->setIcon(icon);
        pickCenterToolButton->setCheckable(true);

        gridLayout_3->addWidget(pickCenterToolButton, 1, 0, 1, 1);

        cyAxisDoubleSpinBox = new QDoubleSpinBox(centerGroupBox);
        cyAxisDoubleSpinBox->setObjectName(QStringLiteral("cyAxisDoubleSpinBox"));
        cyAxisDoubleSpinBox->setPrefix(QStringLiteral("Y: "));
        cyAxisDoubleSpinBox->setDecimals(8);
        cyAxisDoubleSpinBox->setMinimum(-1e+09);
        cyAxisDoubleSpinBox->setMaximum(1e+09);

        gridLayout_3->addWidget(cyAxisDoubleSpinBox, 1, 1, 1, 1);

        czAxisDoubleSpinBox = new QDoubleSpinBox(centerGroupBox);
        czAxisDoubleSpinBox->setObjectName(QStringLiteral("czAxisDoubleSpinBox"));
        czAxisDoubleSpinBox->setPrefix(QStringLiteral("Z: "));
        czAxisDoubleSpinBox->setDecimals(8);
        czAxisDoubleSpinBox->setMinimum(-1e+09);
        czAxisDoubleSpinBox->setMaximum(1e+09);

        gridLayout_3->addWidget(czAxisDoubleSpinBox, 2, 1, 1, 1);


        verticalLayout->addWidget(centerGroupBox);

        verticalSpacer = new QSpacerItem(20, 24, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(SgsTagging);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SgsTagging);
        QObject::connect(buttonBox, SIGNAL(rejected()), SgsTagging, SLOT(reject()));

        orientationTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SgsTagging);
    } // setupUi

    void retranslateUi(QDialog *SgsTagging)
    {
        SgsTagging->setWindowTitle(QApplication::translate("SgsTagging", "Plane properties", 0));
        label_3->setText(QApplication::translate("SgsTagging", "dip", 0));
        label_4->setText(QApplication::translate("SgsTagging", "dip direction", 0));
#ifndef QT_NO_TOOLTIP
        upwardCheckBox->setToolTip(QApplication::translate("SgsTagging", "Whether the plane normal should point upward (Z+) or downward (Z-)", 0));
#endif // QT_NO_TOOLTIP
        upwardCheckBox->setText(QApplication::translate("SgsTagging", "upward", 0));
        orientationTabWidget->setTabText(orientationTabWidget->indexOf(dipTab), QApplication::translate("SgsTagging", "Dip / dip direction", 0));
        orientationTabWidget->setTabText(orientationTabWidget->indexOf(normTab), QApplication::translate("SgsTagging", "Normal", 0));
        dimGroupBox->setTitle(QApplication::translate("SgsTagging", "Dimensions", 0));
        label->setText(QApplication::translate("SgsTagging", "width", 0));
#ifndef QT_NO_TOOLTIP
        wDoubleSpinBox->setToolTip(QApplication::translate("SgsTagging", "Plane width", 0));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("SgsTagging", "height", 0));
#ifndef QT_NO_TOOLTIP
        hDoubleSpinBox->setToolTip(QApplication::translate("SgsTagging", "Plane height", 0));
#endif // QT_NO_TOOLTIP
        centerGroupBox->setTitle(QApplication::translate("SgsTagging", "Center", 0));
#ifndef QT_NO_TOOLTIP
        pickCenterToolButton->setToolTip(QApplication::translate("SgsTagging", "Pick the plane center (click again to cancel)", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class SgsTagging: public Ui_SgsTagging {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SGSTAGGING_H
