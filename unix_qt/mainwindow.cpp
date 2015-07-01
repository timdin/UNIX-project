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
    this->setStyleSheet("D:/Qt/5.4/UNIX-project/unix_qt/riven.jpg);");
    ui->scrollArea->setStyleSheet("background: transparent;");

    //layout///
    QVBoxLayout *layout_img = new QVBoxLayout;
    QHBoxLayout *layout_btn = new QHBoxLayout;
    this->centralWidget()->setLayout(layout_img);
    layout_img->addWidget(ui->label);
    layout_img->addWidget(ui->scrollArea);
    layout_btn->addWidget(ui->pushButton_previous);
    layout_btn->addWidget(ui->pushButton_select);
    layout_btn->addWidget(ui->pushButton_next);
    layout_img->addLayout(layout_btn);

    //button///
    QRect *rect = new QRect(0,0,100,100);
    QRegion* region = new QRegion(*rect,QRegion::Ellipse);
    ui->pushButton_next->setMask(*region);
    ui->pushButton_previous->setMask(*region);
    rect->setRect(20,20,20,20);
    region = new QRegion(*rect,QRegion::Rectangle);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_select_clicked()
{    
    mDialog.exec();
    if( ! mDialog.getImageFilename().isEmpty() )
    {
        this->currentImagePath = mDialog.getImageFilename();
        this->currItm = mDialog.getCurrItm();
        QImage image(currentImagePath);
        this->setImage(image);
    }
}

void MainWindow::on_pushButton_next_clicked()
{
    if(currItm > 100)
        QMessageBox::information(this,tr("Error"),tr("Please select an item!"));
    else
    {
        //get image path and modifiy
        this->refreshImage("next");
        QImage image(currentImagePath);
        if(image.load(currentImagePath))
        {
            this->setImage(image);
        }
        else
        {
            currentImagePath.remove(QString::number(currItm)+".jpg");
            currItm--;
            QMessageBox::information(this,tr("HI"),tr("This is the last page!"));
        }
    }
}

void MainWindow::on_pushButton_previous_clicked()
{
    if(currItm > 100)
        QMessageBox::information(this,tr("Error"),tr("Please select an item!"));
    else
    {
        //get image path and modifiy
        QImage image(currentImagePath);
        this->refreshImage("previous");
        if(image.load(currentImagePath) )
        {
            this->setImage(image);
        }
        else
        {
            currentImagePath.remove(QString::number(currItm)+".jpg");
            currItm++;
            QMessageBox::information(this,tr("HI"),tr("This is the first page!"));
        }
    }
}

void MainWindow::setImage(QImage image)
{
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->label->setScaledContents(true);
    ui->scrollArea->setWidget(ui->label);
}

void MainWindow::refreshImage(QString keywords)
{
    if(keywords == "next")
    {
        currentImagePath.remove(QString::number(currItm)+".jpg");
        currentImagePath = currentImagePath + QString::number((++currItm))+".jpg";
    }
    else if(keywords == "previous")
    {
        currentImagePath.remove(QString::number(currItm)+".jpg");
        currentImagePath = currentImagePath + QString::number((--currItm))+".jpg";
    }
    else
        qDebug() << "false keywords pass.";
}
