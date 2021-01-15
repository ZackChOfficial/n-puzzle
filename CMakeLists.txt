cmake_minimum_required(VERSION 3.16)

SET( CMAKE_BUILD_TYPE Release)
set (CMAKE_CXX_STANDARD 17)

project(n-puzzle)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Board.class.cpp
    src/A_Star.class.cpp
    src/parser.cpp
    src/utils.cpp
    src/heuristic_functions.cpp
    src/Node.class.cpp

  
    src/Node.class.cpp
    src/Ida_Star.class.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC include)
