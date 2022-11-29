add_library(execution_manager_lib execution_manager.cpp)

link_directories ("../command_lib/")
link_directories ("../command_executor_lib/")

target_compile_options(execution_manager_lib  PUBLIC
  -Wall -Wextra -pedantic -Werror
)