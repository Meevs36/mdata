# Author -- Meevs
# Creation Date -- Wed Dec  1 06:49:23 2021
# File Name -- CMakeLists.txt
# Notes --

add_subdirectory (linky)
add_subdirectory (stacky)
add_subdirectory (queue)
add_subdirectory (binaryTree)

set (CMAKE_INSTALL_INCLUDEDIR
	"include/mdata"
	PARENT_SCOPE
)

set_target_properties (mdata
	PROPERTIES
	PUBLIC_HEADER
	"${MDATA_HEADERS}"
)
