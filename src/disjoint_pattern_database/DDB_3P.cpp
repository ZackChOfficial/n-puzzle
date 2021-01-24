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

const std::string DDB_3P::DB_DIR = "disjoint_pattern_databases";

bool operator<(const DFS_Node &n1, const DFS_Node &n2)
{
    return n1.state < n2.state;
}

std::set<DFS_Node> DDB_3P::make_entries(DFS_Node source)
{
    std::queue<DFS_Node> q;
    std::set<DFS_Node> visited;
    int maxdepth = -1;
    q.push(source);
    std::cout << "creating entries...\n";
    int depth_count = 0;
    while (!q.empty())
    {
        auto current = q.front();
        if (current.depth > maxdepth)
        {
            maxdepth = current.depth;
            std::cout << "depth_count " << depth_count << ", ";
            std::cout << "jump to depth : " << maxdepth << "\n";
            depth_count = 0;
        }
        q.pop();
        depth_count++;
        visited.insert(current);
        auto children = current.gen_next_states();
        for (auto &child : children)
            if (visited.find(child) == visited.end())
                q.push(child);
    }
    std::cout << "max depth : " << maxdepth << "\n";
    // 555 max depth was 47
    std::cout << visited.size() << " entries created\n";
    return visited;
};

void DDB_3P::save_entries(std::string file_name, const std::set<DFS_Node> &data, const std::vector<int> &target_pattern)
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

void DDB_3P::create()
{
    std::set<DFS_Node> p1_data = make_entries(m_p1);
    // std::set<DFS_Node> p2_data = make_entries(m_p2);
    // std::set<DFS_Node> p3_data = make_entries(m_p3);

    // fs::create_directory(DB_DIR);

    save_entries(P1_DB_FILE_NAME, p1_data, m_p1_ord);
    // save_entries(P2_DB_FILE_NAME, p2_data, m_p2_ord);
    // save_entries(P3_DB_FILE_NAME, p3_data, m_p3_ord);
}

void DDB_3P::load_db(const std::string &file_name, std::unordered_map<unsigned long, int> &pattern_db)
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

void DDB_3P::load()
{
    load_db(DB_DIR + "/" + P1_DB_FILE_NAME, m_p1_db);
    load_db(DB_DIR + "/" + P2_DB_FILE_NAME, m_p2_db);
    load_db(DB_DIR + "/" + P3_DB_FILE_NAME, m_p3_db);
}

/*
** a function to hash a DFS_node in order to efficiently sore it to a binary file
*/

unsigned long DDB_3P::hash_state(const std::vector<int> &state, const std::vector<int> &target_pattern)
{
    unsigned long hash = 0;
    int width = DFS_Node::s_size;
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

unsigned long DDB_3P::hash_dist(int dist)
{
    unsigned long hash = 0;
    hash += dist * (unsigned long)std::pow(10, 2 * 8);
    return hash;
}

int DDB_3P::heuristic(std::vector<int> &state, const std::vector<int> &goal, const int size)
{
    unsigned long h1 = hash_state(state, m_p1_ord);
    unsigned long h2 = hash_state(state, m_p2_ord);
    unsigned long h3 = hash_state(state, m_p3_ord);
    return m_p1_db[h1] + m_p2_db[h2] + m_p3_db[h3];
}
