#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydialog.h"
#include <QtWebKitWidgets/QWebView>
#include <QUrl>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QDebug>
#include <QString>
#include <QImage>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     QVBoxLayout *layout = new QVBoxLayout;
    this->centralWidget()->setLayout(layout);
    layout->addWidget(ui->label);
    layout->addWidget(ui->scrollArea);
    layout->addWidget(ui->pushButton_localImage,0, Qt::AlignRight);
    layout->addWidget(ui->pushButton_select,0,Qt::AlignRight);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_localImage_clicked()
{

    //getOpenFileName(this,dialogTitle,default path,limited fileType)
    QString filename=QFileDialog::getOpenFileName(
            this,
            tr("Give me the fucking file path"),
            "C:\\qt_hw", //default path when open dialog
            "Image File (*.jpg *.png *.jpeg)"
            );
    if(! filename.isEmpty())
    {
        QImage image(filename);
        ui->label->setPixmap(QPixmap::fromImage(image));

        ui->scrollArea->setBackgroundRole(QPalette::Dark);
        ui->scrollArea->setWidget(ui->label);
    }
}


void MainWindow::on_pushButton_select_clicked()
{
    myDialog mDialog ;
    mDialog.setModal(false);
    mDialog.exec();
    QString img = mDialog.getImageFilename();
    QImage image(img);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->scrollArea->setBackgroundRole(QPalette::Dark);
    ui->scrollArea->setWidget(ui->label);


}
