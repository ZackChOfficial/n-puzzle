#pragma once

#include <vector>

class Board
{
private:
    std::vector<int> body;

public:
    Board(std::vector<int> body) : body(body)
    {
    }

public:
    bool is_solvable();
    static Board gen_solution(int size);
    void print();

};
