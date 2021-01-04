#include <queue> // std::queue
#include <memory>
#include <unordered_set>
#include <algorithm>
#include <cmath>

#include "Disjoint_database.hpp"
#include "A_Star.class.hpp"
#include "utils.hpp"

DFS_Node DDB_555::s_p1 = DFS_Node({1, 2, -1, -1,
                                   12, 13, 14, -1,
                                   -1, 0, -1, -1,
                                   -1, -1, -1, -1});

std::vector<int> DDB_555::s_p1_ord{1, 2, 12, 13, 14};

DFS_Node DDB_555::s_p2 = DFS_Node({-1, -1, 3, 4,
                                   -1, -1, -1, 5,
                                   -1, 0, -1, 6,
                                   -1, -1, -1, 7});
std::vector<int> DDB_555::s_p2_ord{3, 4, 5, 6, 7};

DFS_Node DDB_555::s_p3 = DFS_Node({-1, -1, -1, -1,
                                   -1, -1, -1, -1,
                                   11, 0, 15, -1,
                                   10, 9, 8, -1});
std::vector<int> DDB_555::s_p3_ord{11, 15, 10, 9, 8};

DDB_555 &DDB_555::get()
{
    static DDB_555 instance;
    return instance;
}

bool operator<(const DFS_Node &n1, const DFS_Node &n2)
{
    if (n1.state == n2.state)
        return n1.dist < n2.dist;
    return n1.state < n2.state;
}

std::set<DFS_Node> DDB_555::make_entries(DFS_Node source)
{
    std::queue<DFS_Node> q;
    std::set<DFS_Node> visited;
    int maxdepth = -1;
    source.dist = 0;
    source.depth = 0;
    q.push(source);
    while (!q.empty())
    {
        auto current = q.front();
        if (current.depth > maxdepth)
        {
            maxdepth = current.depth;
            std::cout << "jump to depth : " << maxdepth << "\n";
        }
        q.pop();
        visited.insert(current);

        auto children = current.gen_next_states();
        for (auto &child : children)
        {
            if (visited.find(child) == visited.end())
            {
                if (child.countable)
                    child.dist = current.dist + 1;
                child.depth = current.depth + 1;
                q.push(child);
            }
        }
    }
    std::cout << "max depth : " << maxdepth << "\n";
    // last max depth was 47
    return visited;
};

void DDB_555::save_entries(std::string file_name, const std::set<DFS_Node> &data)
{
    auto cmp = [](const DFS_Node &n1, const DFS_Node &n2) { return n1.state < n2.state; };
    std::set<DFS_Node, decltype(cmp)> clean_data(cmp);

    for (auto &e : data)
    {
        auto it = clean_data.find(e);
        if (it != clean_data.end())
        {
            if (it->dist > e.dist)
            {
                clean_data.erase(it);
                clean_data.insert(e);
            }
        }
        else
        {
            clean_data.insert(e);
        }
    }
    
}

void DDB_555::create()
{
    std::set<DFS_Node> s = make_entries(s_p1);
}

/*
** a function to hash a DFS_node in order to efficiently sore it to a binary file
*/

unsigned long DDB_555::hash(const DFS_Node &n, const std::vector<int> &target_pattern)
{
    unsigned long hash = 0;
    int width = 4;
    for (int i = 0; i < n.state.size(); i++)
    {
        if (n.state[i] > 0)
        {
            int index = std::find(target_pattern.begin(), target_pattern.end(), n.state[i]) - target_pattern.begin();
            hash += (i / width) * std::pow(10, 2 * index) + (i % width) * std::pow(10, 2 * index + 1);
        }
    }
    hash += n.dist * std::pow(10, 2 * 6);
    return hash;
}
