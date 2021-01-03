#pragma once
#include <vector>
#include <utility>
#include <string>
#include <map>

#include "Board.class.hpp"
class DFS_Node : public Board
{
public:
    int dist;
    // its true id 0 swapped with acell actually in pattern (cell != -1)
    bool countable = false;

public:
    std::vector<DFS_Node> gen_next_states() const;

protected:
    DFS_Node cell_swap(int index1, int index2) const;
};

class Disjoint_Pattern_Database
{
    static void create();
    virtual void load() = 0;
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
    void create();
    std::map<int, int> load(std::string file_name);
    unsigned long hash(const DFS_Node &n, const std::vector<int> &target_pattern);

private:
    std::shared_ptr<std::set<DFS_Node>> DDB_555::make_entries(DFS_Node source);
    void save_entries(std::string file_name);
};
