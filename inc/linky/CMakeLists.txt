# Author -- Meevs
# Creation Date -- Wed Dec  1 06:50:09 2021
# File Name -- CMakeLists.txt
# Notes -- 

if (${ENABLE_LINKY})
	set (MDATA_HEADERS 
		${MDATA_HEADERS} ${CMAKE_CURRENT_SOURCE_DIR}/linky.h
		PARENT_SCOPE
	)
endif ()
