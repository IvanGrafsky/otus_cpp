cmake_minimum_required(VERSION 3.10)

set(BUILD_VERSION "44" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION ${BUILD_VERSION})

project(ip_filter VERSION ${PROJECT_VERSION})

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

target_include_directories(ip_filter PUBLIC
  "${PROJECT_SOURCE_DIR}/ip_lib"
)

target_include_directories(ip_filter_test PUBLIC
  "${PROJECT_SOURCE_DIR}/ip_lib"
)

target_compile_options(ip_filter PUBLIC
  -Wall -Wextra -pedantic -Werror
)

target_compile_options(ip_filter_test PUBLIC
  -Wall -Wextra -pedantic -Werror
)

enable_testing()
add_test(ip_filter_test test)

install(TARGETS ip_filter
  RUNTIME DESTINATION bin
)

set(CPACK_GENERATOR DEB)
set(CPACK_DEBIAN_PACKAGE_MAINTAINER IG)
set(CPACK_PACKAGE_VERSION_MAJOR 0)
set(CPACK_PACKAGE_VERSION_MINOR 0)
set(CPACK_PACKAGE_VERSION_PATCH ${BUILD_VERSION})
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
