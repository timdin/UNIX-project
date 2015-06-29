/********************************************************************************
** Form generated from reading UI file 'mydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *myDialog)
    {
        if (myDialog->objectName().isEmpty())
            myDialog->setObjectName(QStringLiteral("myDialog"));
        myDialog->resize(400, 300);
        layoutWidget = new QWidget(myDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 20, 281, 241));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(myDialog);

        QMetaObject::connectSlotsByName(myDialog);
    } // setupUi

    void retranslateUi(QDialog *myDialog)
    {
        myDialog->setWindowTitle(QApplication::translate("myDialog", "Dialog", 0));
        pushButton->setText(QApplication::translate("myDialog", "Open file", 0));
    } // retranslateUi

};

namespace Ui {
    class myDialog: public Ui_myDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H
