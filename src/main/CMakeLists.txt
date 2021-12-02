# Author -- Meevs
# Creation Date -- Wed Dec  1 05:50:41 2021
# File Name -- CMakeLists.txt
# Notes -- 

# Each subdirectory will populate the SOURCES variable with all respective files
# These will be combined here into the 'libmdata.so' shared object
add_subdirectory (linky)
add_subdirectory (stacky)
add_subdirectory (queue)

add_library (mdata SHARED ${SOURCES})
target_include_directories (mdata
  PRIVATE
  ${CMAKE_SOURCE_DIR}/inc/
  ${CMAKE_SOURCE_DIR}/inc/linky/
  ${CMAKE_SOURCE_DIR}/inc/stacky/
  ${CMAKE_SOURCE_DIR}/inc/queue
  )
target_link_directories (mdata
  PRIVATE
  ${CMAKE_SOURCE_DIR}/lib/
  )

install (TARGETS mdata DESTINATION /usr/lib/)
