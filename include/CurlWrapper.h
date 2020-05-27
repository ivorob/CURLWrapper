#pragma once

#include <string>
#include <list>
#include <curl/curl.h>

namespace CURLWrapper {

class Response {
public:
    Response();
    Response(CURLcode status, long code, const std::string& content);

    CURLcode getStatus() const;
    long getCode() const;
    const std::string& getContent() const;
private:
    CURLcode status;
    long code;
    std::string content;
};

class Client {
public:
    using Headers = std::list<std::string>;
public:
    Client();
    virtual ~Client();

    virtual Response sendPost(const std::string& url, const std::string& data);
    virtual Response sendGet(const std::string& url);
    virtual void setHeaders(const Headers& headers);
private:
    CURL *curl;
    struct curl_slist *headers;
};

}
