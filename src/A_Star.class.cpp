#include "A_Star.class.hpp"
#include "utils.hpp"

/**
 * A Star Functions
*/

int                                                  A_Star::total_selected = 0;
int                                                  A_Star::max_states = 0;
Mode                                                 A_Star::mode = Mode::E_Normal;

A_Star::A_Star(const std::vector<int> &initial, Board sol, int (*func)(std::vector<int> &state, const std::vector<int> &goal, const int size), Mode running_mode)
{
    Node::size = sqrt(initial.size());
    heuristic = func;
    root = Node(initial);
    root.gscore = 0;
    root.zero_position =   find(initial.begin(), initial.end(), 0) - initial.begin();
    goal = Node(sol.state);
    mode = running_mode;
}

std::string hash_vector(const std::vector<int>& data)
{
    std::string hash = "";
    for (auto x:data)
        hash += std::to_string(x);
    return hash;
}

void A_Star::run()
{
    Node                                            current;
    Node                                            initial(root.state);
    bool                                            solved;
    std::vector<Node>                               neighbor;
    int                                             tentative_gScore;
    std::unordered_map<std::string, Node>::iterator exist;
    int                                             gscore;
    int                                             in_memory;

    in_queue[hash_vector(initial.state)] = initial;
    states.push(root);
    solved = false;
    in_memory = 1;
    while (!in_queue.empty() && !solved)
    {
        A_Star::total_selected++;
        current = states.top();
        gscore = current.gscore;
        if (current.compare(goal.state))
            solved = true;
        else
        {
            visited.insert(current.state);
            in_queue.erase(hash_vector(current.state));
            neighbor = current.gen_next_states();
            states.pop();
            in_memory--;
            for (auto &child : neighbor)
            {
                if (visited.find(child.state) != visited.end())
                    continue;
                child.gscore = gscore + (A_Star::mode == Mode::E_Greedy ? 0 : 1);
                child.hscore = A_Star::mode == Mode::E_Uniform_Cost ? 0 : heuristic(child.state, goal.state, child.size);
                std::cout << "g:  " << child.gscore  << "\n";
                std::cout << "h:  " <<child.hscore  << "\n";
                exist = in_queue.find(hash_vector(child.state));
                if ( exist != in_queue.end())
                {
                    if (child.gscore < exist->second.gscore)
                    {
                        exist->second.gscore = child.gscore;
                        exist->second.parent = child.parent;
                    }
                    continue;
                }
                states.push(child);
                in_memory++;
                A_Star::max_states = in_memory > A_Star::max_states ? in_memory : A_Star::max_states;
                in_queue.insert(std::make_pair(hash_vector(child.state), child));
            }
        }
    }
    if (solved)
        describe<A_Star>(current);
    else
        std::cout << "Empty Stack\n";
}
