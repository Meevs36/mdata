# Author -- Meevs
# Creation Date -- Wed Dec 29 00:31:40 2021
# File Name -- CMakeLists.txt
# Notes --
#     -- 2021-12-28 -- This test is to ensure the functionality of the .so file. This will hopefully avoid mistakes in the future where I thought the Binary Tree module was working flawlessly (and it was) but it was actually missing from the .so

add_executable (mdataTest
  mdataTestSuite.c
  ${CMAKE_SOURCE_DIR}/src/test/linky/linkyTestSuiteFuncs.c
  ${CMAKE_SOURCE_DIR}/src/test/stacky/stackyTestSuiteFuncs.c
  ${CMAKE_SOURCE_DIR}/src/test/queue/queueTestSuiteFuncs.c
  ${CMAKE_SOURCE_DIR}/src/test/binaryTree/binaryTreeTestSuiteFuncs.c
  )

target_include_directories (mdataTest
  PRIVATE
  ${CMAKE_SOURCE_DIR}/inc/
  ${CMAKE_SOURCE_DIR}/inc/linky/
  ${CMAKE_SOURCE_DIR}/inc/stacky/
  ${CMAKE_SOURCE_DIR}/inc/queue/
  ${CMAKE_SOURCE_DIR}/inc/binaryTree/
  ${CMAKE_SOURCE_DIR}/src/test/linky/
  ${CMAKE_SOURCE_DIR}/src/test/stacky/
  ${CMAKE_SOURCE_DIR}/src/test/queue/
  ${CMAKE_SOURCE_DIR}/src/test/binaryTree/
  )

target_link_directories (mdataTest
  PRIVATE
  ${CMAKE_SOURCE_DIR}/src/main/
  )

target_link_libraries (mdataTest
  mdata
  check
  )
