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

Node::Node()
{
    parent = nullptr;
    gscore = 999999;
    hscore = 999999;
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
    if (parent)
    {
        path = parent->get_path();
        if (path != "")
            return path + " " + move;
    }
    return move;
}

std::vector<Node> Node::gen_next_states() const
{
    int index;
    int size;
    std::vector<Node> new_states;

    size = sqrt(state.size());
    index = find(state.begin(), state.end(), 0) - state.begin();
    if (index - size >= 0)
    {
        Node tmp((create_new(index, index - size)));
        tmp.move = "U";
        new_states.push_back(tmp);
    }
    if (index % size - 1 >= 0)
    {
        Node tmp((create_new(index, index - 1)));
        tmp.move = "L";
        new_states.push_back(tmp);
    }
    if (index % size + 1 < size)
    {
        Node tmp((create_new(index, index + 1)));
        tmp.move = "R";
        new_states.push_back(tmp);
    }
    if (index + size < state.size())
    {
        Node tmp((create_new(index, index + size)));
        tmp.move = "D";
        new_states.push_back(tmp);
    }
    return new_states;
}
/**
 * A Star Functions
*/
A_Star::A_Star(const std::vector<int> &initial, Board sol, int (*func)(std::vector<int> &state, const std::vector<int> &goal))
{
    bool solved;
    heuristic = func;
    root = Node(initial);
    root.gscore = 0;
    root.move = "";
    goal = Node(sol.state);
}

void A_Star::run()
{
    Node current;
    Node initial(root.state);
    bool solved;
    std::vector<Node> neighbor;
    int tentative_gScore;
    std::string path;

    initial.hscore = heuristic(initial.state, goal.state);
    in_queue[initial.state] = initial;
    states.push(Node(root.state));
    std::cout << root.state.size() << "\n";
    solved = false;
    path = "";
    int i = 0;
    while (!in_queue.empty() && !solved)
    {
        i++;
        current = states.top();
        // std::cout << "Current " << current->state.size() << "\n";
        // log("HELLO 1\n");
        if (current.compare(goal.state))
        {
            solved = true;
        }
        else
        {
            visited.insert(current.state);
            in_queue.erase(current.state);
            neighbor = current.gen_next_states();
            for (auto &child : neighbor)
            {
                if (visited.find(child.state) != visited.end())
                {
                    continue;
                }
                child.gscore = current.gscore + 1;
                child.hscore = heuristic(child.state, goal.state);
                child.parent = std::make_shared<Node>(current);
                if (in_queue.find(child.state) != in_queue.end())
                {
                    Node *exist = &in_queue[child.state];
                    if (child.gscore < exist->gscore)
                    {
                        exist->gscore = child.gscore;
                        exist->parent =  child.parent;
                    }
                    continue;
                }
                states.push(child);
                in_queue[child.state] = child;
            }
            states.pop();
        }
    }
    if (solved)
    {
        std::cout << "Solved\nNumber of Iteration: " << i << std::endl;
        std::cout << "Path:  " << current.get_path() << std::endl;
        // current->print();
    }
    else
        std::cout << "Empty Stack\n";
}
