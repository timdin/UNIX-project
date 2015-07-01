#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
class myDialog;
}

class myDialog : public QDialog
{
    Q_OBJECT

public:
    explicit myDialog(QWidget *parent = 0);
    QString getImageFilename();
    int getCurrItm();
    void setfilepath(QString p);
    ~myDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::myDialog *ui;
    QString filepath;
    int currItm;
};

#endif // MYDIALOG_H
