#include "utils.hpp"
#include "A_Star.class.hpp"

void throwError(std::string text)
{
    std::cerr << "ERROR: " << text << std::endl;
    exit(EXIT_FAILURE);
}

template <typename T>
std::vector<std::shared_ptr<T>> gen_next_states(std::shared_ptr<T> b)
{
    int index;
    int size;
    std::shared_ptr<T> tmp;
    std::vector<std::shared_ptr<T>> new_states;

    size = sqrt(b->state.size());
    index = find(b->state.begin(), b->state.end(), 0) - b->state.begin();
    if (index - size >= 0)
    {
        tmp = std::make_shared<T>(b->create_new(index, index - size));
        tmp->move = "U";
        new_states.push_back(tmp);
    }
    if (index - 1 >= 0 && ((index + 1) % size == 0 ? size : (index + 1) % size) - 1 > 0)
    {
        tmp = std::make_shared<T>(b->create_new(index, index - 1));
        tmp->move = "L";
        new_states.push_back(tmp);
    }
    if (index + 1 < b->state.size() && ((index + 1) % size == 0 ? size : (index + 1) % size) + 1 <= size)
    {
        tmp = std::make_shared<T>(b->create_new(index, index + 1));
        tmp->move = "R";
        new_states.push_back(tmp);
    }
    if (index + size < b->state.size())
    {
        tmp = std::make_shared<T>(b->create_new(index, index + size));
        tmp->move = "D";
        new_states.push_back(tmp);
    }
    return new_states;
}

template std::vector<std::shared_ptr<Node>> gen_next_states(std::shared_ptr<Node> b);
