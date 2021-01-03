#include <queue> // std::queue
#include <memory>
#include <unordered_set>
#include <algorithm>

#include "Disjoint_database.hpp"
#include "A_Star.class.hpp"
#include "utils.hpp"

auto p1(std::vector<int>{1, 2, -1, -1,
                         12, 13, 14, -1,
                         -1, 0, -1, -1,
                         -1, -1, -1, -1});

auto p2(std::vector<int>{-1, -1, 3, 4,
                         -1, -1, -1, 5,
                         -1, 0, -1, 6,
                         -1, -1, -1, 7});

auto p3(std::vector<int>{-1, -1, -1, -1,
                         -1, -1, -1, -1,
                         11, 0, 15, -1,
                         10, 9, 8, -1});

bool operator<(const std::shared_ptr<DFS_Node> &n1, const std::shared_ptr<DFS_Node> &n2)
{
    if (n1->dist == n2->dist)
        return n1->state < n2->state;
    return n1->dist < n2->dist;
}

unsigned long DDB_555::hash(const DFS_Node &n, const std::vector<int> &target_pattern)
{
    unsigned long hash;

    for (int i = 0; i < n.state.size(); i++)
    {
        if (n.state[i] > 0)
        {
            unsigned long max_10_pow = 1;
            int index = std::find(target_pattern.begin(), target_pattern.end(), n.state[i]) - target_pattern.begin();
        }
    }
}

std::shared_ptr<std::set<DFS_Node>> DDB_555::make_entries(DFS_Node source)
{
    auto q = std::make_shared<std::queue<DFS_Node>>();
    auto visited = std::make_shared<std::set<DFS_Node>>();
    source.dist = 0;
    q->push(source);
    while (!q->empty())
    {
        auto current = q->front();
        q->pop();
        visited->insert(current);
        auto children = current.gen_next_states();
        for (auto &child : children)
        {
            if (visited->find(child) == visited->end())
            {
                if (child.countable)
                    child.dist = current.dist + 1;
                q->push(child);
            }
        }
    }
    return visited;
};

void DDB_555::save_entries(std::string file_name)
{
}

void DDB_555::create()
{
    // make_entries();
}
