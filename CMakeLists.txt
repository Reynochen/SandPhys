cmake_minimum_required(VERSION 3.22.2)

project(SandPhys)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 20)
add_definitions(-O3)

set(MAIN "main.cpp")
file(GLOB
    SRC "src/*.cpp")

include_directories("${PROJECT_SOURCE_DIR}/Include")

add_executable(${PROJECT_NAME} ${MAIN} ${SRC})