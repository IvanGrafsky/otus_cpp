cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "42" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION ${PATCH_VERSION})

project(helloworld VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(version.h.in version.h)

add_executable(helloworld helloworld.cpp)

add_executable(helloworld_test test.cpp)

target_include_directories(helloworld PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          )

enable_testing()
add_test(helloworld_test test)






