cmake_minimum_required(VERSION 3.8)
project(Task1_GL20)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -lGLU)

set(SOURCE_FILES
        Sources/main.cpp
        Sources/stdafx.cpp
        Sources/stdafx.h
        Sources/targetver.h)

add_executable(Task1_GL20 ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
#find_package(GLM REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

target_link_libraries(Task1_GL20 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY})
