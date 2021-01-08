cmake_minimum_required(VERSION 3.16)

SET( CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_STANDARD 17)

project(n-puzzle)

add_executable(${PROJECT_NAME}
    src/main.cpp src/Board.class.cpp src/A_Star.class.cpp src/parser.cpp src/utils.cpp src/heuristic_functions.cpp
    src/disjoint_pattern_database/DDB_555.cpp
    src/disjoint_pattern_database/Disjoint_database.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC include)
