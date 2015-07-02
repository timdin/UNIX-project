#include "mydialog.h"
#include "ui_mydialog.h"
#include <QDir>
#include <QDebug>
#include <QtCore>
#include <QFileDialog>
#include <QMessageBox>
myDialog::myDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myDialog)
{
    ui->setupUi(this);
    filepath ="/home/comic";
    QDir mDir;
    if ( !mDir.cd(filepath) ) {
        qWarning( "Cannot find the directory" );
    }
    mDir.cd(filepath);
    mDir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    ui->listWidget->addItems(mDir.entryList()) ;

}

myDialog::~myDialog()
{
    delete ui;
}

void myDialog::on_pushButton_clicked()
{
    QListWidgetItem *itm = ui->listWidget->currentItem();
    qDebug() << "filepath before: " << filepath;
    filepath.remove("/" + QString::number(currItm) + ".jpg");
    currItm = itm->text().remove(".jpg").toInt(); //viewing image index numver
    qDebug() << "cur: " << currItm;
    filepath = filepath + "/" + itm->text();   //set the current selected item
    QDir mDir;
    mDir.setPath(filepath);

    QFileInfo temp(filepath);
    qDebug() << "filepath after: " << filepath;
    qDebug() << "is dir? " << temp.isDir();
    qDebug() << "is file? " << temp.isFile();
    if(filepath.isEmpty())
       QMessageBox::information(this,tr("hi"),tr("Please select an item"));
    else if(temp.isDir())
    {
       //"goto next directory "
       this->setfilepath(mDir.path());
       ui->listWidget->clear();
       mDir.cd(filepath);
       mDir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
       ui->listWidget->addItems(mDir.entryList()) ;
    }
    else
    {
        // open image
        this->setfilepath(filepath);
        this->close();
    }

}

QString myDialog::getImageFilename()
{
    return filepath;
}

int myDialog::getCurrItm()
{
    return currItm;
}

void myDialog::setfilepath(QString p)
{
    this->filepath = p;
}

void myDialog::on_pushButton_back_clicked()
{
    if(filepath.compare("/home/comic", "/home/comic") <= 0 )
    {
        QDir mDir;
        mDir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
        mDir.setPath(filepath);
        mDir.cdUp();
        filepath = mDir.path();
        ui->listWidget->clear();
        ui->listWidget->addItems(mDir.entryList()) ;
    }
    else
        this->close();
}
