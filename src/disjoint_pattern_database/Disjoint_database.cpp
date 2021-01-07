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
    else
        res.countable = true;
    return res;
}

std::vector<DFS_Node> DFS_Node::gen_next_states() const
{
    int zero_index;
    int size;
    DFS_Node tmp;
    std::vector<DFS_Node> new_states;

    size = std::sqrt(this->state.size());
    zero_index = std::find(this->state.begin(), this->state.end(), 0) - this->state.begin();
    if (zero_index - size >= 0)
    {
        tmp = this->cell_swap(zero_index, zero_index - size);
        tmp.move = "U";
        new_states.push_back(tmp);
    }
    if (zero_index % size - 1 >= 0)
    {
        tmp = this->cell_swap(zero_index, zero_index - 1);
        tmp.move = "L";
        new_states.push_back(tmp);
    }
    if (zero_index % size + 1 < size)
    {
        tmp = this->cell_swap(zero_index, zero_index + 1);
        tmp.move = "R";
        new_states.push_back(tmp);
    }
    if (zero_index + size < this->state.size())
    {
        tmp = this->cell_swap(zero_index, zero_index + size);
        tmp.move = "D";
        new_states.push_back(tmp);
    }
    return new_states;
}

void DFS_Node::print()
{
    if (countable)
        printf("C, ");
    else
        printf("NC, ");
    printf("d=%d\n", dist);
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