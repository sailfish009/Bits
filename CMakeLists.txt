cmake_minimum_required(VERSION 3.6)
project(Bits)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_definitions(-D _HAS_CXX17=1)
add_definitions(-D _HAS_CXX20=1)
add_definitions(-D _WIN32_WINNT=0x0601)
# add_definitions(-D _MSC_VER=1920)
set(CMAKE_CONFIGURATION_TYPES "Debug" CACHE STRING "" FORCE)

include_directories(src)

set(SOURCE
    src/Bits.cpp)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
add_library(Bits SHARED ${SOURCE})
target_compile_features(Bits PRIVATE cxx_std_17)
target_compile_options(Bits PRIVATE /bigobj)
