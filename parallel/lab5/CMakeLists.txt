cmake_minimum_required(VERSION 3.7)
project(lab5)

set(CMAKE_CXX_STANDARD 98)
set(SOURCE_FILES without_balance.cpp)

find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})

add_executable(lab5 ${SOURCE_FILES})
target_link_libraries(lab5 pthread ${MPI_LIBRARIES})

if(MPI_COMPILE_FLAGS)
    set_target_properties(lab5 PROPERTIES
            COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
    set_target_properties(lab5 PROPERTIES
            LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()
