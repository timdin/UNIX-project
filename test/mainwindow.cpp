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
    ui->webView->page()->setForwardUnsupportedContent(true);
     connect(ui->webView->page(),SIGNAL(downloadRequested(QNetworkRequest)),this,SLOT(download(QNetworkRequest)));
     connect(ui->webView->page(),SIGNAL(unsupportedContent(QNetworkReply*)),this,SLOT(unsupportedContent(QNetworkReply*)));

    ui->webView->load(QUrl("http://img3.6comic.com:99/2/102/708/018_8kr.jpg"));

    ui->webView->adjustSize();
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
void MainWindow::download(const QNetworkRequest &request){
    qDebug()<<"Download Requested: "<<request.url();
}

void MainWindow::unsupportedContent(QNetworkReply * reply){

    qDebug()<<"Unsupported Content: "<<reply->url();

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
    if(! filename.isEmpty())
    {
        if(! ui->label->isVisible() )
        {
            ui->webView->setVisible(false);
            ui->label->setVisible(true);
        }
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

void MainWindow::on_pushButton_download_clicked()
{
    qDebug()<<"get";

}
