cmake_minimum_required(VERSION 3.5.1)
project(lab5)

#set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 98)
#set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -O3)
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS} -O3)
find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})


add_executable(with_balance with_balance.c)
target_link_libraries(with_balance pthread m ${MPI_LIBRARIES})

if(MPI_COMPILE_FLAGS)
    set_target_properties(with_balance PROPERTIES
            COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
    set_target_properties(with_balance PROPERTIES
            LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()

add_executable(without_balance without_balance.cpp)
target_link_libraries(without_balance pthread m ${MPI_LIBRARIES})

if(MPI_COMPILE_FLAGS)
    set_target_properties(without_balance PROPERTIES
            COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
    set_target_properties(without_balance PROPERTIES
            LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()
