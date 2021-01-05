#pragma once
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <set>

#include "Board.class.hpp"
class DFS_Node : public Board
{
public:
    int dist;
    // its true id 0 swapped with acell actually in pattern (cell != -1)
    bool countable;
    int depth;

public:
    DFS_Node() = default;
    DFS_Node(const std::vector<int> &state) : Board(state), dist(0), countable(false), depth(0) {}
    std::vector<DFS_Node> gen_next_states() const;
    void print();

protected:
    DFS_Node cell_swap(int index1, int index2) const;
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
    static int heuristic(const std::vector<int> &state);
    static unsigned long hash_state(const std::vector<int> &state, const std::vector<int> &target_pattern);
    static unsigned long hash_dist(int dist);
    std::map<int, int> load(std::string file_name);

public:
    static DFS_Node s_p1;
    static DFS_Node s_p2;
    static DFS_Node s_p3;
    static std::vector<int> s_p1_ord;
    static std::vector<int> s_p2_ord;
    static std::vector<int> s_p3_ord;

    static std::set<DFS_Node> make_entries(DFS_Node source);
    static void save_entries(std::string file_name, const std::set<DFS_Node> &data, const std::vector<int> &target_pattern);
};
