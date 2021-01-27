#pragma once
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm> // std::find

#include "Board.class.hpp"
class DFS_Node : public Board
{
public:
    static int s_size;

    int dist;
    // its true id 0 swapped with acell actually in pattern (cell != -1)
    int depth;

public:
    DFS_Node() = default;
    DFS_Node(const std::vector<int> &state, bool root = false) : Board(state), dist(0), depth(0)
    {
        if (root)
        {
            zero_position = std::find(state.begin(), state.end(), 0) - state.begin();
            dist = 0;
            depth = 0;
        }
    }
    std::vector<DFS_Node> gen_next_states() const;
    DFS_Node change_state();
    void print();

protected:
    DFS_Node zero_swap(int zero_index, int new_ero_index) const;
    DFS_Node change_state(E_Move move) const;
};

class DDB_3P
{
public:
    static const std::string DB_DIR;

    void create();
    void load();
    int heuristic(std::vector<int> &state);
    unsigned long hash_state(const std::vector<int> &state, const std::vector<int> &target_pattern);
    unsigned long hash_dist(int dist);

public:
    std::unordered_map<unsigned long, int> m_p1_db;
    std::unordered_map<unsigned long, int> m_p2_db;
    std::unordered_map<unsigned long, int> m_p3_db;

    DFS_Node m_p1;
    DFS_Node m_p2;
    DFS_Node m_p3;
    std::vector<int> m_p1_ord;
    std::vector<int> m_p2_ord;
    std::vector<int> m_p3_ord;

    std::string P1_DB_FILE_NAME;
    std::string P2_DB_FILE_NAME;
    std::string P3_DB_FILE_NAME;

    std::set<DFS_Node> make_entries(DFS_Node source);
    void save_entries(std::string file_name, const std::set<DFS_Node> &data, const std::vector<int> &target_pattern);
    void load_db(const std::string &file_name, std::unordered_map<unsigned long, int> &pattern_db);
};

class DDB_663 : public DDB_3P
{
public:
    DDB_663();
};

class DDB_555 : public DDB_3P
{
public:
    DDB_555(bool load = false);
};
