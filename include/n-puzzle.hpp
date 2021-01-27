#pragma once

#include <string>

#include "options.hpp"
#include "Board.class.hpp"

class Algo {
public:
    virtual std::string run(){return std::string();};
};

std::string n_puzzle(Board &board, Options opts);
void print_help();
