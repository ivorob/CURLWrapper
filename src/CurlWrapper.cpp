#include "CurlWrapper.h"

namespace {

size_t
writeToString(void *data, size_t size, size_t count, void *stream)
{
    reinterpret_cast<std::string *>(stream)->append(reinterpret_cast<char *>(data), size * count);
    return size * count;
}

}

CURLWrapper::Client::Client()
    : curl(),
      headers()
{
    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
}

CURLWrapper::Client::~Client()
{
    if (curl != nullptr) {
        curl_easy_cleanup(curl);

        if (this->headers != nullptr) {
            curl_slist_free_all(this->headers);
        }
    }

    curl_global_cleanup();
}

CURLWrapper::Response
CURLWrapper::Client::sendPost(const std::string& url, const std::string& data)
{
    if (this->curl != nullptr) {
        curl_easy_setopt(this->curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(this->curl, CURLOPT_POSTFIELDS, data.c_str());

        std::string content;
        curl_easy_setopt(this->curl, CURLOPT_WRITEFUNCTION, writeToString);
        curl_easy_setopt(this->curl, CURLOPT_WRITEDATA, &content);
        curl_easy_setopt(this->curl, CURLOPT_POST, true);

        CURLcode result = curl_easy_perform(this->curl);
        long responseCode = -1;
        if (result == CURLE_OK) {
            curl_easy_getinfo(this->curl, CURLINFO_RESPONSE_CODE, &responseCode);
        }

        Response response(result, responseCode, content);
        return response;
    }

    return {};
}

void
CURLWrapper::Client::setHeaders(const Headers& headers)
{
    if (this->curl != nullptr) {
        if (this->headers != nullptr) {
            curl_slist_free_all(this->headers);
            this->headers = nullptr;
        }

        for (const auto& header : headers) {
            this->headers = curl_slist_append(this->headers, header.c_str());
        }

        curl_easy_setopt(this->curl, CURLOPT_HTTPHEADER, this->headers);
    }
}

CURLWrapper::Response::Response()
    : status(CURLE_FAILED_INIT),
      code(-1)
{
}

CURLWrapper::Response::Response(CURLcode status, long code, const std::string& content)
    : status(status),
      code(code),
      content(content)
{
}

CURLcode
CURLWrapper::Response::getStatus() const
{
    return this->status;
}

long
CURLWrapper::Response::getCode() const
{
    return this->code;
}

const std::string&
CURLWrapper::Response::getContent() const
{
    return this->content;
}
