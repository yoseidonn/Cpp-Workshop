# CMake minimum version
cmake_minimum_required(VERSION 3.10)

# Project name
project(MyProject)

# Set C++ standard (optional, but recommended)
set(CMAKE_CXX_STANDARD 17)

# Add the main executable and source file
add_executable(RunThis main.cpp)

# Add include directories for header files
target_include_directories(RunThis PRIVATE 
    ${CMAKE_SOURCE_DIR}/data_structures
    ${CMAKE_SOURCE_DIR}/sorting
    ${CMAKE_SOURCE_DIR}/searching
    ${CMAKE_SOURCE_DIR}/custom_lib
)

