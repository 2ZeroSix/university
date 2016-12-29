cmake_minimum_required(VERSION 2.8)

project(SurfacesLibs)
include_directories(../include)

set( MAJOR_VERSION 1.0.0 )
set( MINOR_VERSION 1.0 )
set( LIB_INSTALL_PATH ~/Projects/lib )
set( HEADERS_INSTALL_PATH /usr/local/include/my_lib )
link_directories( "${LIB_INSTALL_PATH}" )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -std=c++14")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -Wall -std=c++14")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wall -std=c++14")

add_library(TwoDimSurface SHARED TwoDimSurface.cpp)
add_library(Plane SHARED Plane.cpp)
add_library(Cylinder SHARED Cylinder.cpp)
add_library(Torus SHARED Torus.cpp)
add_library(WordSurface SHARED WordSurface.cpp)
