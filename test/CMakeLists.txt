cmake_minimum_required(VERSION 3.10)

# Project name
project(LoggerUnitTest VERSION 1.0)

# Configure header
configure_file("${CMAKE_SOURCE_DIR}/inc/LoggerConfig.h.in"
               "${CMAKE_SOURCE_DIR}/inc/LoggerConfig.h")

# Add exectuable
add_executable(LoggerUnitTest "${CMAKE_SOURCE_DIR}/test/LoggerUnitTest.cpp")

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

target_include_directories(LoggerUnitTest PUBLIC
                           "${CMAKE_SOURCE_DIR}/inc"
                           )

add_dependencies(LoggerUnitTest Logger)

target_link_libraries(LoggerUnitTest Logger)
