cmake_minimum_required(VERSION 3.0.0)
project(day7 VERSION 0.1.0)

INCLUDE_DIRECTORIES(
    c:/DEV/vcpkg/installed/x64-windows/include
)

LINK_DIRECTORIES(
    c:/DEV/vcpkg/installed/x64-windows/lib
)

add_library(graph-lib
    Graph.cpp
    Graph.hpp
)

add_library(my-helper-lib
    lib/StringHandler.cpp
    lib/StringHandler.hpp
    lib/SrcNodesLoader.hpp
    lib/SrcNodesLoader.cpp
)

add_executable(day7 main.cpp)

target_link_libraries(day7 PRIVATE graph-lib my-helper-lib)


#TARGET_LINK_LIBRARIES(day7
#   boost
#)
