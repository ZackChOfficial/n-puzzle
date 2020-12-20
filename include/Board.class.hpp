#pragma once

#include <vector>

class Board
{
public:
    std::vector<int>    body;
    std::pair<int,int>  get_position_of_zero();
    int                     size;
public:
    Board(std::vector<int> body): body(body)
    {
    }
    Board(std::vector<int> body, int    size) : body(body), size(size)
    {
    }

public:
    bool                    is_solvable();
    static Board            gen_solution(int size);
    void                    print();
};
