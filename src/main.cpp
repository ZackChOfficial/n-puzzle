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
    // DDB_555::create();

    // auto t1 = high_resolution_clock::now();

    //  DDB_555::load();

    // auto t2 = high_resolution_clock::now();

    // auto dur = duration_cast<milliseconds>(t2 - t1);
    // cout << dur.count() << "ms\n";

    // unsigned long z1 = DDB_555::hash_state(DDB_555::s_p1.state, DDB_555::s_p1_ord);
    // unsigned long z2 = DDB_555::hash_state(DDB_555::s_p2.state, DDB_555::s_p2_ord);
    // unsigned long z3 = DDB_555::hash_state(DDB_555::s_p3.state, DDB_555::s_p3_ord);

    // printf("%0.20lu\n", z1);
    // printf("%0.20lu\n", z2);
    // printf("%0.20lu\n", z3);
    // int dist = z1 / (unsigned long)std::pow(10, 2 * 8);
    // cout << "dist : " << dist << "\n";
    //  printf("%0.20lu\n", (z1 - dist * (unsigned long)std::pow(10, 2 * 8)));

    DDB_555::load();
    vector<int> board = parse();
    Board b(board, (int)sqrt(board.size()));
    A_Star algo(board, Board::gen_solution(b.size), DDB_555::heuristic);
    // A_Star algo(board, Board::gen_solution(b.size), linear_conflict);
    // if (argc > 1)
    // {
    //     if (!strcmp("-s" ,argv[1]))
    //         assert(b.is_solvable() == true);
    //     else if (!strcmp("-u" ,argv[1]))
    //         assert(b.is_solvable() == false);
    // }
    // else {
    if (b.is_solvable())
    {
        cout << "Solvable\n";
        algo.run();
    }
    else
        cout << "Unsolvable\n";
    // }

    return 0;
}

// 00000000002111011000
// 00000000003332313020
// 00000000002313032202