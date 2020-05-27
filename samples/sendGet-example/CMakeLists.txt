CMAKE_MINIMUM_REQUIRED (VERSION 3.10)
PROJECT (sendGet-example)

SET (SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
SET (SOURCES
        ${SRC_DIR}/main.cpp
    )

ADD_EXECUTABLE (sendGet-example ${SOURCES})
TARGET_LINK_LIBRARIES (sendGet-example curlcpp)
