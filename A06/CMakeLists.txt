cmake_minimum_required(VERSION 3.5.0)
project(Adventure LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)

find_package(GTest REQUIRED)
enable_testing()
add_executable(example src/example.cpp src/Vector.tpp)
add_executable(tests test/tests.cpp src/Vector.tpp)
target_link_libraries(tests GTest::GTest GTest::Main)
add_test(NAME tests COMMAND tests)