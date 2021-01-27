project (n-puzzle)
cmake_minimum_required(VERSION 3.16)

add_definitions(-std=c++17 -O3)
include_directories(../../include)

set(SOURCES
        ../../src/wasm.cpp
        ../../src/Board.class.cpp
        ../../src/A_Star.class.cpp
        ../../src/parser.cpp
        ../../src/utils.cpp
        ../../src/heuristic_functions.cpp
        ../../src/Node.class.cpp
        ../../src/disjoint_pattern_database/DDB_3P.cpp
        ../../src/disjoint_pattern_database/DDB_555.cpp
        ../../src/disjoint_pattern_database/DDB_663.cpp
        ../../src/disjoint_pattern_database/Disjoint_database.cpp
        ../../src/Node.class.cpp
        ../../src/Ida_Star.class.cpp
        ../../src/n-puzzle.cpp
)



add_executable(n-puzzle ${SOURCES})


message(STATUS "Setting compilation target to WASM")
set_target_properties(n-puzzle PROPERTIES LINK_FLAGS "--bind -s MODULARIZE")
