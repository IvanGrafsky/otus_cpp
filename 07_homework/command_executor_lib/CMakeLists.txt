add_library(command_executor_lib command_executor.cpp)

link_directories ("../command_lib/")
link_directories ("../logger_lib/")

target_link_libraries(command_executor_lib PUBLIC
  command_lib
  logger_lib
)

target_compile_options(command_executor_lib PUBLIC
  -Wall -Wextra -pedantic -Werror
)