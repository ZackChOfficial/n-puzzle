#include <iostream>
#include <cstring>
#include <cassert>
#include <limits>
#include <chrono>
#include "parser.hpp"
#include "A_Star.class.hpp"
#include "Board.class.hpp"
#include "heuristic_functions.hpp"
#include "Disjoint_database.hpp"

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv)
{

    DDB_555::load();
    vector<int> board = parse();
    Board b(board, (int)sqrt(board.size()));
    A_Star algo(board, Board::gen_solution(b.size), linear_conflict);
    // A_Star algo(board, Board::gen_solution(b.size), DDB_555::heuristic);
    // A_Star algo(board, Board::gen_solution(b.size), manhattan_distance);
    if (b.is_solvable())
    {
        cout << "Solvable\n";
        algo.run();
    }
    else
        cout << "Unsolvable\n";


    return 0;
}