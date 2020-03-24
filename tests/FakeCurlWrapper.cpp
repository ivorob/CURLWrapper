#include "FakeCurlWrapper.h"

CURLWrapper::Response
Fake::CurlWrapper::sendPost(const std::string& url, const std::string& data)
{
    CURLWrapper::Response response(CURLE_OK, 200, "{\"response\":\"Success\"}");
    return response;
}
