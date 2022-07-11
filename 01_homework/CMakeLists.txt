cmake_minimum_required(VERSION 3.10)

set(BUILD_VERSION "42" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION ${BUILD_VERSION})

project(helloworld VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(version.h.in version.h)

add_executable(helloworld_cli helloworld.cpp)
add_library(version_lib lib.cpp)
add_executable(helloworld_test test.cpp)

target_include_directories(version_lib PUBLIC
  "${PROJECT_BINARY_DIR}"
)

target_link_libraries(helloworld_cli PUBLIC
  version_lib
)

target_link_libraries(helloworld_test PUBLIC
  version_lib
  gtest
  gtest_main
  pthread
)

target_compile_options(helloworld_cli PUBLIC
  -Wall -Wextra -pedantic -Werror
)

target_compile_options(helloworld_test PUBLIC
  -Wall -Wextra -pedantic -Werror
)

enable_testing()
add_test(helloworld_test test)

install(TARGETS helloworld_cli
  RUNTIME DESTINATION bin
)

set(CPACK_GENERATOR DEB)
set(CPACK_DEBIAN_PACKAGE_MAINTAINER IG)
set(CPACK_PACKAGE_VERSION_MAJOR 0)
set(CPACK_PACKAGE_VERSION_MINOR 0)
set(CPACK_PACKAGE_VERSION_PATCH ${BUILD_VERSION})
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)