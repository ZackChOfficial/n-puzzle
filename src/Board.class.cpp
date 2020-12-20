#include "Board.class.hpp"
#include <iostream>
#include <cmath>
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

    return Board(body, size);
}

/**
 * This function check if the current board solvable or not
 * and return the boolean result
 * */

bool    Board::is_solvable()
{
    int                 index;
    int                 time;
    int                 diff;
    std::pair<int,int>  zero_in_sol;
    std::pair<int,int>  zero_in_board;
    Board               solution = gen_solution(size);

    zero_in_sol = solution.get_position_of_zero();
    zero_in_board = get_position_of_zero();
    time = 0;
    diff = abs(zero_in_sol.first - zero_in_board.first) + abs(zero_in_sol.second - zero_in_board.second);
    for (int i = 0; i< solution.body.size(); i++)
    {
        for (int j = i; j < body.size(); j++)
        {
            if (body[j] == solution.body[i])
            {
                if (j != i)
                {
                    std::swap(body[j], body[i]);
                    time++;
                }
            }
        }
    }
    return diff % 2 == time % 2;
}

/**
 * this function return the position of the empty cell(number zero)
 * x:(pair.first) fo the column position
 * y:(pair.second) fo the row position
 * */

std::pair<int, int> Board::get_position_of_zero()
{
    int                 index;
    std::pair<int, int> ans;

    index = 0;
    for (int i=0; i < body.size(); i++)
        if (body[i] == 0)
        {
            index = i+1;
            break;
        }
    ans.first = (index % size == 0) ? size : index % size;
    ans.second = (index - ans.first) / size;
    return ans;
}
