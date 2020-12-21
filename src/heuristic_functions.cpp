#include "heuristic_functions.hpp"

int        manhattan_distance(std::vector<int> &state, std::vector<int> &goal)
{
    int hscore = 0;
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
    return hscore;
}

int        linear_conflict(std::vector<int> &state, std::vector<int> &goal)
{
    int hscore;

    hscore = manhattan_distance(state, goal);
    return hscore;
}