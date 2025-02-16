cmake_minimum_required(VERSION 3.5.1)
project(cwalk)

add_library(cwalk
    cwalk.c
    cwalk.h)
target_include_directories(cwalk PUBLIC .)
