#pragma once
#include "Board.class.hpp"
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include "Board.class.hpp"

struct Node : public Board
{
public:
    static  int             size;
    static int              path_length;
    std::shared_ptr<Node>   parent;
    int                     gscore;
    int                     hscore;
    int                     number_of_moves;

public:
    Node();
    Node(const std::vector<int> &data);

    bool                compare(std::vector<int> &rhs) const;
    std::string         get_path() const;
    int                 print() const;
    std::vector<Node>   gen_next_states() const;
    Node                create_new(E_Move    move) const;
};
