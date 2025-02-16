cmake_minimum_required(VERSION 3.5.1)
project(enkiTS)

add_library(enkiTS
    TaskScheduler.cpp
    TaskScheduler.h
    LockLessMultiReadPipe.h)
target_include_directories(enkiTS PUBLIC .)
