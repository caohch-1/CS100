CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(HELLO)
AUX_SOURCE_DIRECTORY(. SRC_LIST)
ADD_EXECUTABLE(hello ${SRC_LIST})