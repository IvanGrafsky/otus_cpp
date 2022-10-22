add_library(document_lib document.cpp)

target_compile_options(document_lib PUBLIC
  -Wall -Wextra -pedantic -Werror
)

link_directories ("../figure_lib/")

target_link_libraries(document_lib PUBLIC
  figure_lib
)