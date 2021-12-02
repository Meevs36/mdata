# Author -- Meevs
# Creation Date -- Thu Dec  2 02:16:29 2021
# File Name -- CMakeLists.txt
# Notes -- 

add_executable (mdataStackyTest
  stackyTestSuite.c
  ${CMAKE_SOURCE_DIR}/src/main/stacky/stacky.c
  )

target_include_directories (mdataStackyTest
  PRIVATE
  ${CMAKE_SOURCE_DIR}/inc/
  ${CMAKE_SOURCE_DIR}/inc/stacky/
  )

target_link_libraries (mdataStackyTest
  check
  )
