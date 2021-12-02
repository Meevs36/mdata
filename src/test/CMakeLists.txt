# Author -- Meevs
# Creation Date -- Wed Dec  1 22:05:45 2021
# File Name -- CMakeLists.txt
# Notes -- 

add_executable (mdataLinkyTest
  linky/linkyTestSuite.c
  ${CMAKE_SOURCE_DIR}/src/main/linky/linky.c
  )

target_include_directories (mdataLinkyTest
  PRIVATE
  ${CMAKE_SOURCE_DIR}/inc/
  ${CMAKE_SOURCE_DIR}/inc/linky/
  )

target_link_libraries (mdataLinkyTest
  check
  )
