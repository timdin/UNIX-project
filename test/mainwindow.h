#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_localImage_clicked();

    void on_pushButton_ImageView_clicked();

    void on_pushButton_webView_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
