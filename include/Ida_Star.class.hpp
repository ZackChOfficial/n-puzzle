#pragma once
#include <iostream>
#include "Node.class.hpp"

class Ida_Star {
private:
    Node    root;
    Node    goal;
    int     (*heuristic)(std::vector<int> &state, const std::vector<int> &goal, const int size);
    int     dfs(Node& , int, int);
public:
    Ida_Star(const std::vector<int> &initial, Board sol, int (*func)(std::vector<int> &state, const std::vector<int> &goal, const int size));
    void    run();
};