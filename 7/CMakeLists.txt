cmake_minimum_required(VERSION 3.19.0)
project(AOC-day7 VERSION 1.0)

add_executable(day7-program main.cpp)
add_library(graph-lib graph.cpp)
target_link_libraries(day7-program graph-lib)