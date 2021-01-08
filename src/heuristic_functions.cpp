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
    std::map<int,int>::iterator elem;

    if (solution_indexs.size() != goal.size())
        solution_indexs = get_indexs(goal);
    for (int i=0;i < state.size(); i++)
    {
        elem = solution_indexs.find(state[i]);
        if (elem == solution_indexs.end())
            throwError("Something went wrong");
        hscore += abs(i-elem->second);
    }
    return hscore;
}

int         ft_sqrt(int size)
{
    for (int i = 1; i*i <= size; i++)
    {
        if (i*i == size)return i;
    }
    return 0;
}

int         get_column(int index, int size)
{
    if (index%size == 0)
        return size;
    return index%size;
}

std::map<int,int>::iterator find_element(int key)
{
    std::map<int,int>::iterator elem;

    elem = solution_indexs.find(key);
    if (elem == solution_indexs.end())
        throwError("Something went wrong");
    return elem;
}

int        linear_conflict(std::vector<int> &state, const std::vector<int> &goal)
{
    int hscore;
    int correct_x;
    int endx;
    int                         size;
    std::map<int,int>::iterator elem1;
    std::map<int,int>::iterator elem2;

    hscore = 0;
    if (solution_indexs.size() != goal.size())
        solution_indexs = get_indexs(goal);
    size = ft_sqrt(state.size());
    for (int i = 0; i < state.size(); i++)
    {
        elem1 = find_element(state[i]);
        hscore += abs(i-elem1->second);
        if (state[i] == 0)
            continue;
        endx = i + size - get_column(i+1, size);  // get the end of the current row
        correct_x = get_column(elem1->second, size);
        if (elem1->second/size == i/size) // check if the current element is in the right row
        {
            for (int j = i+1; j <= endx; j++)
            {
                if (state[j] == 0)
                    continue;
                elem2 = find_element(state[j]);
                if (elem2->second/size != elem1->second/size) // continue if the neighbor element is not in the right row
                    continue;
                hscore += (elem1->second > elem2->second) ? 1 : 0; // check if the current element must be moved after the neighbor element if yes, increment the number of conflict 
            }
        }
        if (correct_x == get_column(i, size))// check if the current element is in the right column
        {
            for (int j = i+size; j < state.size(); j += size)
            {
                if (state[j] == 0)
                    continue;
                elem2 = find_element(state[j]);
                if (correct_x != get_column(elem2->second, size)) // continue if the correct neighbor position is not in the current column
                    continue;
                hscore += (elem1->second > elem2->second) ? 1 : 0;// check if the current element must be moved after the neighbor element if yes, increment the number of conflict 
            }
        }
    }
    return hscore;
}