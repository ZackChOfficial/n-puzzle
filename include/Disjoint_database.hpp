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
    DFS_Node(const std::vector<int> &state, bool root = false) : Board(state), dist(0), depth(0) {
        if (root){
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

class Disjoint_Pattern_Database
{
};

class DDB_663 : public Disjoint_Pattern_Database
{
    static void create();

private:
    std::vector<std::pair<int, int>> make_entries();
    void save_entries(std::string file_name);

public:
    std::map<int, int> load(std::string file_name);
};

class DDB_555
{
public:
    static DDB_555 &get();
    static void create();
    static void load();
    static int heuristic(std::vector<int> &state, const std::vector<int> &goal, const int size);
    static unsigned long hash_state(const std::vector<int> &state, const std::vector<int> &target_pattern);
    static unsigned long hash_dist(int dist);
    std::map<int, int> load(std::string file_name);

public:
    std::unordered_map<unsigned long, int> m_p1_db;
    std::unordered_map<unsigned long, int> m_p2_db;
    std::unordered_map<unsigned long, int> m_p3_db;

    static DFS_Node s_p1;
    static DFS_Node s_p2;
    static DFS_Node s_p3;
    static std::vector<int> s_p1_ord;
    static std::vector<int> s_p2_ord;
    static std::vector<int> s_p3_ord;


    static const std::string DB_DIR;
    static const std::string P1_DB_FILE_NAME;
    static const std::string P2_DB_FILE_NAME;
    static const std::string P3_DB_FILE_NAME;

    static std::set<DFS_Node> make_entries(DFS_Node source);
    static void save_entries(std::string file_name, const std::set<DFS_Node> &data, const std::vector<int> &target_pattern);
    static void load_db(const std::string &file_name, std::unordered_map<unsigned long, int> &pattern_db);
};
