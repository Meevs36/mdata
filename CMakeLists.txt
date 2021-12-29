# Author -- Meevs
# Creation Date -- Wed Dec  1 05:51:34 2021
# File Name -- CMakeLists.txt
# Notes --
#     -- 2021-12-25 -- Version updates can now be tracked via the version.md file

cmake_minimum_required (VERSION 3.16)

project (mdata VERSION 0.2.4)

add_subdirectory (inc)
add_subdirectory (src)

add_custom_target (uninstall
  xargs rm < install_manifest.txt
  )
  

# Enable unit testing to confirm use cases
enable_testing ()
add_test (NAME linkyTest COMMAND src/test/linky/mdataLinkyTest) # Testing for the Linky module
add_test (NAME stackyTest COMMAND src/test/stacky/mdataStackyTest) # Testing for the Stacky module
add_test (NAME queueTest COMMAND src/test/queue/mdataQueueTest) # Testing for the Queue module
add_test (NAME binaryTreeTest COMMAND src/test/binaryTree/mdataBinaryTreeTest) # Testing for the Binary Tree module
add_test (NAME mdataLib COMMAND src/test/mdata/mdataTest) # Testing to ensure that the mdata library was successfully installed onto the system. This test will only succeed if the 'make install' command has been run with root permissions from the build directory after compilation
