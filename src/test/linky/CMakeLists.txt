# Author -- Meevs
# Creation Date -- Thu Dec  2 01:57:14 2021
# File Name -- CMakeLists.txt
# Notes -- 

add_executable (mdataLinkyTest
  linkyTestSuite.c
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
