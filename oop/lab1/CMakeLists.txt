cmake_minimum_required(VERSION 2.6)

project(tritset)

include_directories(.)
add_subdirectory(gtests)

# set source files
set(SOURCE_TRITSET tritset.cpp trit.cpp)

# set required flags
set(TMP_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -std=c++11")
set(TMP_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -Wall -std=c++11")

# set platform -m32
set(CMAKE_CXX_FLAGS  "${TMP_CXX_FLAGS} -m32" )
set(CMAKE_EXE_LINKER_FLAGS  "${TMP_EXE_LINKER_FLAGS} -m32" )
add_library(tritset-m32 STATIC ${SOURCE_TRITSET})

# set platform -mx32
set(CMAKE_CXX_FLAGS  "${TMP_CXX_FLAGS} -mx32" )
set(CMAKE_EXE_LINKER_FLAGS  "${TMP_EXE_LINKER_FLAGS} -mx32" )
add_library(tritset-mx32 STATIC ${SOURCE_TRITSET})

# set platform -m64
set(CMAKE_CXX_FLAGS  "${TMP_CXX_FLAGS} -m64" )
set(CMAKE_EXE_LINKER_FLAGS  "${TMP_EXE_LINKER_FLAGS} -m64" )
add_library(tritset-m64 STATIC ${SOURCE_TRITSET})
