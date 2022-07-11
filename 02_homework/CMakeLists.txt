cmake_minimum_required(VERSION 3.10)

project(ip_filter)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(ip_lib)

add_executable(ip_filter ip_filter.cpp)
add_executable(ip_filter_test test.cpp)

target_link_libraries(ip_filter PUBLIC
  ip_lib
)

target_link_libraries(ip_filter_test PUBLIC
  ip_lib
  gtest
  gtest_main
  pthread
)

target_include_directories(ip_filter_test PUBLIC
  "${PROJECT_SOURCE_DIR}/ip_lib"
)

