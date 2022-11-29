add_library(command_lib command.cpp)

target_compile_options(command_lib PUBLIC
  -Wall -Wextra -pedantic -Werror
)