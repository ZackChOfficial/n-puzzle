#pragma GCC optimize("Ofast") 
#include "parser.hpp"
#include "A_Star.class.hpp"


using namespace std;

int main()
{
    vector<int> board;
    vector<int> sol{
        1, 2, 3,
        8, 0, 4,
        7, 6, 5};
    A_Star *algo;

    board = parse();
    algo = new A_Star(board, sol);
    algo->run();
    return 0;
}