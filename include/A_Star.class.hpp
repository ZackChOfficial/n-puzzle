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

struct Node : public Board
{
public:
    static  int size;
    std::shared_ptr<Node> parent;
    int         gscore;
    int         hscore;

public:
    Node();
    Node(const std::vector<int> &data);
    bool compare(std::vector<int> &rhs) const;
    std::string get_path() const;
    int print() const;
    std::vector<Node>       gen_next_states() const;
    Node                create_new(E_Move    move) const;
};

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
    std::priority_queue<Node, std::vector<Node>, CompareNode> states;
    std::set<std::vector<int>> visited;
    std::map<std::vector<int>, Node> in_queue;
    Node root;
    Node goal;
    int (*heuristic)(std::vector<int> &state, const std::vector<int> &goal);

public:
    A_Star(const std::vector<int> &initial, Board sol, int (*func)(std::vector<int> &state, const std::vector<int> &goal));
    void run();
};
