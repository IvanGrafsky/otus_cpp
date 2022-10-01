add_library(allocator_lib
              logging_allocator.cpp
              my_allocator.cpp)

target_compile_options(allocator_lib PUBLIC
  -Wall -Wextra -pedantic -Werror
)