#include <cypan/view/mainwindow.h>
#include <cypan/common/common_interface.h>
#include "ui_mainwindow.h"
#include <QDebug>

// 找不到 Ui::MainWindow
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitView();
    InitData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitView() 
{
    login_btn_ = ui->login_btn;
}

void MainWindow::InitData() 
{
    service_ = new HttpService();
    // 成员函数作为callback需要使用bind
    std::function<void(QNetworkReply *reply)> callback = std::bind(
        &MainWindow::HandleResponse, this, std::placeholders::_1
    );
    // get 
    // service_->Request(QUrl("http://127.0.0.1/getALLFILES?userId=1234"), callback);
    // post
    std::shared_ptr<json> data = std::make_shared<json>();
    (*data)["user"] = 1234;
    service_->Request(QUrl("https://3caf737d-8319-4db3-9d24-7f1e8f1326ad.mock.pstmn.io"), callback, HTTP_SERVICE::POST, data);
    connect(login_btn_, &QPushButton::clicked, [=](bool checked){
        qDebug() << "clicked";
    });
}

void MainWindow::HandleResponse(QNetworkReply* reply)
{
    qDebug() << "response";
    QUrl url = reply->url();
    if (reply->error()) 
	{
		qDebug() << "go to " << url.toEncoded().constData() << " failed: " << reply->errorString();
	} else {
       qDebug() << reply->readAll();
    }
}