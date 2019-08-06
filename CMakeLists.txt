
cmake_minimum_required(VERSION 3.5)
project(FallingBalls)

set(CMAKE_CXX_STANDARD 11)
include_directories(./include)
# Define the source files and dependencies for the executable
set(SOURCE_FILES
        src/pawn.cpp
        src/main.cpp
        src/filewriting.cpp
        src/action.cpp
        )
add_executable(FBalls ${SOURCE_FILES})