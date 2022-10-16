
cmake_minimum_required(VERSION 3.10)

set(BUILD_VERSION "44" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION ${BUILD_VERSION})

project(template_test VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(print_lib)

add_executable(template_test template_test.cpp)

target_link_libraries(template_test PUBLIC
  print_lib
)

target_include_directories(template_test PUBLIC
  "${PROJECT_SOURCE_DIR}/print_lib"
)

target_compile_options(template_test PUBLIC
  -Wall -Wextra -pedantic -Werror
)

install(TARGETS template_test
  RUNTIME DESTINATION bin
)

set(CPACK_GENERATOR DEB)
set(CPACK_DEBIAN_PACKAGE_MAINTAINER IG)
set(CPACK_PACKAGE_VERSION_MAJOR 0)
set(CPACK_PACKAGE_VERSION_MINOR 0)
set(CPACK_PACKAGE_VERSION_PATCH ${BUILD_VERSION})
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)