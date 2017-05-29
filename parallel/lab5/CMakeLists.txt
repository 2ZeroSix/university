cmake_minimum_required(VERSION 3.7)
project(lab5)

set(CMAKE_CXX_STANDARD 98)
#set(SOURCE_FILES without_balance.cpp)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -O3)
find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})


add_executable(with_balance with_balance.cpp)
target_link_libraries(with_balance pthread ${MPI_LIBRARIES})

if(MPI_COMPILE_FLAGS)
    set_target_properties(with_balance PROPERTIES
            COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
    set_target_properties(with_balance PROPERTIES
            LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()

add_executable(without_balance without_balance.cpp)
target_link_libraries(without_balance pthread ${MPI_LIBRARIES})

if(MPI_COMPILE_FLAGS)
    set_target_properties(without_balance PROPERTIES
            COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
    set_target_properties(without_balance PROPERTIES
            LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()
