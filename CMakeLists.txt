cmake_minimum_required(VERSION 3.27)

project(zeromq)

set(CMAKE_C_COMPILER g++)
set(PROJECT_ROOT_DIR ${CMAKE_SOURCE_DIR})
set(CMAKE_MODULE_PATH ${PROJECT_ROOT_DIR}/cmake)

find_package(zmq REQUIRED)

add_subdirectory(${PROJECT_ROOT_DIR}/req_reply)
add_subdirectory(${PROJECT_ROOT_DIR}/pub_sub)
