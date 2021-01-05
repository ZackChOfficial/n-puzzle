#include <queue> // std::queue
#include <memory>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <unordered_map>

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
    // if (n1.state == n2.state)
    //     return n1.dist < n2.dist;
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
    std::cout << "creating entries...\n";
    while (!q.empty())
    {
        auto current = q.front();
        std::cout << "current  :\n";
        current.print();
        std::cout << "\n";
        if (current.depth > maxdepth)
        {
            maxdepth = current.depth;
            std::cout << "jump to depth : " << maxdepth << "\n";
            if (maxdepth == 2)
                break;
        }
        q.pop();
        visited.insert(current);

        auto children = current.gen_next_states();
        std::cout << "children : \n";
        for (auto &child : children)
        {
            if (visited.find(child) == visited.end())
            {
                current.print();
                std::cout << "\n";

                if (child.countable)
                    child.dist = current.dist + 1;
                child.depth = current.depth + 1;
                q.push(child);
            }
        }
    }
    std::cout << "max depth : " << maxdepth << "\n";
    // last max depth was 47
    std::cout << visited.size() << " entries created\n";
    return visited;
};

void DDB_555::save_entries(std::string file_name, const std::set<DFS_Node> &data, const std::vector<int> &target_pattern)
{
    std::ofstream file;
    std::unordered_map<unsigned long, int> clean_data;

    std::cout << "cleaning data...\n";

    for (auto &e : data)
    {
        auto h = hash_state(e.state, target_pattern);
        auto it = clean_data.find(h);
        if (it != clean_data.end())
        {
            if (it->second > e.dist)
                clean_data[h] = e.dist;
        }
        else
        {
            clean_data[h] = e.dist;
        }
    }
    std::cout << clean_data.size() << " elements resulted\n";

    std::cout << "preaparing data...\n";

    file.open(file_name, std::ios::binary | std::ios::trunc);

    if (file.is_open())
    {
        unsigned long *raw_data = new unsigned long[clean_data.size()];
        int i = 0;
        for (auto const &[key, val] : clean_data)
            raw_data[i++] = key + hash_dist(val);

        std::cout << "writing to file " << file_name << "...\n";
        file.write((char *)raw_data, i * sizeof(unsigned long));
        std::cout << "done"
                  << "\n";
    }
    else
    {
        std::cerr << "unable to write to file : " << file_name << "\n";
    }
}

void DDB_555::create()
{
    std::set<DFS_Node> data = make_entries(s_p1);
    save_entries("DPDB_555_1.bin", data, s_p1_ord);
}

void DDB_555::load()
{
}
/*
** a function to hash a DFS_node in order to efficiently sore it to a binary file
*/

unsigned long DDB_555::hash_state(const std::vector<int> &state, const std::vector<int> &target_pattern)
{
    unsigned long hash = 0;
    int width = 4;
    for (int i = 0; i < state.size(); i++)
    {
        auto it = std::find(target_pattern.begin(), target_pattern.end(), state[i]);
        if (it != target_pattern.end())
        {
            int index = it - target_pattern.begin();
            hash += (i / width) * std::pow(10, 2 * index) + (i % width) * std::pow(10, 2 * index + 1);
        }
    }
    return hash;
}

unsigned long DDB_555::hash_dist(int dist)
{
    unsigned long hash = 0;
    hash += dist * std::pow(10, 2 * 8);
    return hash;
}
