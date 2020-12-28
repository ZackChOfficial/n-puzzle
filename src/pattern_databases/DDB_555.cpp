#include <queue> // std::queue
#include <memory>

#include "Disjoint_database.hpp"
#include "Board.class.hpp"
#include "A_Star.class.hpp"

auto sb_555_p1 = std::make_shared<Node>(std::vector<int>{1, 2, -1, -1,
                                                         12, 13, 14, -1,
                                                         -1, 0, -1, -1,
                                                         -1, -1, -1, -1});

auto sb_555_p2 = std::make_shared<Node>(std::vector<int>{-1, -1, 3, 4,
                                                         -1, -1, -1, 5,
                                                         -1, 0, -1, 6,
                                                         -1, -1, -1, 7});

auto sb_555_p3 = std::make_shared<Node>(std::vector<int>{-1, -1, -1, -1,
                                                         -1, -1, -1, -1,
                                                         11, 0, 15, -1,
                                                         10, 9, 8, -1});

std::vector<std::pair<int, int>> make_entries()
{
    std::queue<std::shared_ptr<Node>> q;
    
};

void DDB_555::create()
{
}
