cmake_minimum_required(VERSION 3.5.1)
project(clang-profiler)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(external)

#add_library(external
#    "external/cwalk/cwalk.c"
#    "external/xxHash/xxhash.c"
#    "external/enkiTS/TaskScheduler.cpp"
#    "external/llvm_demangle/lib/Demangle.cpp"
#    "external/llvm_demangle/lib/ItaniumDemangle.cpp"
#    "external/llvm_demangle/lib/MicrosoftDemangle.cpp"
#    "external/llvm_demangle/lib/MicrosoftDemangleNodes.cpp"
#    "external/simdjson/simdjson.cpp"
#    "external/sqlite3/sqlite3.c")
#target_include_directories(external PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set(SRC
    "src/Analysis.cpp"
    "external/events_parser/Colors.cpp"
    "src/main.cpp"
    "external/events_parser/Utils.cpp"
)
add_executable(${CMAKE_PROJECT_NAME} "${SRC}")
target_link_libraries(${CMAKE_PROJECT_NAME} events_parser)

find_package(Threads REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME} Threads::Threads)
