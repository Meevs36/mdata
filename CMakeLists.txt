# Author -- Meevs
# Creation Date -- Wed Dec  1 05:51:34 2021
# File Name -- CMakeLists.txt
# Notes --
#     -- 2021-12-25 -- Version updates can now be tracked via the version.md file

cmake_minimum_required (VERSION 3.16)

project (mdata VERSION 0.2.6.1)

if (NOT (DEFINED MDATA_MODULES))
  list (APPEND MDATA_MODULES "LINKY" "STACKY" "QUEUE" "BT")
endif ()

# Determine which modules will be included in the build
set (${MDATA_SOURCES} "")
list (FIND MDATA_MODULES "LINKY" LINKY_ENABLED)
list (FIND MDATA_MODULES "STACKY" STACKY_ENABLED)
list (FIND MDATA_MODULES "QUEUE" QUEUE_ENABLED)
list (FIND MDATA_MODULES "BT" BT_ENABLED)

# Include Linky module if enabled
if (NOT (${LINKY_ENABLED} EQUAL -1))
  message (STATUS "[MDATA] -- Enabled Linky module")
  list (APPEND MDATA_SOURCES $<TARGET_OBJECTS:linky>)
  list (APPEND MDATA_TESTS "make mdataLinkyTest\;")
else ()
  message (STATUS "[MDATA] -- Linky module not enabled")
endif ()

# Include Stacky module if enabled
if (NOT (${STACKY_ENABLED} EQUAL -1))
  message (STATUS "[MDATA] -- Enabled Stacky module")
  list (APPEND MDATA_SOURCES $<TARGET_OBJECTS:stacky>)
  #list (APPEND MDATA_TESTS "'make mdataStackyTest'\;")
else ()
  message (STATUS "[MDATA] -- Stacky module not enabled")
endif ()

# Include Queue module if enabled
if (NOT (${QUEUE_ENABLED} EQUAL -1))
  message (STATUS "[MDATA] -- Enabled Queue module")
  list (APPEND MDATA_SOURCES $<TARGET_OBJECTS:queue>)
  #list (APPEND MDATA_TESTS "'make mdataQueueTest'\;")
else ()
  message (STATUS "[MDATA] -- Queue module not enabled")
endif ()

# Include Binary Tree module if enabled
if (NOT (${BT_ENABLED} EQUAL -1))
  message (STATUS "[MDATA] -- Enabled Binary Tree module")
  list (APPEND MDATA_SOURCES $<TARGET_OBJECTS:binaryTree>)
  #list (APPEND MDATA_TESTS "'make mdataBinaryTreeTest'\;")
else ()
  message (STATUS "[MDATA] -- Binary Tree module not enabled")
endif ()


add_subdirectory (inc)
add_subdirectory (src)


add_library (mdata
  SHARED
  ${MDATA_SOURCES}
  )
  #${SOURCES})
target_include_directories (mdata
  PRIVATE
  ${CMAKE_SOURCE_DIR}/inc/
  ${CMAKE_SOURCE_DIR}/inc/linky/
  ${CMAKE_SOURCE_DIR}/inc/stacky/
  ${CMAKE_SOURCE_DIR}/inc/queue/
  ${CMAKE_SOURCE_DIR}/inc/binaryTree/
  )
target_link_directories (mdata
  PRIVATE
  ${CMAKE_SOURCE_DIR}/lib/
  )

install (TARGETS mdata DESTINATION /usr/lib/)

# Uninstall target for easy removal from host system
add_custom_target (uninstall
  COMMAND xargs rm < install_manifest.txt 
  COMMAND rmdir /usr/include/mdata/
  )

# Added custom target to allow for easy, seperate compilation of all unit tests
add_custom_target (mtests
  COMMENT Compiling test suites
  )

# Enable unit testing to confirm use cases
enable_testing ()
set (VALGRIND_ARGS --leak-check=full --error-exitcode=1 --exit-on-first-error=no)
if (NOT (${LINKY_ENABLED} EQUAL -1))
  add_dependencies (mtests mdataLinkyTest)
  add_test (NAME linkyTest COMMAND ${CMAKE_BINARY_DIR}/src/test/linky/mdataLinkyTest) # Testing for the Linky module
  add_test (NAME linkyValgrindTest COMMAND valgrind ${VALGRIND_ARGS} ${CMAKE_BINARY_DIR}/src/test/linky/mdataLinkyTest)
endif ()
if (NOT (${STACKY_ENABLED} EQUAL -1))
  add_dependencies (mtests mdataStackyTest)
  add_test (NAME stackyTest COMMAND src/test/stacky/mdataStackyTest) # Testing for the Stacky module
  add_test (NAME stackyValgrindTest COMMAND valgrind ${VALGRIND_ARGS} ${CMAKE_BINARY_DIR}/src/test/stacky/mdataStackyTest)
endif ()
if (NOT (${QUEUE_ENABLED} EQUAL -1))
  add_dependencies (mtests mdataQueueTest)
  add_test (NAME queueTest COMMAND src/test/queue/mdataQueueTest) # Testing for the Queue module
  add_test (NAME queueValgrindTest COMMAND valgrind ${VALGRIND_ARGS} ${CMAKE_BINARY_DIR}/src/test/queue/mdataQueueTest)
endif ()
if (NOT (${BT_ENABLED} EQUAL -1))
  add_dependencies (mtests mdataBinaryTreeTest)
  add_test (NAME binaryTreeTest COMMAND src/test/binaryTree/mdataBinaryTreeTest) # Testing for the Binary Tree module
  add_test (NAME binaryTreeValgrindTest COMMAND valgrind ${VALGRIND_ARGS} ${CMAKE_BINARY_DIR}/src/test/binaryTree/mdataBinaryTreeTest)
endif ()
