#pragma once

#include <vector>

class Board
{
private:
    std::vector<int>    body;
    int                 size;
    std::pair<int,int>  get_position_of_zero();
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
