#include "Ida_Star.class.hpp"
#include "utils.hpp"

Ida_Star::Ida_Star(const std::vector<int> &initial, Board sol, int (*func)(std::vector<int> &state, const std::vector<int> &goal, const int size))
{
    Node::size = sqrt(initial.size());
    heuristic = func;
    root = Node(initial);
    root.gscore = 0;
    root.zero_position =   find(initial.begin(), initial.end(), 0) - initial.begin();
    goal = Node(sol.state);
}

void    Ida_Star::run()
{
    int threshold;
    threshold = heuristic(root.state, goal.state, goal.size);
    std::cout << threshold << "\n";
    while (1337)
    {
        threshold = dfs(root, 0, threshold);
        std::cout << threshold << "\n";
        if (threshold == -1)
        {
            std::cout << "Solved\n";
            break;
        }
        if (threshold == INT_MAX)
        {
            std::cout << "Unsolved\n";
            break;
        }
    }
}

int    Ida_Star::dfs(Node&  node, int g, int threshold)
{
    int f = g + heuristic(node.state, goal.state, goal.size);
    std::vector<Node>                               neighbor;
    if (f > threshold)
        return f;
    if (node.compare(goal.state))
    {
        std::cout << node.get_path() << std::endl;
        return -1;
    }
    int min = INT_MAX;
    neighbor = node.gen_next_states();
    for (auto &child : neighbor)
    {
        int temp = dfs(child, g+1, threshold);
        if (temp == -1)
        {
            return -1;
        }
        if (temp < min)
            min = temp;
    }
    return min;
}