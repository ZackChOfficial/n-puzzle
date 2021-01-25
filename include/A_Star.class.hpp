#pragma once
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>

#include "utils.hpp"
#include "Node.class.hpp"
#include "options.hpp"

struct CompareNode
{
    inline bool operator()(const Node lhs, const Node rhs) const
    {
        return lhs.hscore + lhs.gscore > rhs.hscore + rhs.gscore;
    }
};

class A_Star
{
private:
    static int                                                  total_selected;
    static int                                                  max_states;
    static E_Method                                                 mode;
    std::priority_queue<Node, std::vector<Node>, CompareNode>   states;
    std::set<std::vector<int>>                                  visited;
    std::unordered_map<std::string, Node>                       in_queue;
    Node                                                        root;
    Node                                                        goal;
    int     (*heuristic)(std::vector<int> &state, const std::vector<int> &goal, const int size);

public:
    A_Star(const std::vector<int> &initial, Board sol, int (*func)(std::vector<int> &state, const std::vector<int> &goal, const int size), E_Method running_mode);
    void            run();
    template<typename T>
    friend   void    describe(Node&);
};
