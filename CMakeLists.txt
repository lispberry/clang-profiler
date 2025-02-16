cmake_minimum_required(VERSION 3.5.1)
project(clang-profiler)

set(CMAKE_CXX_STANDARD 20)

add_library(external
    "external/cwalk/cwalk.c"
    "external/inih/ini.c"
    "external/xxHash/xxhash.c"
    "external/enkiTS/TaskScheduler.cpp"
    "external/inih/cpp/INIReader.cpp"
    "external/llvm-Demangle/lib/Demangle.cpp"
    "external/llvm-Demangle/lib/ItaniumDemangle.cpp"
    "external/llvm-Demangle/lib/MicrosoftDemangle.cpp"
    "external/llvm-Demangle/lib/MicrosoftDemangleNodes.cpp"
    "external/simdjson/simdjson.cpp"
    "external/sqlite3/sqlite3.c")
target_include_directories(external PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set(SRC
    "src/Analysis.cpp"
    "src/Arena.cpp"
    "src/BuildEvents.cpp"
    "src/Colors.cpp"
    "src/main.cpp"
    "src/Utils.cpp"
)
add_executable(${CMAKE_PROJECT_NAME} "${SRC}")
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17)

find_library(LIBRT rt)
if(LIBRT)
    target_link_libraries(${CMAKE_PROJECT_NAME} ${LIBRT})
endif()

find_package(Threads REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME} Threads::Threads external)
