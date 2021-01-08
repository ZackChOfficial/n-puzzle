#pragma once

#include <vector>
#include <memory>
#include <string>

class Board
{
public:
    std::vector<int> state;
    int size;
    std::string move;

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
    std::pair<int, int> get_position_of_zero();
    bool is_solvable();
    void print();

protected:
    std::vector<int> create_new(int index1, int index2) const;

public:
    std::vector<Board> gen_next_states();
};
