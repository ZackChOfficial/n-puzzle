cmake_minimum_required(VERSION 3.16)

# uncomment this if you wand debug binary
SET( CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_STANDARD 14)

project(n-puzzle)

add_executable(${PROJECT_NAME}
    src/main.cpp src/Board.class.cpp src/A_Star.class.cpp src/parser.cpp src/utils.cpp src/heuristic_functions.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC include)
