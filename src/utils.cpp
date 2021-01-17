#include "A_Star.class.hpp"
#include "Ida_Star.class.hpp"
#include "utils.hpp"
#include <iostream>

void throwError(std::string text)
{
    std::cerr << "ERROR: " << text << std::endl;
    exit(EXIT_FAILURE);
}

template<typename T>
void    describe(Node& node)
{
    std::cout << "* Total selected node:                " << T::total_selected << "\n";
    std::cout << "* Max nodes in memory at same time:   " << T::max_states << "\n";
    std::cout << "* Steps required:                    " << node.get_path() << "\n";
    std::cout << "* Number of steps required:           " << Node::path_length << "\n";
}

template void    describe<A_Star>(Node& node);
template void    describe<Ida_Star>(Node& node);