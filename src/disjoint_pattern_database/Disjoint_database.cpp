#include "Disjoint_database.hpp"
#include <cmath>

int DFS_Node::s_size = 4;

/*
** returns a new node with cells at index 'i1' and index 'i2' swapped
*/

DFS_Node DFS_Node::zero_swap(int zero_index, int new_zero_index) const
{
    DFS_Node newElem = DFS_Node(this->state);

    std::swap(newElem.state[zero_index], newElem.state[new_zero_index]);
    if (newElem.state[zero_index] >= 0 && state[new_zero_index] >= 0)
        newElem.dist = dist + 1;
    else
        newElem.dist = dist;
    newElem.zero_position = new_zero_index;

    newElem.depth = depth + 1;
    return newElem;
}

DFS_Node DFS_Node::change_state(E_Move move) const
{
    DFS_Node res;
    switch (move)
    {
    case UP:
        res = zero_swap(zero_position, zero_position - s_size);
        break;
    case RIGHT:
        res = zero_swap(zero_position, zero_position + 1);
        break;
    case DOWN:
        res = zero_swap(zero_position, zero_position + s_size);
        break;
    case LEFT:
        res = zero_swap(zero_position, zero_position - 1);
        break;
    }
    return res;
}

std::vector<DFS_Node> DFS_Node::gen_next_states() const
{
    std::vector<DFS_Node> new_states;

    if (zero_position - s_size >= 0)
        new_states.push_back(change_state(UP));
    if (zero_position % s_size - 1 >= 0)
        new_states.push_back(change_state(LEFT));
    if (zero_position % s_size + 1 < s_size)
        new_states.push_back(change_state(RIGHT));
    if (zero_position + s_size < state.size())
        new_states.push_back(change_state(DOWN));
    return new_states;
}

void DFS_Node::print()
{
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
