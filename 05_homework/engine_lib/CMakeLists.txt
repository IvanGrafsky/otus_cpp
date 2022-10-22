add_library(engine_lib engine.cpp)

target_compile_options(engine_lib PUBLIC
  -Wall -Wextra -pedantic -Werror
)