#include "Disjoint_database.hpp"
#include <cmath>
#include <algorithm> // std::find

/*
** returns a new node with cells at index 'i1' and index 'i2' swapped
*/

DFS_Node DFS_Node::cell_swap(int i1, int i2) const
{
    DFS_Node res = *this;
    std::swap(res.state[i1], res.state[i2]);
    if (res.state[i1] < 0 || res.state[i2] < 0)
        res.countable = false;
    return res;
}

std::vector<DFS_Node> DFS_Node::gen_next_states() const
{
    int index;
    int size;
    DFS_Node tmp;
    std::vector<DFS_Node> new_states;

    size = std::sqrt(this->state.size());
    index = std::find(this->state.begin(), this->state.end(), 0) - this->state.begin();
    if (index - size >= 0)
    {
        tmp = this->cell_swap(index, index - size);
        tmp.move = "U";
        new_states.push_back(tmp);
    }
    if (index - 1 >= 0 && ((index + 1) % size == 0 ? size : (index + 1) % size) - 1 > 0)
    {
        tmp = this->cell_swap(index, index - 1);
        tmp.move = "L";
        new_states.push_back(tmp);
    }
    if (index + 1 < this->state.size() && ((index + 1) % size == 0 ? size : (index + 1) % size) + 1 <= size)
    {
        tmp = this->cell_swap(index, index + 1);
        tmp.move = "R";
        new_states.push_back(tmp);
    }
    if (index + size < this->state.size())
    {
        tmp = this->cell_swap(index, index + size);
        tmp.move = "D";
        new_states.push_back(tmp);
    }
    return new_states;
}

void DFS_Node::print()
{
    for (size_t i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (state[4 * i + j] >= 0)
                printf("%3d", state[4 * i + j]);
            else
                printf("  *");
        }

        printf("\n");
    }
}