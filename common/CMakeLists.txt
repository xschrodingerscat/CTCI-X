

project(lgs_common)

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


set(PROJECT_APP lgx_common)

set(APP_SOURCE
	lgs_main.c
	../cutest/lgs_cutest.c
	../os/lgs_clock.c
	lgs_common.c
	lgs_common_unittest.c

)

include_directories(
	.
	../
	../cutest
	../os
)

add_executable(${PROJECT_APP} ${APP_SOURCE})

if(WIN32)
	target_link_libraries(${PROJECT_APP} Ws2_32.lib)
else()
    target_link_libraries(${PROJECT_APP} pthread)
endif()





