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
    filepath ="D:/Qt/5.4/test";
    QDir mDir = QDir::root();
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
    currItm = itm->text().toInt();
    filepath = filepath + "/" + itm->text();   //comic image path
    QDir mDir = QDir::root();
    mDir.setPath(filepath);

    QFileInfo temp(filepath);

    if(filepath.isEmpty())
       QMessageBox::information(this,tr("hi"),tr("Please select an item"));
    else if(temp.isDir())
    {
       //"goto next directory "
       this->setImageFilename(filepath);
       ui->listWidget->clear();
       mDir.cd(filepath);
       mDir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
       ui->listWidget->addItems(mDir.entryList()) ;
    }
    else
    {        
        // open image
        this->setImageFilename(filepath);
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

void myDialog::setImageFilename(QString tmp)
{
    this->filepath = tmp;
}
