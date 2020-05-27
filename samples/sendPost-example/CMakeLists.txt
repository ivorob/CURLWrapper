CMAKE_MINIMUM_REQUIRED (VERSION 3.10)
PROJECT (sendPost-example)

SET (SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
SET (SOURCES
        ${SRC_DIR}/main.cpp
    )

ADD_EXECUTABLE (sendPost-example ${SOURCES})
TARGET_LINK_LIBRARIES (sendPost-example curlcpp)
