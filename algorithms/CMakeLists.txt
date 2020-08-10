

project(lgs_algorithms)

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


set(PROJECT_APP lgx_algorithms)

set(APP_SOURCE
	lgs_algorithms.c
	../common/lgs_common.c
	../cutest/lgs_cutest.c
	../structure/lgs_graph.c
	../structure/lgs_list.c
	../structure/lgs_queue.c
	lgs_bfs.c
	lgs_bfs_unittest.c
	lgs_dfs.c
	lgs_dfs_unittest.c
)

include_directories(
	.
	../
	../cutest
	../structure
)

add_executable(${PROJECT_APP} ${APP_SOURCE})

if(WIN32)
	target_link_libraries(${PROJECT_APP} Ws2_32.lib)
else()
    target_link_libraries(${PROJECT_APP} pthread)
endif()





