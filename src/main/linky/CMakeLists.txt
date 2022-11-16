# Author -- Meevs
# Creation Date -- Wed Dec  1 05:51:56 2021
# File Name -- CMakeLists.txt
# Notes -- 

add_library (linky
  OBJECT
  ${CMAKE_CURRENT_SOURCE_DIR}/linky.c
  )

target_include_directories (linky
  PRIVATE ${CMAKE_SOURCE_DIR}/inc/linky/
  )

