#include "baseHttpService.h"
#include <functional>
#include <QObject>

class HttpService : public BaseHttpService {
    using Callback = std::function<void(QNetworkReply *reply)>;
public:
    HttpService() : BaseHttpService() {
    }
    virtual void Request(QUrl url, Callback callback);
};