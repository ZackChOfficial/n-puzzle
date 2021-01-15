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
#include "Ida_Star.class.hpp"

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv)
{

//    DDB_663 db_663;

//     db_663.create();
    vector<int> board = parse();
    Board b(board, (int)sqrt(board.size()));
   
    // A_Star algo(board, Board::gen_solution(b.size), DDB_555::heuristic);
    // A_Star algo(board, Board::gen_solution(b.size), manhattan_distance);
    if (b.is_solvable())
    {
        
        cout << "Solvable\n";
        if (argv[1] && argv[1][0] == '1')
        {
            Ida_Star algo(board, Board::gen_solution(b.size), linear_conflict);
            algo.run();
        }
        else
        {
            A_Star algo(board, Board::gen_solution(b.size), linear_conflict);
            algo.run();
        }
    }
    else
        cout << "Unsolvable\n";


    return 0;
}