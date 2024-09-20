cmake_minimum_required(VERSION 3.27)

project(zeromq)

set(CMAKE_C_COMPILER g++)
set(PROJECT_EXECUTABLE_NAME zeromq)
set(PROJECT_LIBRARY_NAME zeromq)
set(PROJECT_ROOT_DIR ${CMAKE_SOURCE_DIR})

set(CMAKE_MODULE_PATH ${PROJECT_ROOT_DIR}/cmake)

file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_EXECUTABLE_NAME} main.cpp ${SOURCES})

# add_library() goes here

# find_package() goes here

target_include_directories(${PROJECT_EXECUTABLE_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)
# target_include_directories() goes here
# target_link_libraries() goes here
