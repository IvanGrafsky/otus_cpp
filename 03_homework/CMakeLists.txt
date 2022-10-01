cmake_minimum_required(VERSION 3.10)

project(allocator_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(allocator_lib)
add_subdirectory(my_vector_lib)

add_executable(allocator_test allocator_test.cpp)

target_link_libraries(allocator_test PUBLIC
  allocator_lib
  my_vector_lib
)

target_include_directories(allocator_test PUBLIC
  "${PROJECT_SOURCE_DIR}/ip_lib"
)

target_compile_options(allocator_test PUBLIC
  -Wall -Wextra -pedantic -Werror
)