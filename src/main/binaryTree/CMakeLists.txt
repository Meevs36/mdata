# Author -- Meevs
# Creation Date -- Wed Dec 29 00:26:12 2021
# File Name -- CMakeLists.txt
# Notes -- 

add_library (binaryTree
  OBJECT
  ${CMAKE_CURRENT_SOURCE_DIR}/binaryTree.c
  )

target_include_directories (binaryTree
  PRIVATE ${CMAKE_SOURCE_DIR}/inc/binaryTree/
  )
