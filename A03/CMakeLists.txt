cmake_minimum_required(VERSION 3.5.0)
project(Adventure LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SRC_FILES "src/*.cpp")
file(GLOB INC_FILES "src/*.h")

include_directories(src)

add_executable(Adventure main.cpp ${SRC_FILES} ${INC_FILES})

