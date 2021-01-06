#include "heuristic_functions.hpp"

std::map<int, int>   get_indexs(const std::vector<int> &goal)
{
    std::map<int, int> indexs;

    for (int i=0;i<goal.size(); i++)
        indexs.insert(std::make_pair(goal[i], i));
    
    return indexs;
}
int        manhattan_distance(std::vector<int> &state, const std::vector<int> &goal)
{
    int hscore = 0;
    std::pair<int, int> index;
    std::map<int,int>::iterator elem;

    if (solution_indexs.size() != goal.size())
        solution_indexs = get_indexs(goal);
    for (int i=0;i < state.size(); i++)
    {
        elem = solution_indexs.find(state[i]);
        if (elem == solution_indexs.end())
            throwError("Something went wrong");
        index = *elem;
        hscore += abs(i-index.second);
    }
    return hscore;
}

int        linear_conflict(std::vector<int> &state, const std::vector<int> &goal)
{
    int hscore;
    int correct_x;
    int real_x;
    int endx;
    int size;
    int linear_conflict;
    int index;
    std::map<int,int>::iterator elem1;
    std::map<int,int>::iterator elem2;

    hscore = manhattan_distance(state, goal);
    if (solution_indexs.size() != goal.size())
        solution_indexs = get_indexs(goal);
    size = (int)sqrt(state.size());
    linear_conflict = 0;
    for (int i=0; i < state.size(); i++)
    {
        // get the end of the current row
        endx = i + size - ((i+1)%size == 0 ? size : (i+1)%size);
        elem1 = solution_indexs.find(state[i]);
        if (elem1 == solution_indexs.end())
            throwError("Something went wrong");
        correct_x = elem1->second%size == 0 ? size :elem1->second%size;
        real_x = i%size == 0 ? size :i%size;
        if (elem1->second/size == i/size) // check if the current element is in the right row
        {
            for (int j = i+1; j <= endx; j++)
            {
                elem2 = solution_indexs.find(state[j]);
                if (elem2 == solution_indexs.end())
                    throwError("Something went wrong");
                if (elem2->second/size != elem1->second/size) // check if the neighbor element is not in the right row
                    continue;
                if (elem1->second > elem2->second) // check if the current element must be move after the neighbor element if yes, increment the number of conflict 
                    linear_conflict++;
            }
        }
        if (correct_x == real_x)// check if the current element is in the right column
        {
            for (int j = i+size; j < state.size(); j += size)
            {
                elem2 = solution_indexs.find(state[j]);
                if (elem2 == solution_indexs.end())
                    throwError("Something went wrong");
                if (correct_x != (elem2->second%size == 0 ? size :elem2->second%size)) // check if the neighbor element is not in the right column
                    continue;
                if (elem1->second > elem2->second) // check if the current element must be move after the neighbor element if yes, increment the number of conflict 
                    linear_conflict++;
            }
        }
    }
    // std::cout << "Conflict: " << linear_conflict << "\n";
    hscore += 2*linear_conflict;
    return hscore;
}