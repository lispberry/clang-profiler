cmake_minimum_required(VERSION 3.5.1)
project(header)

add_library(header INTERFACE)
target_include_directories(header INTERFACE .)
