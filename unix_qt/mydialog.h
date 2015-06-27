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
    void setImageFilename(QString name);
    ~myDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::myDialog *ui;
    QString ImageFilename;
};

#endif // MYDIALOG_H
