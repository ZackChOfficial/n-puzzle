#pragma GCC optimize("Ofast")
#include "parser.hpp"
#include "A_Star.class.hpp"
#include "Board.class.hpp"
#include <iostream>

using namespace std;

int main()
{
    vector<int> board = parse();
    // algo = new A_Star(board, sol);
    // algo->run();

    Board b(board,(int)sqrt(board.size()));
    if (b.is_solvable())
        cout << "Solvable\n";
    else
        cout << "Unsolvable\n";
    return 0;
}
