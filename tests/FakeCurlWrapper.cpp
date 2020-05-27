#include "FakeCurlWrapper.h"

CURLWrapper::Response
Fake::CurlWrapper::sendPost(const std::string& url, const std::string& data)
{
    for (const auto& header : this->headers) {
        if (header.find("Content-type") != std::string::npos) {
            return CURLWrapper::Response(CURLE_OK, 200, "{\"response\":\"Wrong content-type header\"}");
        }
    }

    return CURLWrapper::Response(CURLE_OK, 200, "{\"response\":\"Success\"}");
}

CURLWrapper::Response
Fake::CurlWrapper::sendGet(const std::string& url)
{
    return CURLWrapper::Response(CURLE_OK, 200, "<html><body>test</body></html>");
}

void
Fake::CurlWrapper::setHeaders(const CURLWrapper::Client::Headers& headers)
{
    this->headers = headers;
}
