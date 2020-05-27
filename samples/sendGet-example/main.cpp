#include <iostream>
#include "CurlWrapper.h"

int
main(int argc, char *argv[])
{
    CURLWrapper::Client client;
    std::string url = "http://httpbin.org/get";
    std::cout << "Send request to " << url << std::endl;

    CURLWrapper::Response response = client.sendGet(url);
    if (response.getStatus() == CURLE_OK && response.getCode() == 200) {
        std::cout << "Response: " << std::endl;
        std::cout << response.getContent() << std::endl;
    } else {
        std::cerr << "CURL status: " << response.getStatus() << std::endl;
        std::cerr << "CURL response code: " << response.getCode() << std::endl;
        std::cerr << "Response content: " << response.getContent() << std::endl;
    }

    return EXIT_SUCCESS;
}
