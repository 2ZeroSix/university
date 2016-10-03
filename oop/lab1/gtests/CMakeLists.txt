cmake_minimum_required(VERSION 2.6)

project(tritset_tests)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# set source files
set(SOURCE_GTESTS main_gtests.cpp trit_gtests.cpp tritset_gtests.cpp)

# set required flags
set(TMP_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -std=c++11")
set(TMP_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -Wall -std=c++11")

# set platform -m32
set(CMAKE_CXX_FLAGS  "${TMP_CXX_FLAGS} -m32" )
set(CMAKE_EXE_LINKER_FLAGS  "${TMP_EXE_LINKER_FLAGS} -m32" )
add_executable(runTests-m32 ${SOURCE_GTESTS})
target_link_libraries(runTests-m32 ${GTEST_LIBRARIES} tritset-m32 pthread)
add_custom_command( TARGET runTests-m32 
                    POST_BUILD
                    COMMAND runTests-m32) #> /dev/null && echo "[PASSED] m32" || (echo "[FAIL] m32" && false))

# set platform -mx32
set(CMAKE_CXX_FLAGS  "${TMP_CXX_FLAGS} -mx32" )
set(CMAKE_EXE_LINKER_FLAGS  "${TMP_EXE_LINKER_FLAGS} -mx32" )
add_executable(runTests-mx32 ${SOURCE_GTESTS})
target_link_libraries(runTests-mx32 ${GTEST_LIBRARIES} tritset-mx32 pthread)
add_custom_command( TARGET runTests-mx32
                    POST_BUILD
                    COMMAND runTests-mx32)# > /dev/null && echo "[PASSED] mx32" || (echo "[FAIL] mx32" && false))

# set platform -m64
set(CMAKE_CXX_FLAGS  "${TMP_CXX_FLAGS} -m64" )
set(CMAKE_EXE_LINKER_FLAGS  "${TMP_EXE_LINKER_FLAGS} -m64" )
add_executable(runTests-m64 ${SOURCE_GTESTS})
target_link_libraries(runTests-m64 ${GTEST_LIBRARIES} tritset-m64 pthread)
add_custom_command( TARGET runTests-m64
                    POST_BUILD
                    COMMAND runTests-m64)# > /dev/null && echo "[PASSED] m64" || (echo "[FAIL] m64" && false))
