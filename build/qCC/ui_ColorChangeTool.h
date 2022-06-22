/********************************************************************************
** Form generated from reading UI file 'ColorChangeTool.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORCHANGETOOL_H
#define UI_COLORCHANGETOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColorChangeTool
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QPushButton *cloneBtn;
    QPushButton *cloneBtn_2;
    QPushButton *cloneBtn_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSlider *redSlider;
    QSpinBox *redSpinBox;
    QSlider *greenSlider;
    QSpinBox *greenSpinBox;
    QSlider *blueSlider;
    QSpinBox *blueSpinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ColorChangeTool)
    {
        if (ColorChangeTool->objectName().isEmpty())
            ColorChangeTool->setObjectName(QStringLiteral("ColorChangeTool"));
        ColorChangeTool->resize(371, 255);
        verticalLayout = new QVBoxLayout(ColorChangeTool);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_2 = new QWidget(ColorChangeTool);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        cloneBtn = new QPushButton(widget_2);
        cloneBtn->setObjectName(QStringLiteral("cloneBtn"));
        cloneBtn->setGeometry(QRect(10, 10, 89, 25));
        cloneBtn_2 = new QPushButton(widget_2);
        cloneBtn_2->setObjectName(QStringLiteral("cloneBtn_2"));
        cloneBtn_2->setGeometry(QRect(10, 40, 121, 25));
        cloneBtn_3 = new QPushButton(widget_2);
        cloneBtn_3->setObjectName(QStringLiteral("cloneBtn_3"));
        cloneBtn_3->setGeometry(QRect(110, 10, 81, 25));

        verticalLayout->addWidget(widget_2);

        widget = new QWidget(ColorChangeTool);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        redSlider = new QSlider(widget);
        redSlider->setObjectName(QStringLiteral("redSlider"));
        redSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(redSlider, 0, 0, 1, 1);

        redSpinBox = new QSpinBox(widget);
        redSpinBox->setObjectName(QStringLiteral("redSpinBox"));

        gridLayout->addWidget(redSpinBox, 0, 1, 1, 1);

        greenSlider = new QSlider(widget);
        greenSlider->setObjectName(QStringLiteral("greenSlider"));
        greenSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(greenSlider, 1, 0, 1, 1);

        greenSpinBox = new QSpinBox(widget);
        greenSpinBox->setObjectName(QStringLiteral("greenSpinBox"));

        gridLayout->addWidget(greenSpinBox, 1, 1, 1, 1);

        blueSlider = new QSlider(widget);
        blueSlider->setObjectName(QStringLiteral("blueSlider"));
        blueSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(blueSlider, 2, 0, 1, 1);

        blueSpinBox = new QSpinBox(widget);
        blueSpinBox->setObjectName(QStringLiteral("blueSpinBox"));

        gridLayout->addWidget(blueSpinBox, 2, 1, 1, 1);


        verticalLayout->addWidget(widget);

        buttonBox = new QDialogButtonBox(ColorChangeTool);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ColorChangeTool);
        QObject::connect(buttonBox, SIGNAL(accepted()), ColorChangeTool, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ColorChangeTool, SLOT(reject()));

        QMetaObject::connectSlotsByName(ColorChangeTool);
    } // setupUi

    void retranslateUi(QDialog *ColorChangeTool)
    {
        ColorChangeTool->setWindowTitle(QApplication::translate("ColorChangeTool", "Dialog", 0));
        cloneBtn->setText(QApplication::translate("ColorChangeTool", "clone", 0));
        cloneBtn_2->setText(QApplication::translate("ColorChangeTool", "\344\274\230\345\214\226\345\275\223\345\211\215\350\275\250\350\277\271", 0));
        cloneBtn_3->setText(QApplication::translate("ColorChangeTool", "load path", 0));
    } // retranslateUi

};

namespace Ui {
    class ColorChangeTool: public Ui_ColorChangeTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORCHANGETOOL_H
