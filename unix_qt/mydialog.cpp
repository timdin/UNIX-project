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

    QDir mDir = QDir::root();
    if ( !mDir.cd("C:\\qt_hw") ) {
        qWarning( "Cannot find the directory" );
        qDebug() << mDir.path() ;
    }

    ui->listWidget->addItems(mDir.entryList()) ;
    delete ui->listWidget->item(1);
    delete ui->listWidget->item(0);

}

myDialog::~myDialog()
{
    delete ui;
}

void myDialog::on_pushButton_clicked()
{
    QListWidgetItem *itm = ui->listWidget->currentItem();
    QString imgName = itm->text();
    QString filename = "C:/qt_hw/" + imgName;   //comic image path

    if(filename.isEmpty())
       QMessageBox::information(this,tr("hi"),tr("Please select an item"));
    else
    {
        qDebug() << filename;
        this->setImageFilename(filename);
    }
    this->close();
}

QString myDialog::getImageFilename()
{
    QString filename = ImageFilename;
    qDebug() << "filename: " + filename;
    return filename;
}

void myDialog::setImageFilename(QString name)
{
    this->ImageFilename = name;
    qDebug() << "name: " + name;
}
