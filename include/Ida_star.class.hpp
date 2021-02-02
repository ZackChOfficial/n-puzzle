#pragma once

#include <iostream>
#include <string>
#include <climits>

#include "n-puzzle.hpp"
#include "Node.class.hpp"
#include "utils.hpp"
#include "options.hpp"

class Ida_Star : public Algo
{
private:
    Node root;
    Node goal;
    Node solution;
    int (*heuristic)(std::vector<int> &state, const std::vector<int> &goal, const int size);
    int dfs(Node &, int, int);
    static int total_selected;
    static int max_states;
    static int in_memory;
    static E_Method mode;

public:
    Ida_Star(const std::vector<int> &initial, Board sol, int (*func)(std::vector<int> &state, const std::vector<int> &goal, const int size), E_Method running_mode);
    std::string run(Options opts);
    template <typename T>
    friend std::string describe(Node &, Options);
};
