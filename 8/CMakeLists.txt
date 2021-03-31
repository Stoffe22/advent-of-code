cmake_minimum_required(VERSION 3.0.0)
project(day8 VERSION 0.1.0)

include_directories(
    c:/DEV/vcpkg/installed/x64-windows/include
)

link_directories(
    c:/DEV/vcpkg/installed/x64-windows/lib
)

add_library(load-lib
    loader/LoadInstructions.cpp
    loader/LoadInstructions.hpp
)

add_executable(day8 main.cpp)

target_link_libraries(day8 PRIVATE load-lib)