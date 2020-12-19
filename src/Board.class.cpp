#include "Board.class.hpp"
#include <iostream>

/*
** a printer helper function
*/

void Board::print()
{
    for (auto i : body)
        std::cout << i << " ";
    std::cout << "\n";
}

/*
** this function generates the target solution for a specific
** game board size, and it must be in a spiral form.
** for example a taget solution for size 3 board :
**                     1  2  3
**                     8  0  4
**                     7  6  5
*/

Board Board::gen_solution(int size)
{
    std::vector<int> body(size * size);
    // index in 'body'
    int bi;
    int inc = 1;
    int li = 0, ri = size - 1, ui = 0, di = size - 1;
    /*
        direction in whitch we traverse
        0 : left->right, 1 : top->bottom ....
    */
    int dir = 0;
    while (li <= ri)
    {
        inc = inc == size * size ? 0 : inc;
        // upper rows traverse
        if (dir % 4 == 0)
        {
            for (int i = li; i <= ri; i++)
                body[i + size * ui] = inc++;
            ui++;
        }
        // right columns travers
        else if (dir % 4 == 1)
        {
            for (int i = ui; i <= di; i++)
                body[ri + size * i] = inc++;
            ri--;
        }
        // down rows travers
        else if (dir % 4 == 2)
        {
            for (int i = ri; i >= li; i--)
                body[i + size * di] = inc++;
            di--;
        }
        // left columns travers
        else if (dir % 4 == 3)
        {
            for (int i = di; i >= ui; i--)
                body[li + size * i] = inc++;
            li++;
        }
        dir++;
    }

    return Board(body);
}
