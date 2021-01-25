#include "parser.hpp"
#include "A_Star.class.hpp"
#include "Board.class.hpp"
#include "heuristic_functions.hpp"
#include "Disjoint_database.hpp"
#include "Ida_Star.class.hpp"
#include "options.hpp"

// using namespace std;m:


int main(int argc, char **argv)
{

    std::vector<int> board = parse();
    Board b(board, (int)sqrt(board.size()));
    if (b.is_solvable())
    {
        if (argv[1] && argv[1][0] == '1')
        {
            Ida_Star algo(board, Board::gen_solution(b.size), linear_conflict, E_Method::Uniform_Cost);
            algo.run();
        }
        else
        {
            A_Star algo(board, Board::gen_solution(b.size), linear_conflict, E_Method::Uniform_Cost);
            algo.run();
        }
    }
    else
        std::cout << "Unsolvable\n";

    return 0;
}
