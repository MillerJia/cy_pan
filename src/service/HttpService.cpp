#include "HttpService.h"

void HttpService::Request(QUrl url, Callback callback, HTTP_SERVICE::HTTP_METHOD method, std::shared_ptr<json> data)
{
    QNetworkRequest request;
    switch (method)
    {
    case HTTP_SERVICE::GET:
        request.setUrl(url);       
        network_manager_->get(request);
        break;
    case HTTP_SERVICE::POST:
        request.setUrl(url);
        if (data) {
            QString postData = QString::fromStdString(std::move(data->dump()));
            network_manager_->post(request, postData.toUtf8());
        }
        break;
    default:
        qDebug() << "unknown http method";
        return;
        break;
    }
    QObject::connect(network_manager_, &QNetworkAccessManager::finished, [=](QNetworkReply *reply)
                     { callback(reply); });
}