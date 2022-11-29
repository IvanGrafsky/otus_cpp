cmake_minimum_required(VERSION 3.10)

set(BUILD_VERSION "44" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION ${BUILD_VERSION})

project(bulk VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(command_lib)
add_subdirectory(command_executor_lib)
add_subdirectory(execution_manager_lib)

add_executable(bulk bulk.cpp)

target_link_libraries(bulk PUBLIC
  command_lib
  command_executor_lib
  execution_manager_lib
)

target_include_directories(bulk PUBLIC
 "${PROJECT_SOURCE_DIR}/command_lib"
 "${PROJECT_SOURCE_DIR}/command_executor_lib"
 "${PROJECT_SOURCE_DIR}/execution_manager_lib"
)

target_compile_options(bulk PUBLIC
  -Wall -Wextra -pedantic -Werror
)

install(TARGETS bulk
  RUNTIME DESTINATION bin
)

set(CPACK_GENERATOR DEB)
set(CPACK_DEBIAN_PACKAGE_MAINTAINER IG)
set(CPACK_PACKAGE_VERSION_MAJOR 0)
set(CPACK_PACKAGE_VERSION_MINOR 0)
set(CPACK_PACKAGE_VERSION_PATCH ${BUILD_VERSION})
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)