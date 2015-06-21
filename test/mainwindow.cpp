#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    ui->webView->load(QUrl("http://img3.6comic.com:99/2/102/708/018_8kr.jpg"));
     QVBoxLayout *layout = new QVBoxLayout;
    this->centralWidget()->setLayout(layout);
    layout->addWidget(ui->webView);
    layout->addWidget(ui->label);
    layout->addWidget(ui->pushButton_localImage,0, Qt::AlignRight);
    layout->addWidget(ui->pushButton_webView,0, Qt::AlignRight);
    layout->addWidget(ui->pushButton_ImageView,0,Qt::AlignRight);
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
    //filename = "http://img3.6comic.com:99/2/102/708/018_8kr.jpg";
    if(! ui->label->isVisible() )
    {
        ui->webView->setVisible(false);
        ui->label->setVisible(true);
    }
    if(filename.isEmpty())
         ui->label->setText("You didnt choose any file!");
    else
    {
        if( ui->webView->isVisible() )
            ui->webView->setVisible(false);
        QImage image(filename);
        ui->label->setPixmap(QPixmap::fromImage(image));
        //ui->lab_filePath->setText(filename);
    }
}

void MainWindow::on_pushButton_ImageView_clicked()
{
    if(! ui->label->isVisible() )
    {
        ui->webView->setVisible(false);
        ui->label->setVisible(true);
    }
}

void MainWindow::on_pushButton_webView_clicked()
{
    if(! ui->webView->isVisible() )
    {
        ui->webView->setVisible(true);
        ui->label->setVisible(false);
    }
}
