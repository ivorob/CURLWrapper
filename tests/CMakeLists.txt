CMAKE_MINIMUM_REQUIRED (VERSION 3.10)
PROJECT (curlwrapper-tests)

SET (SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
SET (MAIN_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../src)
SET (MAIN_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../include)
SET (SOURCES
        ${SRC_DIR}/tests.cpp
        ${SRC_DIR}/CurlWrapperTest.cpp
        ${SRC_DIR}/FakeCurlWrapper.cpp
        ${MAIN_SRC_DIR}/CurlWrapper.cpp
    )

SET (HEADERS
        ${SRC_DIR}/FakeCurlWrapper.h
        ${MAIN_INCLUDE_DIR}/CurlWrapper.h
    )

INCLUDE (GoogleTest)
ADD_EXECUTABLE (curlwrapper-tests ${SOURCES} ${HEADERS})
TARGET_INCLUDE_DIRECTORIES (curlwrapper-tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
TARGET_INCLUDE_DIRECTORIES (curlwrapper-tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
TARGET_LINK_LIBRARIES (curlwrapper-tests gtest libcurl)

GTEST_ADD_TESTS (TARGET curlwrapper-tests TEST_PREFIX old:)
GTEST_DISCOVER_TESTS (curlwrapper-tests TEST_PREFIX new:)
