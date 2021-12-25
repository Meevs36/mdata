# Author -- Meevs
# Creation Date -- Fri Dec 24 09:49:02 2021
# File Name -- CMakeLists.txt
# Notes -- 

add_executable (mdataBinaryTreeTest
  binaryTreeTestSuite.c
  ${CMAKE_SOURCE_DIR}/src/main/binaryTree/binaryTree.c
  )

target_include_directories (mdataBinaryTreeTest
  PRIVATE
  ${CMAKE_SOURCE_DIR}/inc/
  ${CMAKE_SOURCE_DIR}/inc/binaryTree/
  )

target_link_libraries (mdataBinaryTreeTest
  check
  )

target_compile_options (mdataBinaryTreeTest
  PRIVATE
  -g
  )
