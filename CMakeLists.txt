cmake_minimum_required(VERSION 3.5.1)
project(clang-profiler)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(external)

set(SRC
    "src/Sql.cpp"
    "src/Sql.h"
    "src/Analysis.cpp"
    "src/main.cpp"
)
add_executable(${CMAKE_PROJECT_NAME} "${SRC}")
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC src)
target_link_libraries(${CMAKE_PROJECT_NAME} events_parser sqlite3 tree-sitter tree-sitter-cpp)

find_package(Threads REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME} Threads::Threads)
