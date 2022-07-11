add_library(ip_lib ip_lib.cpp)

target_compile_options(ip_lib PUBLIC
  -Wall -Wextra -pedantic -Werror
)