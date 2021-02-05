#pragma once

#include <string>

#include "options.hpp"
#include "Board.class.hpp"

class Algo {
public:
    virtual std::string run(Options opts){return std::string();};
};

std::string n_puzzle(std::vector<int> state, Options opts);
void print_help();
