project (n-puzzle)
cmake_minimum_required(VERSION 3.16)

SET( CMAKE_BUILD_TYPE Release)
set (CMAKE_CXX_STANDARD 17)
include_directories(../../../include)
add_compile_options(-Werror)


set(SOURCES
        ../../../src/wasm.cpp
        ../../../src/Board.class.cpp
        ../../../src/A_Star.class.cpp
        ../../../src/parser.cpp
        ../../../src/utils.cpp
        ../../../src/heuristic_functions.cpp
        ../../../src/Node.class.cpp
        ../../../src/disjoint_pattern_database/DDB_3P.cpp
        ../../../src/disjoint_pattern_database/DDB_555.cpp
        ../../../src/disjoint_pattern_database/DDB_663.cpp
        ../../../src/disjoint_pattern_database/Disjoint_database.cpp
        ../../../src/Node.class.cpp
        ../../../src/Ida_Star.class.cpp
        ../../../src/n-puzzle.cpp
)



add_executable(n-puzzle ${SOURCES})


message(STATUS "Setting compilation target to WASM")
set_target_properties(n-puzzle PROPERTIES LINK_FLAGS "--bind -s ASSERTIONS=1 -o n-puzzle.js  -s WASM=1   --preload-file ../../../../disjoint_pattern_databases@/disjoint_pattern_databases -s ALLOW_MEMORY_GROWTH=1 -s EXIT_RUNTIME=1")
