#include "Disjoint_database.hpp"
#include <cmath>

/*
** returns a new node with cells at index 'i1' and index 'i2' swapped
*/

// DFS_Node DFS_Node::cell_swap(int i1, int i2)
// {
//     DFS_Node res = *this;
//     std::swap(res.state[i1], res.state[i2]);
//     if (res.state[i1] > 0 ||  res.state[i2] > 0)
//         res.
//     return res;
// }

// std::vector<std::shared_ptr<DFS_Node>> gen_next_states(std::shared_ptr<DFS_Node> b)
// {
//     int index;
//     int size;
//     std::shared_ptr<DFS_Node> tmp;
//     std::vector<std::shared_ptr<DFS_Node>> new_states;

//     size = std::sqrt(b->state.size());
//     index = find(b->state.begin(), b->state.end(), 0) - b->state.begin();
//     if (index - size >= 0)
//     {
//         tmp = std::make_shared<DFS_Node>(b->create_new(index, index - size));
//         tmp->move = "U";
//         new_states.push_back(tmp);
//     }
//     if (index - 1 >= 0 && ((index + 1) % size == 0 ? size : (index + 1) % size) - 1 > 0)
//     {
//         tmp = std::make_shared<DFS_Node>(b->create_new(index, index - 1));
//         tmp->move = "L";
//         new_states.push_back(tmp);
//     }
//     if (index + 1 < b->state.size() && ((index + 1) % size == 0 ? size : (index + 1) % size) + 1 <= size)
//     {
//         tmp = std::make_shared<DFS_Node>(b->create_new(index, index + 1));
//         tmp->move = "R";
//         new_states.push_back(tmp);
//     }
//     if (index + size < b->state.size())
//     {
//         tmp = std::make_shared<DFS_Node>(b->create_new(index, index + size));
//         tmp->move = "D";
//         new_states.push_back(tmp);
//     }
//     return new_states;
// }
