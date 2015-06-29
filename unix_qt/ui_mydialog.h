/********************************************************************************
** Form generated from reading UI file 'mydialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myDialog
{
public:
    QListWidget *listWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_back;

    void setupUi(QDialog *myDialog)
    {
        if (myDialog->objectName().isEmpty())
            myDialog->setObjectName(QString::fromUtf8("myDialog"));
        myDialog->resize(387, 306);
        listWidget = new QListWidget(myDialog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(61, 21, 256, 192));
        widget = new QWidget(myDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 220, 251, 71));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_back = new QPushButton(widget);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));

        horizontalLayout->addWidget(pushButton_back);


        retranslateUi(myDialog);

        QMetaObject::connectSlotsByName(myDialog);
    } // setupUi

    void retranslateUi(QDialog *myDialog)
    {
        myDialog->setWindowTitle(QApplication::translate("myDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("myDialog", "OK", 0, QApplication::UnicodeUTF8));
        pushButton_back->setText(QApplication::translate("myDialog", "Back", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class myDialog: public Ui_myDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H
