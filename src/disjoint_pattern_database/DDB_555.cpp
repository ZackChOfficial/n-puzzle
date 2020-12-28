#include <queue> // std::queue
#include <memory>
#include <unordered_set>

#include "Disjoint_database.hpp"
#include "Board.class.hpp"
#include "A_Star.class.hpp"
#include "utils.hpp"

auto sb_555_p1 = std::make_shared<DFS_Node>(std::vector<int>{1, 2, -1, -1,
                                                             12, 13, 14, -1,
                                                             -1, 0, -1, -1,
                                                             -1, -1, -1, -1});

auto sb_555_p2 = std::make_shared<DFS_Node>(std::vector<int>{-1, -1, 3, 4,
                                                             -1, -1, -1, 5,
                                                             -1, 0, -1, 6,
                                                             -1, -1, -1, 7});

auto sb_555_p3 = std::make_shared<DFS_Node>(std::vector<int>{-1, -1, -1, -1,
                                                             -1, -1, -1, -1,
                                                             11, 0, 15, -1,
                                                             10, 9, 8, -1});

std::vector<std::pair<int, int>> DDB_555::make_entries(std::shared_ptr<DFS_Node> source)
{
    std::vector<std::pair<std::shared_ptr<DFS_Node>, int> > result;
    std::queue<std::shared_ptr<DFS_Node> > q;
    std::unordered_set<std::vector<int> > visited;
    source->dist = 0;
    q.push(source);
    while (!q.empty())
    {
        auto current = q.front();
        q.pop();
        visited.insert(current->state);
        auto children = gen_next_states(current);
        for (auto &child : children)
        {
        }
    }
};

void DDB_555::create()
{
}
