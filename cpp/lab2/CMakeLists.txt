cmake_minimum_required(VERSION 2.8)

project(Searcher)

include_directories(include)
include_directories(AnyOption)
# add_subdirectory(gtests)

# set required flags
set(CMAKE_CXX_FLAGS             "${CMAKE_CXX_FLAGS} -O3 -Wall -std=c++14")
set(CMAKE_EXE_LINKER_FLAGS      "${CMAKE_EXE_LINKER_FLAGS} -Wall -std=c++14")
set(CMAKE_SHARED_LINKER_FLAGS   "${CMAKE_SHARED_LINKER_FLAGS} -Wall -std=c++14")
add_subdirectory(Surfaces)
add_subdirectory(AnyOption)

add_executable(Searcher base/main.cpp base/MainRoutines.cpp)
target_link_libraries(Searcher anyoption TwoDimSurface Plane Cylinder Torus WordSurface)