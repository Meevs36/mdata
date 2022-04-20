# Author -- Meevs
# Creation Date -- Sun Dec  5 01:33:14 2021
# File Name -- CMakeLists.txt
# Notes -- 

add_executable (mdataQueueTest
  EXCLUDE_FROM_ALL
  queueTestSuite.c
  queueTestSuiteFuncs.c
  ${CMAKE_SOURCE_DIR}/src/main/queue/queue.c
  )

target_include_directories (mdataQueueTest
  PRIVATE
  ${CMAKE_SOURCE_DIR}/inc/
  ${CMAKE_SOURCE_DIR}/inc/queue/
  )

target_link_libraries (mdataQueueTest
  check
  )

target_compile_options (mdataQueueTest
  PRIVATE
  -g
  )
