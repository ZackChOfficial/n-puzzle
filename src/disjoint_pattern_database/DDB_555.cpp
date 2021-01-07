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

const std::string DDB_555::P1_DB_FILE_NAME = "DPDB_555_1.bin";
const std::string DDB_555::P2_DB_FILE_NAME = "DPDB_555_2.bin";
const std::string DDB_555::P3_DB_FILE_NAME = "DPDB_555_3.bin";

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
    return n1.state < n2.state;
}

std::set<DFS_Node> DDB_555::make_entries(DFS_Node source)
{
    std::queue<DFS_Node> q;
    std::set<DFS_Node> visited;
    int maxdepth = -1;
    source.dist = 0;
    source.depth = 0;
    source.countable = true;
    q.push(source);
    std::cout << "creating entries...\n";
    while (!q.empty())
    {
        auto current = q.front();
        if (current.depth > maxdepth)
        {
            maxdepth = current.depth;
            std::cout << "jump to depth : " << maxdepth << "\n";
            // if (maxdepth == 3)
            //     break;
        }
        q.pop();

        //  std::cout << "\ncurrent  :\n";
        // current.print();
        // if (visited.find(current) != visited.end())
        //     std::cout << "exsists\n";
        visited.insert(current);
        // std::cout << "S = " << visited.size() << "\n";

        auto children = current.gen_next_states();
        // std::cout << "children : \n";
        for (auto &child : children)
        {
            if (visited.find(child) == visited.end())
            {
                if (child.countable)
                    child.dist = current.dist + 1;
                child.depth = current.depth + 1;
                // child.print();
                // std::cout << "\n";
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
        delete[] raw_data;
    }
    else
    {
        std::cerr << "unable to write to file : " << file_name << "\n";
    }
}

void DDB_555::create()
{
    std::set<DFS_Node> p1_data = make_entries(s_p1);
    std::set<DFS_Node> p2_data = make_entries(s_p2);
    std::set<DFS_Node> p3_data = make_entries(s_p3);

    save_entries(P1_DB_FILE_NAME, p1_data, s_p1_ord);
    save_entries(P2_DB_FILE_NAME, p2_data, s_p2_ord);
    save_entries(P3_DB_FILE_NAME, p3_data, s_p3_ord);
}

void DDB_555::load_db(const std::string &file_name, std::unordered_map<unsigned long, int> &pattern_db)
{
    std::ifstream file(file_name, std::ios::binary | std::ios::ate);
    std::streampos size;
    unsigned long *raw_data;

    if (file.is_open())
    {
        std::cout << "loading " << file_name << "\n";
        size = file.tellg();
        raw_data = new unsigned long[size];
        file.seekg(0, std::ios::beg);
        file.read((char *)raw_data, size);
        file.close();
        std::cout << "done !\n";

        for (int i = 0; i < size / sizeof(unsigned long); i++)
        {
            int dist = raw_data[i] / (unsigned long)std::pow(10, 2 * 8);
            unsigned long state_hash = raw_data[i] - dist * (unsigned long)std::pow(10, 2 * 8);

            pattern_db[state_hash] = dist;
        }
        delete[] raw_data;
    }
    else
        std::cout << "Unable to open file " << file_name << "\n";
}

void DDB_555::load()
{
    auto instance = get();
    load_db(P1_DB_FILE_NAME, instance.m_p1_db);
    load_db(P2_DB_FILE_NAME, instance.m_p2_db);
    load_db(P3_DB_FILE_NAME, instance.m_p3_db);

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
            hash += (i / width) * (unsigned long)std::pow(10, 2 * index) + (i % width) * (unsigned long)std::pow(10, 2 * index + 1);
        }
    }
    return hash;
}

unsigned long DDB_555::hash_dist(int dist)
{
    unsigned long hash = 0;
    hash += dist * (unsigned long)std::pow(10, 2 * 8);
    return hash;
}

int DDB_555::heuristic(std::vector<int> &state, const std::vector<int>& goal)
{
    DDB_555 &instance = get();
    unsigned long h1 = hash_state(state, s_p1_ord);
    unsigned long h2 = hash_state(state, s_p2_ord);
    unsigned long h3 = hash_state(state, s_p3_ord);
    return instance.m_p1_db[h1] + instance.m_p2_db[h2] + instance.m_p3_db[h3];
}