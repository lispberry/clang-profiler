cmake_minimum_required(VERSION 3.5.1)
project(sqlite3)

add_library(sqlite3 STATIC
        sqlite3.c
)

target_include_directories(sqlite3 PUBLIC
        .
)
