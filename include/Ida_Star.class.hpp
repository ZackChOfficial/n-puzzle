#pragma once
#include <iostream>
#include "Node.class.hpp"
#include <climits>
#include "utils.hpp"
#include <string>
#include "options.hpp"

class Ida_Star {
private:
    Node    root;
    Node    goal;
    Node    solution;
    int     (*heuristic)(std::vector<int> &state, const std::vector<int> &goal, const int size);
    int     dfs(Node& , int, int);
    static int                                                  total_selected;
    static int                                                  max_states;
    static int                                                  in_memory;
    static E_Method                                                 mode;

public:
    Ida_Star(const std::vector<int> &initial, Board sol, int (*func)(std::vector<int> &state, const std::vector<int> &goal, const int size), E_Method running_mode);
    void            run();
    template<typename T>
    friend   void    describe(Node&);
};
