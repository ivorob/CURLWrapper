#pragma once

#include "CurlWrapper.h"

namespace Fake {

class CurlWrapper : public CURLWrapper::Client {
public:
    CURLWrapper::Response sendPost(const std::string& url, const std::string& data) override;
    CURLWrapper::Response sendGet(const std::string& url) override;

    void setHeaders(const CURLWrapper::Client::Headers& headers) override;
private:
    CURLWrapper::Client::Headers headers;
};

}
