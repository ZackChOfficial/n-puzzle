cmake_minimum_required(VERSION 3.16)

SET( CMAKE_BUILD_TYPE Release)
set (CMAKE_CXX_STANDARD 17)
add_compile_options(-Werror)

project(n-puzzle)

set(SRCS
        src/main.cpp
        src/Board.class.cpp
        src/A_Star.class.cpp
        src/parser.cpp
        src/utils.cpp
        src/heuristic_functions.cpp
        src/Node.class.cpp
        src/disjoint_pattern_database/DDB_3P.cpp
        src/disjoint_pattern_database/DDB_555.cpp
        src/disjoint_pattern_database/DDB_663.cpp
        src/disjoint_pattern_database/Disjoint_database.cpp
        src/Node.class.cpp
        src/Ida_Star.class.cpp
        src/n-puzzle.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC include)
