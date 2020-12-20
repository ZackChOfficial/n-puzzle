#pragma GCC optimize("Ofast")
#include "parser.hpp"
#include "A_Star.class.hpp"
#include "Board.class.hpp"
#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

int main(int argc, char **argv)
{
    vector<int> board = parse();
    // algo = new A_Star(board, sol);
    // algo->run();

    Board b(board,(int)sqrt(board.size()));
    if (argc > 1)
    {
        if (!strcmp("-s" ,argv[1]))
            assert(b.is_solvable() == true);
        else if (!strcmp("-u" ,argv[1]))
            assert(b.is_solvable() == false);
    }
    else {
        if (b.is_solvable())
            cout << "Solvable\n";
        else
            cout << "Unsolvable\n";
    }
    return 0;
}
