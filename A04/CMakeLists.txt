cmake_minimum_required(VERSION 3.5.0)
project(Adventure LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
    src/DiaryManager.cpp
    src/utils.cpp
)

set(HEADERS
    src/DiaryEntry.h
    src/DiaryManager.h
    src/utils.h
)

include_directories(src)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
add_executable(pdadd src/pdadd.cpp ${SOURCES} ${HEADERS})
add_executable(pdlist src/pdlist.cpp ${SOURCES} ${HEADERS})
add_executable(pdshow src/pdshow.cpp ${SOURCES} ${HEADERS})
add_executable(pdremove src/pdremove.cpp ${SOURCES} ${HEADERS})
