cmake_minimum_required(VERSION 2.6)

project(tritset_tests)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} .)
add_subdirectory(gtests)

set(SOURCE_EXE main_gtests.cpp trit_gtests.cpp tritset_gtests.cpp)
set(SOURCE_LIB tritset.cpp)

add_library(tritset STATIC ${SOURCE_LIB})

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -O3 -Wall -std=c++11" )
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -Wall -std=c++11" )

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests ${SOURCE_EXE})
target_link_libraries(runTests ${GTEST_LIBRARIES} tritset pthread)
