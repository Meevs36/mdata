# Author -- Meevs
# Creation Date -- Wed Dec  1 05:51:56 2021
# File Name -- CMakeLists.txt
# Notes -- 

add_library (stacky
  OBJECT
  ${CMAKE_CURRENT_SOURCE_DIR}/stacky.c
  )

target_include_directories (stacky
  PRIVATE ${CMAKE_SOURCE_DIR}/inc/stacky/
  )
