#pragma once

#include <vector>
#include <memory>
#include <string>

class Board
{
public:
    enum E_Move{
        UP,
        RIGHT,
        DOWN,
        LEFT
    };
    std::vector<int> state;
    int              size;
    E_Move           move;
    int              zero_position;

public:
    Board()
    {
    }
    Board(const std::vector<int> &state) : state(state), size(state.size())
    {
    }
    Board(const std::vector<int> &state,const int &size) : state(state), size(size)
    {
    }

    static Board gen_solution(int size);

public:
    std::pair<int, int> get_position_of_zero() const;
    bool is_solvable() const;
    void print();


public:
    std::vector<Board> gen_next_states();
};
