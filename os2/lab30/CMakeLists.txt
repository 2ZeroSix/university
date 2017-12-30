cmake_minimum_required(VERSION 3.9)
project(lab30)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab30
        second_proxy.c)
target_link_libraries(lab30 pthread)
