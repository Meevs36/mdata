# Author -- Meevs
# Creation Date -- Wed Dec  1 05:51:34 2021
# File Name -- CMakeLists.txt
# Notes -- 

cmake_minimum_required (VERSION 3.16)

project (mdata VERSION 0.1.0)

add_subdirectory (inc)
add_subdirectory (src)

enable_testing ()
add_test (NAME linkyTest COMMAND src/test/linky/mdataLinkyTest)
add_test (NAME stackyTest COMMAND src/test/stacky/mdataStackyTest)
