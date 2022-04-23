# Author -- Meevs
# Creation Date -- Wed Dec  1 05:50:41 2021
# File Name -- CMakeLists.txt
# Notes -- 


# Only enter sub-directory if the respective module is infact enabled
if (NOT (${LINKY_ENABLED} EQUAL -1))
  add_subdirectory (linky)
endif ()

if (NOT (${STACKY_ENABLED} EQUAL -1))
  add_subdirectory (stacky)
endif ()

if (NOT (${QUEUE_ENABLED} EQUAL -1))
  add_subdirectory (queue)
endif ()

if (NOT (${BT_ENABLED} EQUAL -1))
  add_subdirectory (binaryTree)
endif ()
