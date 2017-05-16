cmake_minimum_required(VERSION 3.0)
project(lab3)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)

find_package(MPI)
include_directories(${MPI_INCLUDE_PATH})

add_executable(lab3 ${SOURCE_FILES})
target_link_libraries(lab3 pthread ${MPI_LIBRARIES})

if(MPI_COMPILE_FLAGS)
    set_target_properties(lab3 PROPERTIES
            COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
    set_target_properties(lab3 PROPERTIES
            LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()
