#include <iostream>
#include <cstring>
#include <cassert>

#include "parser.hpp"
#include "A_Star.class.hpp"
#include "Board.class.hpp"
#include "heuristic_functions.hpp"
#include "Disjoint_database.hpp"

using namespace std;

int main(int argc, char **argv)
{
    DDB_555 db;
    db.create();
    // vector<int> board = parse();
    // Board b(board,(int)sqrt(board.size()));
    // A_Star algo(board, Board::gen_solution(b.size), linear_conflict);
    // if (argc > 1)
    // {
    //     if (!strcmp("-s" ,argv[1]))
    //         assert(b.is_solvable() == true);
    //     else if (!strcmp("-u" ,argv[1]))
    //         assert(b.is_solvable() == false);
    // }
    // else {
    //     if (b.is_solvable())
    //     {
    //         cout << "Solvable\n";
    //         algo.run();
    //     }
    //     else
    //         cout << "Unsolvable\n";
    // }

    return 0;
}
