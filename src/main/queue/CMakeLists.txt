# Author -- Meevs
# Creation Date -- Wed Dec  1 05:51:56 2021
# File Name -- CMakeLists.txt
# Notes -- 

add_library (queue
  OBJECT
  ${CMAKE_CURRENT_SOURCE_DIR}/queue.c
  )

target_include_directories (queue
  PRIVATE ${CMAKE_SOURCE_DIR}/inc/queue/
  )
