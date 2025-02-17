cmake_minimum_required(VERSION 3.13)

project(tree-sitter
        VERSION "0.25.1"
        DESCRIPTION "An incremental parsing system for programming tools"
        HOMEPAGE_URL "https://tree-sitter.github.io/tree-sitter/"
        LANGUAGES C)

add_library(tree-sitter "${PROJECT_SOURCE_DIR}/src/lib.c")
target_include_directories(tree-sitter PUBLIC src include)

if(MSVC)
  target_compile_options(tree-sitter PRIVATE
                         /wd4018 # disable 'signed/unsigned mismatch'
                         /wd4232 # disable 'nonstandard extension used'
                         /wd4244 # disable 'possible loss of data'
                         /wd4267 # disable 'possible loss of data (size_t)'
                         /wd4701 # disable 'potentially uninitialized local variable'
                         /we4022 # treat 'incompatible types' as an error
                         /W4)
else()
  target_compile_options(tree-sitter PRIVATE
                         -Wall -Wextra -Wshadow -Wpedantic
                         -Werror=incompatible-pointer-types)
endif()

target_compile_definitions(tree-sitter PRIVATE _POSIX_C_SOURCE=200112L _DEFAULT_SOURCE)
