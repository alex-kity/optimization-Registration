/********************************************************************************
** Form generated from reading UI file 'entitySelectionDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTITYSELECTIONDLG_H
#define UI_ENTITYSELECTIONDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EntitySelectionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QListWidget *listWidget;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *selectAllPushButton;
    QPushButton *selectNonePushButton;
    QSpacerItem *horizontalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EntitySelectionDialog)
    {
        if (EntitySelectionDialog->objectName().isEmpty())
            EntitySelectionDialog->setObjectName(QStringLiteral("EntitySelectionDialog"));
        EntitySelectionDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(EntitySelectionDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(EntitySelectionDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        listWidget = new QListWidget(EntitySelectionDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setAlternatingRowColors(true);

        verticalLayout->addWidget(listWidget);

        frame = new QFrame(EntitySelectionDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        selectAllPushButton = new QPushButton(frame);
        selectAllPushButton->setObjectName(QStringLiteral("selectAllPushButton"));

        horizontalLayout_2->addWidget(selectAllPushButton);

        selectNonePushButton = new QPushButton(frame);
        selectNonePushButton->setObjectName(QStringLiteral("selectNonePushButton"));

        horizontalLayout_2->addWidget(selectNonePushButton);

        horizontalSpacer_2 = new QSpacerItem(225, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        buttonBox = new QDialogButtonBox(frame);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout->addWidget(frame);


        retranslateUi(EntitySelectionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EntitySelectionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EntitySelectionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(EntitySelectionDialog);
    } // setupUi

    void retranslateUi(QDialog *EntitySelectionDialog)
    {
        EntitySelectionDialog->setWindowTitle(QApplication::translate("EntitySelectionDialog", "Entity selector", 0));
        label->setText(QApplication::translate("EntitySelectionDialog", "Select an entity:", 0));
        selectAllPushButton->setText(QApplication::translate("EntitySelectionDialog", "select all", 0));
        selectNonePushButton->setText(QApplication::translate("EntitySelectionDialog", "select none", 0));
    } // retranslateUi

};

namespace Ui {
    class EntitySelectionDialog: public Ui_EntitySelectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTITYSELECTIONDLG_H
