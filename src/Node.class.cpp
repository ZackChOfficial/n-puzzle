#include "A_Star.class.hpp"
#include "utils.hpp"

/**
 * Basic Node Functions
*/
Node::Node(std::vector<int> const &data)
{
    parent = nullptr;
    gscore = 999999;
    hscore = 999999;
    state = data;
    move = "";
}

int Node::print()
{
    int x = 0;
    if (parent)
    {
        x = parent->print();
    }
    x++;
    for (int i = 0; i < (int)sqrt(state.size()); i++)
    {
        for (int j = 0; j < (int)sqrt(state.size()); j++)
        {
            std::cout << state[i * (int)sqrt(state.size()) + j] << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n\n";
    return x;
}

bool Node::compare(std::vector<int> &rhs)
{
    if (state.size() != rhs.size())
        return false;
    for (int i = 0; i < state.size(); i++)
        if (state[i] != rhs[i])
            return false;
    return true;
}

std::string Node::get_path()
{
    std::string path;
    if (parent)
    {
        path = parent->get_path();
        if (path != "")
            return path + " " + move;
    }
    return move;
}