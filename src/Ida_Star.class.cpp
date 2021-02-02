#include "Ida_Star.class.hpp"
#include "utils.hpp"

/**
 * Ida Star Functions
*/

int Ida_Star::total_selected = 0;
int Ida_Star::max_states = 0;
int Ida_Star::in_memory = 0;
E_Method Ida_Star::mode = E_Method::Normal;

Ida_Star::Ida_Star(const std::vector<int> &initial, Board sol, int (*func)(std::vector<int> &state, const std::vector<int> &goal, const int size), E_Method running_mode)
{
    Node::size = sqrt(initial.size());
    heuristic = func;
    root = Node(initial);
    root.gscore = 0;
    root.zero_position = find(initial.begin(), initial.end(), 0) - initial.begin();
    goal = Node(sol.state);
    mode = running_mode;
}

std::string Ida_Star::run(Options opts)
{
    std::string result;
    int threshold;
    threshold = heuristic(root.state, goal.state, goal.size);
    while (1337)
    {
        threshold = dfs(root, 0, threshold);
        if (threshold == -1)
            break;
        if (threshold == INT_MAX)
            break;
    }
    if (threshold == -1)
        result += describe<Ida_Star>(solution, opts);
    else
        result += "Unsolved\n";
    return result;
}

int Ida_Star::dfs(Node &node, int g, int threshold)
{
    std::vector<Node> neighbor;
    int f;

    f = g + heuristic(node.state, goal.state, goal.size);
    if (f > threshold)
        return f;
    if (node.compare(goal.state))
    {
        solution = node;
        return -1;
    }
    int min = INT_MAX;
    neighbor = node.gen_next_states();
    for (auto &child : neighbor)
    {
        int temp = dfs(child, g + 1, threshold);
        if (temp == -1)
            return -1;
        if (temp < min)
            min = temp;
    }
    return min;
}
