#pragma once
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>
#include "Board.class.hpp"
#include <map>
#include <memory>

struct Node {
public:
    std::vector<int>        state;
    std::shared_ptr<Node>   parent;
    int                     gscore;
    int                     hscore;
    std::string             move;

public:
    Node(std::vector<int> const &data);
    std::vector<std::shared_ptr<Node>> next_states();
    bool                compare(std::vector<int> &rhs);
    std::string         get_path();
    int                 print();
    
private:
    std::vector<int>    create_new(int index1, int index2);
};

struct CompareNode
{
    inline bool    operator()(const std::shared_ptr<Node> lhs, const std::shared_ptr<Node> rhs) const
    {
        // std::cout << "      " << lhs->hscore + lhs->gscore << " > " << rhs->hscore + rhs->gscore << std::endl;
        return lhs->hscore + lhs->gscore > rhs->hscore + rhs->gscore;
    }
};

class A_Star {
private:
    std::priority_queue<std::shared_ptr<Node>,std::vector<std::shared_ptr<Node>>, CompareNode> states;
    std::set<std::vector<int>>                                  visited;
    std::map<std::vector<int>, std::shared_ptr<Node>>                                  in_queue;
    std::shared_ptr<Node>                                       root;
    std::shared_ptr<Node>                                       goal;
    int                                                        (*heuristic)(std::vector<int> &state, std::vector<int> &goal);

public:
    A_Star(std::vector<int> &initial,  Board sol, int (*func)(std::vector<int> &state, std::vector<int> &goal));
    ~A_Star();
    void                                                        run();
};
