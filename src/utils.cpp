#include "A_Star.class.hpp"
#include "utils.hpp"

void throwError(std::string text)
{
    std::cerr << "ERROR: " << text << std::endl;
    exit(EXIT_FAILURE);
}

// template <typename T>
// std::vector<T> gen_next_states(T b)
// {
//     int index;
//     int size;
//     std::vector<T> new_states;

//     size = sqrt(b.state.size());
//     index = find(b.state.begin(), b.state.end(), 0) - b.state.begin();
//     if (index - size >= 0)
//     {
//         T tmp((b.create_new(index, index - size)));
//         tmp.move = "U";
//         new_states.push_back(tmp);
//     }
//     if (index % size - 1 >= 0)
//     {
//         T tmp((b.create_new(index, index - 1)));
//         tmp.move = "L";
//         new_states.push_back(tmp);
//     }
//     if (index % size + 1 < size)
//     {
//         T tmp((b.create_new(index, index + 1)));
//         tmp.move = "R";
//         new_states.push_back(tmp);
//     }
//     if (index + size < b.state.size())
//     {
//         T tmp((b.create_new(index, index + size)));
//         tmp.move = "D";
//         new_states.push_back(tmp);
//     }
//     return new_states;
// }

// template std::vector<Node> gen_next_states(Node b);