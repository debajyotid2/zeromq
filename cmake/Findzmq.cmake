find_path(ZMQ_INCLUDE_DIR NAMES zmq.hpp PATHS /usr/include/ /usr/local/include/)

find_library(ZMQ_LIBRARY NAMES zmq PATHS /usr/lib64/)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(zmq DEFAULT_MSG ZMQ_LIBRARY ZMQ_INCLUDE_DIR)

if(ZMQ_FOUND)
    message(STATUS "Found zmq.")
    set(ZMQ_INCLUDE_DIRS ${ZMQ_INCLUDE_DIR})
    set(ZMQ_LIBRARIES ${ZMQ_LIBRARY})
else()
    message(FATAL_ERROR "Could not find zmq.")
endif()
