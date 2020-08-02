cmake_minimum_required(VERSION 3.10)

# Project name
project(Logger VERSION 1.0)

# Configure header
configure_file(include/Logger.h.in include/Logger.h)

# Add exectuable
add_executable(Logger src/Logger.cpp)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQRUIED True)
