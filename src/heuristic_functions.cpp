#include "heuristic_functions.hpp"
#include "Disjoint_database.hpp"

std::unordered_map<int, int>   get_indexs(const std::vector<int> &goal)
{
    std::unordered_map<int, int> indexs;

    for (int i=0;i<(int)goal.size(); i++)
        indexs.insert(std::make_pair(goal[i], i));

    return indexs;
}

int        manhattan_distance(std::vector<int> &state, const std::vector<int> &goal, const int size)
{
    int hscore = 0;
    std::unordered_map<int,int>::iterator elem;

    if (solution_indexs.size() != goal.size())
        solution_indexs = get_indexs(goal);
    for (int i=0;i < (int)state.size(); i++)
    {
        elem = solution_indexs.find(state[i]);
        if (elem == solution_indexs.end())
            throwError("Something went wrong");
        hscore += abs(i-elem->second);
    }
    return (hscore);
}

int         get_column(int index, int size)
{
    if (index%size == 0)
        return size;
    return index%size;
}

std::unordered_map<int,int>::iterator find_element(int key)
{
    std::unordered_map<int,int>::iterator elem;

    elem = solution_indexs.find(key);
    if (elem == solution_indexs.end())
        throwError("Something went wrong");
    return elem;
}

int        row_conflict(std::vector<int> &state, std::unordered_map<int,int>::iterator& elem,
                            const int& index, const int& end, const int& size)
{
    std::unordered_map<int,int>::iterator   elem2;
    int                                     hscore;

    hscore = 0;
    for (int j = index+1; j <= end; j++)
    {
        if (state[j] == 0)
            continue;
        elem2 = find_element(state[j]);
        if (elem2->second/size != elem->second/size) // continue if the neighbor element is not in the right row
            continue;
        hscore += (elem->second > elem2->second) ? 1 : 0; // check if the current element must be moved after the neighbor element if yes, increment the number of conflict
    }
    return hscore;
}

int        column_conflict(std::vector<int> &state, std::unordered_map<int,int>::iterator& elem, const int& index, const int& size)
{
    std::unordered_map<int,int>::iterator   elem2;
    int                                     hscore;

    hscore = 0;
    for (size_t j = index + size; j < state.size(); j += size)
    {
        if (state[j] == 0)
            continue;
        elem2 = find_element(state[j]);
        if (get_column(elem->second, size) != get_column(elem2->second, size)) // continue if the correct neighbor position is not in the current column
            continue;
        hscore += (elem->second > elem2->second) ? 1 : 0;// check if the current element must be moved after the neighbor element if yes, increment the number of conflict
    }
    return hscore;
}

int        linear_conflict(std::vector<int> &state, const std::vector<int> &goal,const int size)
{
    int                                     hscore;
    int                                     endx;
    std::unordered_map<int,int>::iterator   elem;

    hscore = 0;
    if (solution_indexs.size() != goal.size())
        solution_indexs = get_indexs(goal);
    for (int i = 0; i < (int)state.size(); i++)
    {
        elem = find_element(state[i]);
        hscore += abs(i-elem->second);
        if (state[i] == 0)
            continue;
        endx = i + size - get_column(i+1, size);  // get the end of the current row
        if (elem->second/size == i/size) // check if the current element is in the right row
           hscore += row_conflict(state, elem, i, endx, size);
        if (get_column(elem->second, size) == get_column(i, size))// check if the current element is in the right column
            hscore += column_conflict(state, elem, i, size);
    }
    return hscore;
}

int        dpdb_555(std::vector<int> &state, const std::vector<int> &goal, const int size){
    static DDB_555 db(true);
    return db.heuristic(state);
}
