add_library(command_executor_lib command_executor.cpp)

link_directories ("../command_lib/")

target_compile_options(command_executor_lib PUBLIC
  -Wall -Wextra -pedantic -Werror
)