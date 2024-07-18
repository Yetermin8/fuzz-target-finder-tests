#include <iostream>
#include <vector>
#include <algorithm>
#include <curl/curl.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>
#include <curlpp/Easy.hpp>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <cpprest/http_client.h>
#include <azure/core/http/http.hpp>

namespace myNamespace {
    class MyClass {
    public:
        void myMethod() {
            std::cout << "MyClass::myMethod()" << std::endl;
            std::vector<int> vec = {1, 2, 3, 4, 5};
            std::sort(vec.begin(), vec.end());
            externalFunction();
            curlExample();
            pocoExample();
            curlppExample();
            qtExample();
            cpprestsdkExample();
            azureExample();
            envExample();
            sysExample();
        }

        static void staticMethod() {
            std::cout << "MyClass::staticMethod()" << std::endl;
        }

    private:
        int myData;

        void curlExample() {
            CURL* curl;
            CURLcode res;
            curl = curl_easy_init();
            if(curl) {
                curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                std::string user_input;
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &user_input);
                res = curl_easy_perform(curl);
                curl_easy_cleanup(curl);
                std::cout << "cURL example executed: " << user_input << std::endl;
            }
        }

        void pocoExample() {
            Poco::Net::HTTPClientSession session("example.com");
            Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, "/");
            Poco::Net::HTTPResponse response;
            session.sendRequest(request);
            std::istream &rs = session.receiveResponse(response);
            std::string user_input;
            Poco::StreamCopier::copyStream(rs, std::cout);
            std::cout << "Poco example executed: " << user_input << std::endl;
        }

        void curlppExample() {
            curlpp::Easy myRequest;
            myRequest.setOpt(curlpp::options::Url("http://example.com"));
            std::cout << "cURLpp example executed" << std::endl;
        }

        void qtExample() {
            QNetworkAccessManager manager;
            QNetworkRequest request(QUrl("http://example.com"));
            QNetworkReply *reply = manager.get(request);
            std::cout << "Qt example executed" << std::endl;
        }

        void cpprestsdkExample() {
            web::http::client::http_client client(U("http://www.bing.com/"));
            web::http::uri_builder builder(U("/search"));
            builder.append_query(U("q"), U("cpprestsdk"));
            client.request(web::http::methods::GET, builder.to_string());
            std::cout << "C++ REST SDK example executed" << std::endl;
        }

        void azureExample() {
            azure::core::http::Request request(azure::core::http::HttpMethod::Get, azure::core::http::Url("https://example.com"));
            azure::core::http::HttpPipeline pipeline;
            azure::core::http::Response response = pipeline.Send(request, azure::core::Context());
            std::cout << "Azure SDK for C++ example executed" << std::endl;
        }

        void envExample() {
            const char* env_var = std::getenv("USER_INPUT");
            if (env_var) {
                std::string user_input(env_var);
                std::cout << "Environment variable USER_INPUT: " << user_input << std::endl;
            }
        }

        void sysExample() {
            std::system("ls");
            long page_size = sysconf(_SC_PAGESIZE);
            std::cout << "Page size: " << page_size << std::endl;
        }

        static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
            ((std::string*)userp)->append((char*)contents, size * nmemb);
            return size * nmemb;
        }
    };

    template <typename T>
    class MyTemplateClass {
    public:
        T myTemplateMethod(T value) {
            std::cout << "MyTemplateClass::myTemplateMethod()" << std::endl;
            return value;
        }
    };
}

void globalFunction() {
    std::cout << "globalFunction()" << std::endl;
    myNamespace::MyClass obj;
    obj.myMethod();
    myNamespace::MyTemplateClass<int> templObj;
    templObj.myTemplateMethod(42);
}

int main() {
    globalFunction();
    myNamespace::MyClass::staticMethod();
    return 0;
}
