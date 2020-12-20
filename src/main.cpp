#pragma GCC optimize("Ofast")
#include "parser.hpp"
#include "A_Star.class.hpp"
#include "Board.class.hpp"
#include "heuristic_functions.hpp"
#include <iostream>

using namespace std;

int main()
{
    vector<int> board = parse();
    // algo->run();

    Board b(board,(int)sqrt(board.size()));
    if (b.is_solvable())
    {   
        cout << "Solvable\n";
        A_Star *algo = new A_Star(board, b.gen_solution(b.size), manhattan_distance);
        algo->run();
    }
    else
        cout << "Unsolvable\n";
    return 0;
}
