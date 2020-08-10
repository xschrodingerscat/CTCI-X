

project(lgs_structure)

cmake_minimum_required(VERSION 0.1)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
set(CMAKE_BUILD_TYPE "Debug")

add_definitions(-DCMAKE_BUILD)
add_definitions(-DUNICODE)
add_definitions(-D_UNICODE)
add_definitions(-D__STDC_FORMAT_MACROS)
add_definitions(-DNOMINMAX)
add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-D_WINSOCK_DEPRECATED_NO_WARNINGS)
add_definitions(-DNEED_BCOPY)

add_definitions(-DUNIT_TESTING)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pipe -Wall -Wextra -Werror -g")
#set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -Wpointer-arith -Wconditional-uninitialized -Wno-unused-parameter -Wno-deprecated-declarations")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pipe -Wall -Wextra -g")


set(PROJECT_APP lgx_structure)

set(APP_SOURCE
	lgs_structure.c
	../common/lgs_common.c
	../cutest/lgs_cutest.c
	lgs_list.c
	lgs_list_unittest.c
	lgs_vector.c
	lgs_vector_unittest.c
	lgs_hash.c
	lgs_hash_unittest.c
	lgs_string_builder.c
	lgs_string_builder_unittest.c
	lgs_queue.c
	lgs_queue_unittest.c
	lgs_stack.c
	lgs_stack_unittest.c
	lgs_graph.c
	lgs_graph_unittest.c
)

include_directories(
	.
	../
	../common
	../cutest
)

add_executable(${PROJECT_APP} ${APP_SOURCE})

if(WIN32)
	target_link_libraries(${PROJECT_APP} Ws2_32.lib)
else()
    target_link_libraries(${PROJECT_APP} pthread)
endif()





