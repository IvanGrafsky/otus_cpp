add_library(execution_manager_lib execution_manager.cpp)

target_compile_options(execution_manager_lib  PUBLIC
  -Wall -Wextra -pedantic -Werror
)