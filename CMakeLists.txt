cmake_minimum_required(VERSION 3.10)

# Project name
project(Logger VERSION 1.0)

# Configure header
configure_file("${CMAKE_SOURCE_DIR}/inc/LoggerConfig.h.in"
               "${CMAKE_SOURCE_DIR}/inc/LoggerConfig.h")

# Add exectuable
add_executable(Logger src/Logger.cpp)

# Specify C++ standard
set(Logger CMAKE_CXX_STANDARD 17)
set(Logger CMAKE_CXX_STANDARD_REQRUIED True)

target_include_directories(Logger PUBLIC
                           "${CMAKE_SOURCE_DIR}/inc"
                           )


if (UNIX)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif (UNIX)
