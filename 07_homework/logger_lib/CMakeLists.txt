add_library(logger_lib logger.cpp)

target_compile_options(logger_lib PUBLIC
  -Wall -Wextra -pedantic -Werror
)