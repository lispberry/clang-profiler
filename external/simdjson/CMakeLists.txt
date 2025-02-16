cmake_minimum_required(VERSION 3.5.1)
project(simdjson)

add_library(simdjson simdjson.cpp)
target_include_directories(simdjson PUBLIC .)
