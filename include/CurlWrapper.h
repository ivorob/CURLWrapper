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
    const CURLcode status;
    const long code;
    const std::string content;
};

class Client {
public:
    using Headers = std::list<std::string>;
public:
    Client();
    virtual ~Client();

    virtual Response sendPost(const std::string& url, const std::string& data);
    virtual void setHeaders(const Headers& headers);
private:
    CURL *curl;
    struct curl_slist *headers;
};

}
