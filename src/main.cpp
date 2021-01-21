
#include "parser.hpp"
#include "A_Star.class.hpp"
#include "Board.class.hpp"
#include "heuristic_functions.hpp"
#include "Disjoint_database.hpp"
#include "Ida_Star.class.hpp"
#include "Mode.class.hpp"

using namespace std;

int main(int argc, char **argv)
{

//    DDB_663 db_663;

//     db_663.create();
    vector<int> board = parse();
    Board b(board, (int)sqrt(board.size()));
    if (b.is_solvable())
    {
        if (argv[1] && argv[1][0] == '1')
        {
            Ida_Star algo(board, Board::gen_solution(b.size), linear_conflict, Mode::E_Greedy);
            algo.run();
        }
        else
        {
            A_Star algo(board, Board::gen_solution(b.size), linear_conflict, Mode::E_Uniform_Cost);
            algo.run();
        }
    }
    else
        cout << "Unsolvable\n";


    return 0;
}