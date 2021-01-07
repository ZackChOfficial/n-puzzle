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
}

int Node::print()
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
            printf("%2d  ", state[i * (int)sqrt(state.size()) + j] );
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
/**
 * A Star Functions
*/
A_Star::A_Star(std::vector<int> &initial, Board sol, int (*func)(std::vector<int> &state, const std::vector<int> &goal))
{
    std::shared_ptr<Node> current;
    bool solved;
    std::vector<std::shared_ptr<Node>> neighbor;

    heuristic = func;
    root = std::make_shared<Node>(initial);
    root->gscore = 0;
    root->move = "";
    goal = std::make_shared<Node>(sol.state);
}

void A_Star::run()
{
    std::shared_ptr<Node> current;
    bool solved;
    std::vector<std::shared_ptr<Node>> neighbor;
    int tentative_gScore;
    std::string path;

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
        else
        {
            states.pop();
            visited.insert(current->state);
            in_queue.erase(current->state);
            neighbor = gen_next_states(current);
            for (auto &child : neighbor)
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
    }
    if (solved)
    {
        std::cout << "Solved\nNumber of Iteration: " << i << std::endl;
        std::cout << "Path:  " << current->get_path() << std::endl;
        current->print();
    }
    else
        std::cout << "Empty Stack\n";
}
