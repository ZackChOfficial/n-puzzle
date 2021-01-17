#include "A_Star.class.hpp"
#include "utils.hpp"

/**
 * Basic Node Functions
*/

int Node::size = 0;
int Node::path_length = 0;

Node::Node(std::vector<int> const &data)
    : parent(nullptr), gscore(99999), hscore(99999)
{
    state = data;

}

Node::Node()
    : parent(nullptr), gscore(99999), hscore(99999)
{
    zero_position = 0;
}

int Node::print() const
{
    int x = 0;
    if (parent)
    {
        x = parent->print();
    }
    x++;
    std::cout << "Move:  " << move << "  " << &move << "\n";
    for (int i = 0; i < (int)sqrt(state.size()); i++)
    {
        for (int j = 0; j < (int)sqrt(state.size()); j++)
        {
            printf("%2d  ", state[i * (int)sqrt(state.size()) + j]);
        }
        std::cout << std::endl;
    }
    std::cout << "\n\n";
    return x;
}

bool Node::compare(std::vector<int> &rhs) const
{
    if (state.size() != rhs.size())
        return false;
    for (int i = 0; i < state.size(); i++)
        if (state[i] != rhs[i])
            return false;
    return true;
}

std::string Node::get_path() const
{
    std::string path;
    std::string moves[4] = {"U","R","D","L"};

    if (parent)
    {
        path = parent->get_path();
        path_length++;
        return path + " " + moves[move];
    }
    else
    return "";
}

Node Node::create_new(E_Move move) const
{
    Node newElem = Node(this->state);

    switch (move)
    {
    case UP:
        std::swap(newElem.state[zero_position], newElem.state[zero_position - size]);
        newElem.zero_position = zero_position - size;
        newElem.move = UP;
        break;
    case RIGHT:
        std::swap(newElem.state[zero_position], newElem.state[zero_position + 1]);
        newElem.zero_position = zero_position + 1;
        newElem.move = RIGHT;
        break;
    case DOWN:
        std::swap(newElem.state[zero_position], newElem.state[zero_position + size]);
        newElem.zero_position = zero_position + size;
        newElem.move = DOWN;
        break;
    case LEFT:
        std::swap(newElem.state[zero_position], newElem.state[zero_position - 1]);
        newElem.zero_position = zero_position - 1;
        newElem.move = LEFT;
        break;
    }
    newElem.parent = std::make_shared<Node>(*this);
    return newElem;
}

std::vector<Node> Node::gen_next_states() const
{
    std::vector<Node> new_states;

    if (zero_position - size >= 0)
        new_states.push_back(create_new(UP));
    if (zero_position % size - 1 >= 0)
        new_states.push_back(create_new(LEFT));
    if (zero_position % size + 1 < size)
        new_states.push_back(create_new(RIGHT));
    if (zero_position + size < state.size())
        new_states.push_back(create_new(DOWN));
    return new_states;
}
