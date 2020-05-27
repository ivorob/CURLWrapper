#include <gtest/gtest.h>
#include <curl/curl.h>

#include "FakeCurlWrapper.h"

TEST(CurlWrapper, responseTest)
{
    CURLWrapper::Response response;
    ASSERT_EQ(CURLE_FAILED_INIT, response.getStatus());
    ASSERT_EQ(-1, response.getCode());
    ASSERT_EQ("", response.getContent());

    CURLWrapper::Response response1(CURLE_OK, 200, "hello");
    ASSERT_EQ(CURLE_OK, response1.getStatus());
    ASSERT_EQ(200, response1.getCode());
    ASSERT_EQ("hello", response1.getContent());
}

TEST(CurlWrapper, postRequestTest)
{
    Fake::CurlWrapper wrapper;
    CURLWrapper::Response response = wrapper.sendPost("http://localhost/", "{}");
    ASSERT_EQ(CURLE_OK, response.getStatus());
    ASSERT_EQ(200, response.getCode());
    ASSERT_EQ("{\"response\":\"Success\"}", response.getContent());
}

TEST(CurlWrapper, postWithSpecificHeaders)
{
    Fake::CurlWrapper wrapper;
    wrapper.setHeaders({"Content-type: application/pdf"});
    CURLWrapper::Response response = wrapper.sendPost("http://localhost/", "{}");
    ASSERT_EQ(CURLE_OK, response.getStatus());
    ASSERT_EQ(200, response.getCode());
    ASSERT_EQ("{\"response\":\"Wrong content-type header\"}", response.getContent());
}

TEST(CurlWrapper, getRequestTest)
{
    Fake::CurlWrapper wrapper;
    CURLWrapper::Response response = wrapper.sendGet("http://localhost/");
    ASSERT_EQ(CURLE_OK, response.getStatus());
    ASSERT_EQ(200, response.getCode());
    ASSERT_EQ("<html><body>test</body></html>", response.getContent());
}
