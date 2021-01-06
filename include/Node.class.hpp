#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <cmath>


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
