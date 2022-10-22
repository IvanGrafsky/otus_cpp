add_library(figure_lib figure.cpp)

target_compile_options(figure_lib PUBLIC
  -Wall -Wextra -pedantic -Werror
)