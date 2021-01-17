#include "Ida_Star.class.hpp"
#include "utils.hpp"


int                                                  Ida_Star::total_selected = 0;
int                                                  Ida_Star::max_states = 0;
int                                                  Ida_Star::in_memory = 0;

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
    while (1337)
    {
        threshold = dfs(root, 0, threshold);
        if (threshold == -1)
            break;
        if (threshold == INT_MAX)
            break;
    }
    if (threshold == -1)
        describe<Ida_Star>(solution);
    else 
        std::cout << "Unsolved\n";
}

int    Ida_Star::dfs(Node&  node, int g, int threshold)
{
    std::vector<Node>                               neighbor;
    int f = g + heuristic(node.state, goal.state, goal.size);
    if (f > threshold)
    {
        Ida_Star::max_states = Ida_Star::max_states > g ? Ida_Star::max_states : g;
        return f;
    }
    if (node.compare(goal.state))
    {
        Ida_Star::max_states = Ida_Star::max_states > g ? Ida_Star::max_states : g;
        solution = node;
        return -1;
    }
    int min = INT_MAX;
    neighbor = node.gen_next_states();
    for (auto &child : neighbor)
    {
        Ida_Star::total_selected++;
        int temp = dfs(child, g+1, threshold);
        if (temp == -1)
            return -1;
        if (temp < min)
            min = temp;
    }
    return min;
}