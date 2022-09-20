#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QNetworkAccessManager>
#include "HttpService.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void InitView();
    void InitData();
    void HandleResponse(QNetworkReply* reply);

private:
    Ui::MainWindow *ui;
    QPushButton* login_btn_;

    HttpService* service_;
};
#endif // MAINWINDOW_H
