#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydialog.h"
#include <QUrl>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QDebug>
#include <QString>
#include <QImage>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     QVBoxLayout *layout = new QVBoxLayout;
    this->centralWidget()->setLayout(layout);
    layout->addWidget(ui->label);
    layout->addWidget(ui->scrollArea);
    layout->addWidget(ui->pushButton_select);
    layout->addWidget(ui->pushButton_next);
    layout->addWidget(ui->pushButton_previous);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_select_clicked()
{
    myDialog mDialog ;
    mDialog.setModal(false);
    mDialog.exec();
    if( currentImagePath.isEmpty() )
    {
        this->currentImagePath = mDialog.getImageFilename();
        this->currItm = mDialog.getCurrItm();
        QImage image(currentImagePath);
        ui->label->setPixmap(QPixmap::fromImage(image));
        ui->scrollArea->setBackgroundRole(QPalette::Dark);
        ui->scrollArea->setWidget(ui->label);
    }
}

void MainWindow::on_pushButton_next_clicked()
{
    if(currItm == 0) currItm++;
    //get image path and modifiy
    currentImagePath.remove(QString::number(currItm)+".jpg");
    currentImagePath = currentImagePath + QString::number((++currItm))+".jpg";

    QImage image(currentImagePath);
    if(image.load(currentImagePath))
    {
        ui->label->setPixmap(QPixmap::fromImage(image));
        ui->scrollArea->setWidget(ui->label);
    }
    else
    {
        currentImagePath.remove(QString::number(currItm)+".jpg");
        currItm--;
        QMessageBox::information(this,tr("HI"),tr("This is the last page!"));
    }
}

void MainWindow::on_pushButton_previous_clicked()
{
    //get image path and modifiy
    currentImagePath.remove(QString::number(currItm)+".jpg");
    currentImagePath = currentImagePath + QString::number((--currItm))+".jpg";
    QImage image(currentImagePath);
    if(image.load(currentImagePath) )
    {
        ui->label->setPixmap(QPixmap::fromImage(image));
        ui->scrollArea->setWidget(ui->label);
    }
    else
    {
        currentImagePath.remove(QString::number(currItm)+".jpg");
        currItm++;
        QMessageBox::information(this,tr("HI"),tr("This is the first page!"));
    }
}
