#ifndef __A_STAR
# define __A_STAR
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>


struct Node {
    std::vector<int>    state;
    Node                *parent;
    int                 hscore;
    int                 gscore;

public:
    Node(std::vector<int> const &data);
    std::vector<Node *> next_states();
    void                manhattan_distance(std::vector<int> &goal);
    void                linear_conflicts(std::vector<int> &goal);
    void                hamming_distance(std::vector<int> &goal);
    bool                operator==(const Node &rhs);
    
private:
    std::vector<int>    create_new(int index1, int index2);
};

struct CompareNode
{
    inline bool    operator()(const Node* lhs, const Node* rhs) const
    {
        return lhs->hscore + lhs->gscore < rhs->hscore + lhs->gscore;
    }
};

class A_Star {
private:
    std::priority_queue<Node *,std::vector<Node*>, CompareNode> states;
    std::set<std::vector<int>>                                  visited;
    std::set<std::vector<int>>                                  in_queue;
    Node                                                        *root;
    Node                                                        *goal;

public:
    A_Star(std::vector<int> &initial, std::vector<int> &sol);
    ~A_Star();
    void                                                        run();
};

#endif