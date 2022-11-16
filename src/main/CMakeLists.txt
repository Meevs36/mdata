# Author -- Meevs
# Creation Date -- Wed Dec  1 05:50:41 2021
# File Name -- CMakeLists.txt
# Notes -- 


# Only enter sub-directory if the respective module is infact enabled
if (${ENABLE_LINKY})
  add_subdirectory (linky)
endif ()

if (${ENABLE_STACKY})
  add_subdirectory (stacky)
endif ()

if (${ENABLE_QUEUE})
  add_subdirectory (queue)
endif ()

if (${ENABLE_BT})
  add_subdirectory (binaryTree)
endif ()
