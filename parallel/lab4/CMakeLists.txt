cmake_minimum_required(VERSION 3.7)
project(lab4)

set(CMAKE_CXX_STANDARD 98)
set(SOURCE_FILES main.cpp)

find_package(MPI)
include_directories(${MPI_INCLUDE_PATH})

add_executable(lab4 ${SOURCE_FILES})
target_link_libraries(lab4 pthread ${MPI_LIBRARIES})

if(MPI_COMPILE_FLAGS)
    set_target_properties(lab4 PROPERTIES
            COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
    set_target_properties(lab4 PROPERTIES
            LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()
