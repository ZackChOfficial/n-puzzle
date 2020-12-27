#pragma once

#include <vector>
#include <memory>

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
    Board(std::vector<int> state) : state(state)
    {
    }
    Board(std::vector<int> state, int size) : state(state), size(size)
    {
    }

    static Board gen_solution(int size);

public:
    std::pair<int, int> get_position_of_zero();
    bool is_solvable();
    void print();


protected:
    std::vector<int> create_new(int index1, int index2);

public:
    template <typename T>
    friend std::vector<std::shared_ptr<T>> gen_next_states(std::shared_ptr<T> b);
};
