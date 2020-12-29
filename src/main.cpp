#pragma GCC optimize("Ofast")
#include "parser.hpp"
#include "A_Star.class.hpp"
#include "Board.class.hpp"
#include "heuristic_functions.hpp"
#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

int main(int argc, char **argv)
{
    vector<int> board = parse();
    Board b(board,(int)sqrt(board.size()));
    A_Star algo(board, Board::gen_solution(b.size), manhattan_distance);
    if (argc > 1)
    {
        if (!strcmp("-s" ,argv[1]))
            assert(b.is_solvable() == true);
        else if (!strcmp("-u" ,argv[1]))
            assert(b.is_solvable() == false);
    }
    else {
        if (b.is_solvable())
        {
            cout << "Solvable\n";
            algo.run();
        }
        else
            cout << "Unsolvable\n";
    }
    return 0;
}
