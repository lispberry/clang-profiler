cmake_minimum_required(VERSION 3.5.1)
project(llvm_demangle)

add_library(llvm_demangle
    lib/Demangle.cpp
    lib/ItaniumDemangle.cpp
    lib/MicrosoftDemangle.cpp
    lib/MicrosoftDemangleNodes.cpp)
target_include_directories(llvm_demangle PUBLIC include)
