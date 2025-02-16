cmake_minimum_required(VERSION 3.5.1)
project(ClangBuildAnalyzer)

include(GNUInstallDirs)

add_subdirectory(src/external/sqlite3)

set(SRC
# C sources
    "src/external/cwalk/cwalk.c"
    "src/external/inih/ini.c"
    "src/external/xxHash/xxhash.c"
# C++ sources
    "src/Analysis.cpp"
    "src/Arena.cpp"
    "src/BuildEvents.cpp"
    "src/Colors.cpp"
    "src/main.cpp"
    "src/Utils.cpp"
    "src/external/enkiTS/TaskScheduler.cpp"
    "src/external/inih/cpp/INIReader.cpp"
    "src/external/llvm-Demangle/lib/Demangle.cpp"
    "src/external/llvm-Demangle/lib/ItaniumDemangle.cpp"
    "src/external/llvm-Demangle/lib/MicrosoftDemangle.cpp"
    "src/external/llvm-Demangle/lib/MicrosoftDemangleNodes.cpp"
    "src/external/simdjson/simdjson.cpp"
)
add_executable(ClangBuildAnalyzer "${SRC}")
target_compile_features(ClangBuildAnalyzer PRIVATE cxx_std_17)

find_library(LIBRT rt)
if(LIBRT)
    target_link_libraries(ClangBuildAnalyzer ${LIBRT})
endif()

find_package(Threads REQUIRED)
target_link_libraries(ClangBuildAnalyzer Threads::Threads sqlite3)

install(TARGETS ClangBuildAnalyzer
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        )
