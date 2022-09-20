#include "HttpService.h"

void HttpService::Request(QUrl url, Callback callback) {
    network_manager_->get(QNetworkRequest(url));
    QObject::connect(network_manager_, &QNetworkAccessManager::finished, [=](QNetworkReply *reply) {
        callback(reply);
    });
}