cmake_minimum_required(VERSION 3.27)

project(zeromq)

set(CMAKE_C_COMPILER g++)
set(SERVER_EXECUTABLE_NAME server)
set(CLIENT_EXECUTABLE_NAME client)
set(PROJECT_ROOT_DIR ${CMAKE_SOURCE_DIR})

set(CMAKE_MODULE_PATH ${PROJECT_ROOT_DIR}/cmake)

file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(${SERVER_EXECUTABLE_NAME} server.cpp ${SOURCES})
add_executable(${CLIENT_EXECUTABLE_NAME} client.cpp ${SOURCES})

find_package(zmq REQUIRED)

target_include_directories(${SERVER_EXECUTABLE_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_include_directories(${SERVER_EXECUTABLE_NAME} PRIVATE ${ZMQ_INCLUDE_DIRS})
target_link_libraries(${SERVER_EXECUTABLE_NAME} PRIVATE zmq)

target_include_directories(${CLIENT_EXECUTABLE_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_include_directories(${CLIENT_EXECUTABLE_NAME} PRIVATE ${ZMQ_INCLUDE_DIRS})
target_link_libraries(${CLIENT_EXECUTABLE_NAME} PRIVATE zmq)
