#include "A_Star.class.hpp"


/**
 * Basic Node Functions
*/

Node::Node(std::vector<int> const &data)
{
    parent = nullptr;
    gscore = INT32_MAX;
    state.reserve(data.size());
    copy(data.begin(), data.end(), back_inserter(state));
}

std::vector<Node *> Node::next_states()
{
    int             index;
    int             size;
    Node            *tmp;
    std::vector<Node *>  new_states;


    size = sqrt(state.size());
    index = state.begin() - find(state.begin(), state.end(), 0);
    if (index - size >= 0)
    {
        tmp = new Node(create_new(index, index - size));
        new_states.push_back(tmp);
    }
    if (index - 1 >= 0)
    {
        tmp = new Node(create_new(index, index - 1));
        new_states.push_back(tmp);
    }
    if (index + 1 < state.size())
    {
        tmp = new Node(create_new(index, index + 1));
        new_states.push_back(tmp);
    }
    if (index + size < state.size())
    {
        tmp = new Node(create_new(index, index + size));
        new_states.push_back(tmp);
    }
    return new_states;
}

std::vector<int> Node::create_new(int index1, int index2)
{
    std::vector<int> newState(state);
    std::swap(newState[index1], newState[index2]);
    return newState;
}

void        Node::manhattan_distance(std::vector<int> &goal)
{
    hscore = 0;
    for (int i=0;i<goal.size(); i++)
    {
        for (int j=0;j < state.size(); j++)
        {
            if (goal[i] == state[j])
            {
                hscore += abs(i-j);
            }
        }
    }
    hscore *= -1;
}

void        Node::linear_conflicts(std::vector<int> &goal)
{
    // need to be implemented
}

void        Node::hamming_distance(std::vector<int> &goal)
{
    // need to be implemented
}

bool        Node::operator==(const Node &rhs)
{
    if (state.size() != rhs.state.size())
        return false;
    for (int i=0;i < state.size(); i++)
    {
        if (state[i] != rhs.state[i])
            return false;
    }
    return true;
}

/**
 * A Star Functions
*/


A_Star::A_Star(std::vector<int> &initial, std::vector<int> &sol)
{
    Node                *current;
    bool                solved;
    std::vector<Node *> neighbor;

    root = new Node(initial);
    solved = false;
    goal = new Node(sol);
    states.push(root);
    in_queue.insert(root->state);
    while (!states.empty())
    {
        current = states.top();
        states.pop();
        visited.insert(current->state);
        in_queue.erase(current->state);
        if (goal == current)
        {
            solved = true;
            break;
        }
        neighbor = current->next_states();
        for (Node *state : neighbor)
        {
            if (visited.find(state->state) == visited.end() && in_queue.find(state->state) == in_queue.end())
            {
                state->parent = current;
                state->hamming_distance(sol);
                states.push(state);
                in_queue.insert(state->state);
            }
        }
    }
}