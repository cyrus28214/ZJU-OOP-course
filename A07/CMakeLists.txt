cmake_minimum_required(VERSION 3.5.0)
project(Adventure LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)

# find_package(GTest REQUIRED)
enable_testing()
add_executable(tests test/tests.cpp src/MemoryPoolAllocator.tpp)
# target_link_libraries(tests GTest::GTest GTest::Main)
add_test(NAME tests COMMAND tests)