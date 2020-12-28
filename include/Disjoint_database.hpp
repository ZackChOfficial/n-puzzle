#pragma once
#include <vector>
#include <utility>
#include <string>
#include <map>

class DisjointDatabase
{
    static void create();

    virtual void load() = 0;
};

class DDB_663
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

    static void create();

private:
    std::vector<std::pair<int, int>> make_entries();
    void save_entries(std::string file_name);

public:
    std::map<int, int> load(std::string file_name);
};
