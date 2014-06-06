cmake_minimum_required(VERSION 2.8)

project(project_euler CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
add_definitions(-g -std=gnu++11 -fsigned-char -Wall -W -Wshadow -Wpointer-arith -Wcast-qual -Winline)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
add_definitions("-DHAS_BOOST")

include_directories(lib)
#add_subdirectory(lib)
add_subdirectory(src)
#add_subdirectory(test)

