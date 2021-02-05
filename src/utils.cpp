#include "A_Star.class.hpp"
#include "Ida_Star.class.hpp"
#include "utils.hpp"
#include <iostream>

void throwError(std::string text)
{
    std::cerr << "ERROR: " << text << std::endl;
    exit(EXIT_FAILURE);
}

template <typename T>
std::string describe(Node &node, Options opts)
{
    std::string result;
    if (opts.only_steps)
        result += node.get_path() + "\n";
    else
    {
        result += "* Total selected node:                " + std::to_string(T::total_selected) + "\n";
        result += "* Max nodes in memory at same time:   " + std::to_string(T::max_states) + "\n";
        result += "* Steps required:                    " + node.get_path() + "\n";
        result += "* Number of steps required:           " + std::to_string(Node::path_length) + "\n";
    }
    return result;
}

template std::string describe<A_Star>(Node &node, Options opts);
template std::string describe<Ida_Star>(Node &node, Options opts);
