#include "heuristic_functions.hpp"

std::map<int, int>   get_indexs(std::vector<int> &goal)
{
    std::map<int, int> indexs;

    for (int i=0;i<goal.size(); i++)
        indexs.insert(std::make_pair(goal[i], i));
    
    return indexs;
}
int        manhattan_distance(std::vector<int> &state, std::vector<int> &goal)
{
    int hscore = 0;
    std::pair<int, int> index;

    if (solution_indexs.size() != goal.size())
        solution_indexs = get_indexs(goal);
    for (int i=0;i < state.size(); i++)
    {
        if (solution_indexs.find(state[i]) == solution_indexs.end())
            throwError("Something went wrong");
        index = *solution_indexs.find(state[i]);
        hscore += abs(i-index.second);
    }
    return hscore;
}

int        linear_conflict(std::vector<int> &state, std::vector<int> &goal)
{
    int hscore;

    hscore = manhattan_distance(state, goal);
    return hscore;
}