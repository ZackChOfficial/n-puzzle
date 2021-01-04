#include <iostream>
#include <cstring>
#include <cassert>
#include <limits>

#include "parser.hpp"
#include "A_Star.class.hpp"
#include "Board.class.hpp"
#include "heuristic_functions.hpp"
#include "Disjoint_database.hpp"

using namespace std;

int main(int argc, char **argv)
{
    DFS_Node p1(std::vector<int>{1, 2, -1, -1,
                             12, 13, 14, -1,
                             -1, 0, -1, -1,
                             -1, -1, -1, -1});

    p1.dist = 44;

    unsigned long z = DDB_555::hash(p1, DDB_555::s_p1_ord);
    printf("%0.20lu\n", z);
    cout << std::numeric_limits<unsigned long>::max() << "\n";

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
