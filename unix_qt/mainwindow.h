#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mydialog.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setImage(QImage image);
    void refreshImage(QString keyword);
    ~MainWindow();

private slots:

    void on_pushButton_select_clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_previous_clicked();

private:
    Ui::MainWindow *ui;
    QString currentImagePath;
    myDialog mDialog;
    int currItm;
};

#endif // MAINWINDOW_H
