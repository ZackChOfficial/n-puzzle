#pragma once
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <memory>

#include "Board.class.hpp"

struct Node : public Board {
public:
    std::shared_ptr<Node>   parent;
    int                     gscore;
    int                     hscore;

public:
    Node(const std::vector<int> &data);
    bool                compare(std::vector<int> &rhs);
    std::string         get_path();
    int                 print();
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
    int                                                        (*heuristic)(std::vector<int> &state, const std::vector<int> &goal);

public:
    A_Star(std::vector<int> &initial,  Board sol, int (*func)(std::vector<int> &state, const std::vector<int> &goal));
    void                                                        run();
};
