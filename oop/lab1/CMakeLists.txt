cmake_minimum_required(VERSION 2.6)

project(tritset)

include_directories(.)
add_subdirectory(gtests)

set(SOURCE_TRITSET tritset.cpp)
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -O3 -Wall -std=c++11" )
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -Wall -std=c++11" )

add_library(tritset STATIC ${SOURCE_TRITSET})
