#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "Service.h"
#include <string>

class BaseHttpService 
{
public:
    BaseHttpService() {
        Init();
    }
    virtual void Request(QUrl url){};

private:
    void Init() {
        network_manager_ = new QNetworkAccessManager();
    }

protected:
  QNetworkAccessManager* network_manager_;
};