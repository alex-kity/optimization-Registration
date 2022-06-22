/********************************************************************************
** Form generated from reading UI file 'primitiveDistanceDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIMITIVEDISTANCEDLG_H
#define UI_PRIMITIVEDISTANCEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_primitiveDistanceDlg
{
public:
    QLabel *label;
    QCheckBox *signedDistCheckBox;
    QCheckBox *flipNormalsCheckBox;
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QCheckBox *treatPlanesAsBoundedCheckBox;

    void setupUi(QDialog *primitiveDistanceDlg)
    {
        if (primitiveDistanceDlg->objectName().isEmpty())
            primitiveDistanceDlg->setObjectName(QStringLiteral("primitiveDistanceDlg"));
        primitiveDistanceDlg->resize(450, 312);
        label = new QLabel(primitiveDistanceDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 351, 91));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(true);
        signedDistCheckBox = new QCheckBox(primitiveDistanceDlg);
        signedDistCheckBox->setObjectName(QStringLiteral("signedDistCheckBox"));
        signedDistCheckBox->setGeometry(QRect(30, 140, 102, 17));
        flipNormalsCheckBox = new QCheckBox(primitiveDistanceDlg);
        flipNormalsCheckBox->setObjectName(QStringLiteral("flipNormalsCheckBox"));
        flipNormalsCheckBox->setEnabled(false);
        flipNormalsCheckBox->setGeometry(QRect(140, 140, 131, 17));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(flipNormalsCheckBox->sizePolicy().hasHeightForWidth());
        flipNormalsCheckBox->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(primitiveDistanceDlg);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(4, 270, 371, 30));
        hboxLayout = new QHBoxLayout(layoutWidget);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setEnabled(true);

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy1);

        hboxLayout->addWidget(cancelButton);

        treatPlanesAsBoundedCheckBox = new QCheckBox(primitiveDistanceDlg);
        treatPlanesAsBoundedCheckBox->setObjectName(QStringLiteral("treatPlanesAsBoundedCheckBox"));
        treatPlanesAsBoundedCheckBox->setEnabled(true);
        treatPlanesAsBoundedCheckBox->setGeometry(QRect(30, 110, 151, 17));

        retranslateUi(primitiveDistanceDlg);

        QMetaObject::connectSlotsByName(primitiveDistanceDlg);
    } // setupUi

    void retranslateUi(QDialog *primitiveDistanceDlg)
    {
        primitiveDistanceDlg->setWindowTitle(QApplication::translate("primitiveDistanceDlg", "Distance to Primitive", 0));
        label->setText(QApplication::translate("primitiveDistanceDlg", "<html><head/><body><p>[NOTE]: This tool will measure each clouds points to either a plane, box, sphere, cylinder, or cone.</p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        signedDistCheckBox->setToolTip(QApplication::translate("primitiveDistanceDlg", "compute signed distances", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        signedDistCheckBox->setStatusTip(QApplication::translate("primitiveDistanceDlg", "compute signed distances", 0));
#endif // QT_NO_STATUSTIP
        signedDistCheckBox->setText(QApplication::translate("primitiveDistanceDlg", "signed distances", 0));
        flipNormalsCheckBox->setText(QApplication::translate("primitiveDistanceDlg", "flip normals", 0));
        okButton->setText(QApplication::translate("primitiveDistanceDlg", "Ok", 0));
        cancelButton->setText(QApplication::translate("primitiveDistanceDlg", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        treatPlanesAsBoundedCheckBox->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        treatPlanesAsBoundedCheckBox->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        treatPlanesAsBoundedCheckBox->setText(QApplication::translate("primitiveDistanceDlg", "Treat planes as bounded", 0));
    } // retranslateUi

};

namespace Ui {
    class primitiveDistanceDlg: public Ui_primitiveDistanceDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIMITIVEDISTANCEDLG_H
