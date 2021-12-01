# Author -- Meevs
# Creation Date -- Wed Dec  1 06:49:23 2021
# File Name -- CMakeLists.txt
# Notes --

add_subdirectory (linky)
add_subdirectory (stacky)
add_subdirectory (queue)

install (DIRECTORY DESTINATION /usr/include/mdata/)
