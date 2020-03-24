#pragma once

#include "CurlWrapper.h"

namespace Fake {

class CurlWrapper : public CURLWrapper::Client {
public:
    CURLWrapper::Response sendPost(const std::string& url, const std::string& data) override;
};

}
