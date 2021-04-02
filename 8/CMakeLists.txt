cmake_minimum_required(VERSION 3.0.0)
project(day8 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

add_library(helper-lib
    helper/helper.hpp
    helper/helper.cpp
)

add_executable(day8 main.cpp)

target_link_libraries(day8 PRIVATE load-lib helper-lib)