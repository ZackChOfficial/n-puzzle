#include "n-puzzle.hpp"
#include "A_Star.class.hpp"
#include "Ida_Star.class.hpp"
#include "heuristic_functions.hpp"
#include "Disjoint_database.hpp"

std::string n_puzzle(Board &board, Options opts)
{
    if (!board.is_solvable())
        return std::string("Unsolvable\n");

    std::unique_ptr<Algo> algo;
    int (*heuristic)(std::vector<int> & state, const std::vector<int> &goal, const int size);

    switch (opts.heuristic)
    {
    case E_Heuristic::MANHATTAN_DISTANCE_PLUS_LNIEAR_CONFLICT:
        heuristic = linear_conflict;
        break;
    case E_Heuristic::DISJOINT_PATTERN_DATABASE:
        heuristic = dpdb_555;
        break;
    }

    switch (opts.algo)
    {
    case E_Algo::IDA_STAR:
        algo = std::make_unique<Ida_Star>(board.state, Board::gen_solution(board.size), heuristic, opts.method);
        break;
    case E_Algo::A_STAR:
        algo = std::make_unique<A_Star>(board.state, Board::gen_solution(board.size), heuristic, opts.method);
        break;
    }

    return algo->run();
}

void print_help()
{
    std::cout << "Usage: ./n-puzzle <options>\n"
              << "whare options are\n"
              << "-a :\n"
              << "  stands for (algorithm) which takes a string argument\n"
              << "  '-a a*' or 'a_star' to use A* algorithm\n"
              << "  '-a ida*' or 'ida_star' to use interactive deepening A*\n"
              << "-m :\n"
              << "  'wich stands for (method) and takes the folowing arguments\n"
              << "  '-m n' or '-m normal' wich applys NORMAL search method (distance from goal + distance from source)\n"
              << "  '-m g' or '-m greedy' wich applys only greedy search (distance from goal)\n"
              << "  '-m u' or '-m uniform' wich applys only uniform search (distance from source)\n"
              << "-h :\n"
              << "  stands for (heuristic), wich is the function that gets the distance from sourcein a* or ida* algorithm\n"
              << "  amd it takes the folwing algorithm\n"
              << "  '-h m+l' wich stands for 'manhatan distance + linear conflict'\n"
              << "  '-h dpdb' wich standss for disjoint pattern data base\n";
}
