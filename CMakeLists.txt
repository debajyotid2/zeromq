cmake_minimum_required(VERSION 3.27)

project(zeromq)

set(CMAKE_C_COMPILER g++)
set(PROJECT_ROOT_DIR ${CMAKE_SOURCE_DIR})
set(CMAKE_MODULE_PATH ${PROJECT_ROOT_DIR}/cmake)
set(REQ_REPLY_ROOT ${PROJECT_ROOT_DIR}/req_reply)

find_package(zmq REQUIRED)

foreach(exe server client)
    add_executable(${exe} ${REQ_REPLY_ROOT}/${exe}.cpp)
    target_include_directories(${exe} PRIVATE ${ZMQ_INCLUDE_DIRS})
    target_link_libraries(${exe} PRIVATE ${ZMQ_LIBRARIES})
endforeach()
