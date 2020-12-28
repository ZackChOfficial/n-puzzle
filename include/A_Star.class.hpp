#pragma once
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>
#include "Board.class.hpp"
#include <map>

struct Node {
public:
    std::vector<int>    state;
    Node                *parent;
    int                 gscore;
    int                 hscore;
    int                 score;
    std::string         move;

public:
    Node(std::vector<int> const &data);
    std::vector<Node *> next_states();
    bool                compare(std::vector<int> &rhs);
    std::string         get_path();
    int                 print();
    
private:
    std::vector<int>    create_new(int index1, int index2);
};

struct CompareNode
{
    inline bool    operator()(const Node* lhs, const Node* rhs) const
    {
        // std::cout << "      " << lhs->hscore + lhs->gscore << " > " << rhs->hscore + rhs->gscore << std::endl;
        return lhs->hscore + lhs->gscore > rhs->hscore + rhs->gscore;
    }
};

class A_Star {
private:
    std::priority_queue<Node *,std::vector<Node*>, CompareNode> states;
    std::set<std::vector<int>>                                  visited;
    std::map<std::vector<int>, Node *>                                  in_queue;
    Node                                                        *root;
    Node                                                        *goal;
    int                                                        (*heuristic)(std::vector<int> &state, std::vector<int> &goal);

public:
    A_Star(std::vector<int> &initial,  Board sol, int (*func)(std::vector<int> &state, std::vector<int> &goal));
    ~A_Star();
    void                                                        run();
};
