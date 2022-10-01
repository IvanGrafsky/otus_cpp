add_library(my_vector_lib my_vector.cpp)

target_compile_options(my_vector_lib PUBLIC
  -Wall -Wextra -pedantic -Werror
)