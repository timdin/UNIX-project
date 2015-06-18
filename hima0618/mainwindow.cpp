#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QImage>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //getOpenFileName(this,dialogTitle,default path,limited fileType)
    QString filename=QFileDialog::getOpenFileName(
            this,
            tr("Give me the fucking file path"),
            "C:\\qt_hw", //default path when open dialog
            "Image File (*.jpg *.png *.jpeg)"
            );
    //filename = "http://img3.6comic.com:99/2/102/708/018_8kr.jpg";
    if(filename.isEmpty())
        ui->lab_filePath->setText("You didnt choose any file!");
    else
    {
        QImage image(filename);
        ui->lab_img->setPixmap(QPixmap::fromImage(image));
        ui->lab_filePath->setText(filename);
    }
}
