cmake_minimum_required(VERSION 3.5.1)
project(events_parser)

add_library(events_parser
        Utils.cpp
        Utils.h
        Colors.cpp
        Colors.h
        Arena.cpp
        Arena.h
        BuildEvents.cpp
        BuildEvents.h)
target_link_libraries(events_parser
        flat_hash_map
        header
        cwalk
        xxHash
        llvm_demangle
        simdjson
        enkiTS
)
target_include_directories(events_parser PUBLIC .)
