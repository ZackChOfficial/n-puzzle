#include "Board.class.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>

/*
** a printer helper function
*/

void Board::print()
{
    for (auto i : state)
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
    std::vector<int> state(size * size);
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
                state[i + size * ui] = inc++;
            ui++;
        }
        // right columns travers
        else if (dir % 4 == 1)
        {
            for (int i = ui; i <= di; i++)
                state[ri + size * i] = inc++;
            ri--;
        }
        // down rows travers
        else if (dir % 4 == 2)
        {
            for (int i = ri; i >= li; i--)
                state[i + size * di] = inc++;
            di--;
        }
        // left columns travers
        else if (dir % 4 == 3)
        {
            for (int i = di; i >= ui; i--)
                state[li + size * i] = inc++;
            li++;
        }
        dir++;
    }

    return Board(state, size);
}

/**
 * This function check if the current board solvable or not
 * and return the boolean result
 * */

bool Board::is_solvable() const
{
    int time;
    int diff;
    std::pair<int, int> zero_in_sol;
    std::pair<int, int> zero_in_board;
    Board solution = gen_solution(size);
    Board current = *this;

    zero_in_sol = solution.get_position_of_zero();
    zero_in_board = current.get_position_of_zero();
    time = 0;
    diff = abs(zero_in_sol.first - zero_in_board.first) + abs(zero_in_sol.second - zero_in_board.second);
    for (size_t i = 0; i < solution.state.size(); i++)
    {
        for (size_t j = i; j < current.state.size(); j++)
        {
            if (current.state[j] == solution.state[i])
            {
                if (j != i)
                {
                    std::swap(current.state[j], current.state[i]);
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

std::pair<int, int> Board::get_position_of_zero() const
{
    int index;
    std::pair<int, int> ans;

    index = 0;
    for (size_t i = 0; i < state.size(); i++)
        if (state[i] == 0)
        {
            index = i + 1;
            break;
        }
    ans.first = (index % size == 0) ? size : index % size;
    ans.second = (index - ans.first) / size;
    return ans;
}

// std::vector<int> Board::create_new(int index1, int index2) const
// {
//     std::vector<int> newState = std::vector(state);
//     std::swap(newState[index1], newState[index2]);
//     return newState;
// }
