add_library(execution_manager_lib execution_manager.cpp)

link_directories ("../command_lib/")
link_directories ("../command_executor_lib/")

target_link_libraries(execution_manager_lib PUBLIC
  command_executor_lib
  command_lib
)

target_compile_options(execution_manager_lib  PUBLIC
  -Wall -Wextra -pedantic -Werror
)