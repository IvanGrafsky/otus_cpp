cmake_minimum_required(3.10)

project(ip_filter)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(ip_filter ip_filter.cpp)

add_executable(ip_filter_test test.cpp)