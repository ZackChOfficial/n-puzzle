#pragma once
#include "Board.class.hpp"
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <memory>



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
