#include "A_Star.class.hpp"

/**
 * Basic Node Functions
*/
Node::Node(std::vector<int> const &data)
{
    parent = nullptr;
    gscore = 999999;
    hscore = 999999;
    state.reserve(data.size());
    copy(data.begin(), data.end(), back_inserter(state));
}

int    Node::print()
{
    int x = 0;
    if (parent)
    {
       x =  parent->print();
    }
    x++;
    for (int i = 0; i < (int)sqrt(state.size()); i++)
    {
        for (int j = 0; j < (int)sqrt(state.size()); j++)
        {
            std::cout << state[i*(int)sqrt(state.size()) + j] << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n\n";
    return x;
}
std::vector<std::shared_ptr<Node>> Node::next_states()
{
    int                     index;
    int                     size;
    std::shared_ptr<Node>   tmp;
    std::vector<std::shared_ptr<Node>>  new_states;


    size = sqrt(state.size());
    index = find(state.begin(), state.end(), 0) - state.begin();
    if (index - size >= 0)
    {
        tmp = std::make_shared<Node>(create_new(index, index - size));
        tmp->move = "U";
        new_states.push_back(tmp);
        
    }
    if (index - 1 >= 0 && ((index + 1)%size == 0?size:(index + 1)%size)  - 1 > 0)
    {
        tmp = std::make_shared<Node>(create_new(index, index - 1));
        tmp->move = "L";
        new_states.push_back(tmp);
    }
    if (index + 1 < state.size() && ((index + 1)%size == 0?size:(index + 1)%size) + 1 <= size)
    {
        tmp = std::make_shared<Node>(create_new(index, index + 1));
        tmp->move = "R";
        new_states.push_back(tmp);
    }
    if (index + size < state.size())
    {
        tmp = std::make_shared<Node>(create_new(index, index + size));
        tmp->move = "D";
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

bool Node::compare(std::vector<int> &rhs)
{
    if (state.size() != rhs.size())
        return false;
    for (int i = 0; i < state.size(); i++)
        if (state[i] != rhs[i])
            return false;
    return true;
}

std::string         Node::get_path()
{
    std::string path;
    if (parent)
    {
        path = parent->get_path();
        if (path != "")
            return path +" " + move;
    }
    return move;
}
/**
 * A Star Functions
*/
A_Star::A_Star(std::vector<int> &initial, Board sol, int (*func)(std::vector<int> &state, std::vector<int> &goal))
{
    std::shared_ptr<Node>                   current;
    bool                                    solved;
    std::vector<std::shared_ptr<Node>>     neighbor;

    heuristic = func;
    root = std::make_shared<Node>(initial);
    root->gscore = 0;
    root->move = "";
    goal = std::make_shared<Node>(sol.body);
}

void    A_Star::run()
{
    std::shared_ptr<Node>               current;
    bool                                solved;
    std::vector<std::shared_ptr<Node>>  neighbor;
    int                 tentative_gScore;
    std::string         path;
    
    root->hscore = heuristic(root->state, goal->state);
    in_queue[root->state] = root;
    states.push(root);
    solved = false;
    path = "";
    int i = 0;
    while (!in_queue.empty() && !solved)
    {
        i++;
        current = states.top();
        if (current->compare(goal->state))
        {
            solved = true;
        }
        else {
            states.pop();
            visited.insert(current->state);
            in_queue.erase(current->state);
            neighbor = current->next_states();
            for (auto& child : neighbor)
            {
                if (visited.find(child->state) != visited.end())
                {
                    continue;
                }
                child->gscore = current->gscore + 1;
                child->hscore = heuristic(child->state, goal->state);
                child->parent = current;
                if (in_queue.find(child->state) != in_queue.end())
                {
                    std::shared_ptr<Node> exist = in_queue[child->state];
                    if (child->gscore < exist->gscore)
                    {
                        exist->gscore = child->gscore;
                        exist->parent = current;
                    }
                    continue;
                }
                states.push(child);
                in_queue[child->state] = child;
            }
        }
        // std::cout << i << std::endl;
    }
    if (solved)
    {
        std::cout << "Solved\nNumber of Iteration: " << i << std::endl;
        std::cout << "Path:  " << current->get_path() << std::endl;
        // current->print();
    }
    else std::cout << "Empty Stack\n";
}