cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "42" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION ${PATCH_VERSION})

project(helloworld VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(version.h.in version.h)

add_executable(helloworld helloworld.cpp)
add_library(version_lib lib.cpp)
add_executable(helloworld_test test.cpp)

target_include_directories(version_lib PUBLIC
  "${PROJECT_BINARY_DIR}"
)

target_link_libraries(helloworld PUBLIC
  version_lib
)

target_link_libraries(helloworld_test PUBLIC
  version_lib
  gtest
  gtest_main
  pthread
)

target_compile_options(helloworld PUBLIC
  -Wall -Wextra -pedantic -Werror
)

target_compile_options(helloworld_test PUBLIC
  -Wall -Wextra -pedantic -Werror
)

enable_testing()
add_test(helloworld_test test)