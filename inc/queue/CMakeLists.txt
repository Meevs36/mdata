# Author -- Meevs
# Creation Date -- Wed Dec  1 06:50:09 2021
# File Name -- CMakeLists.txt
# Notes -- 

if (${ENABLE_QUEUE})
	set (MDATA_HEADERS
		${MDATA_HEADERS} ${CMAKE_CURRENT_SOURCE_DIR}/queue.h
		PARENT_SCOPE
	)
endif ()
