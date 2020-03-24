CMAKE_MINIMUM_REQUIRED (VERSION 3.0)
PROJECT (tests)

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

ADD_EXECUTABLE (tests ${SOURCES} ${HEADERS})
TARGET_INCLUDE_DIRECTORIES (tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
TARGET_INCLUDE_DIRECTORIES (tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
TARGET_LINK_LIBRARIES (tests gtest libcurl)
