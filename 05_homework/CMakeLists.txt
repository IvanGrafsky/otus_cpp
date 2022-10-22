cmake_minimum_required(VERSION 3.10)

set(BUILD_VERSION "44" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION ${BUILD_VERSION})

project(graph_engine VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(figure_lib)
add_subdirectory(engine_lib)
add_subdirectory(document_lib)

add_executable(graph_engine main.cpp)

target_link_libraries(graph_engine PUBLIC
  figure_lib
  engine_lib
  document_lib
)

target_compile_options(graph_engine PUBLIC
  -Wall -Wextra -pedantic -Werror
)