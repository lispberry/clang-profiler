cmake_minimum_required(VERSION 3.5.1)
project(xxHash)

add_library(xxHash
    xxhash.c
    xxhash.h)
target_include_directories(xxHash PUBLIC .)
