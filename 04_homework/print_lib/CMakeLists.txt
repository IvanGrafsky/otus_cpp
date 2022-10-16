
add_library(print_lib print_lib.hpp)

set_target_properties(print_lib PROPERTIES LINKER_LANGUAGE CXX)

target_compile_options(print_lib PUBLIC
  -Wall -Wextra -pedantic -Werror
)