#include <cypan/service/baseHttpService.h>
#include <cypan/common/common_interface.h>
#include <functional>
#include <QObject>

namespace HTTP_SERVICE {
    enum HTTP_METHOD {
        GET,
        POST,
    };
}

class HttpService : public BaseHttpService {
    using Callback = std::function<void(QNetworkReply *reply)>;
public:
    HttpService() : BaseHttpService() {
    }
    virtual void Request(QUrl url, Callback callback, HTTP_SERVICE::HTTP_METHOD 
                        method =  HTTP_SERVICE::HTTP_METHOD::GET, std::shared_ptr<json> data = nullptr);
};