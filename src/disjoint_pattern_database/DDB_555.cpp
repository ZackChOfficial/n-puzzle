#include "Disjoint_database.hpp"

DDB_555::DDB_555() 
{
    P1_DB_FILE_NAME = "DPDB_555_1.bin";
    P2_DB_FILE_NAME = "DPDB_555_2.bin";
    P3_DB_FILE_NAME = "DPDB_555_3.bin";

    m_p1 = DFS_Node({1, 2, -1, -1,
                              12, 13, 14, -1,
                              -1, 0, -1, -1,
                              -1, -1, -1, -1},
                             true);

    m_p1_ord = {1, 2, 12, 13, 14};

    m_p2 = DFS_Node({-1, -1, 3, 4,
                              -1, -1, -1, 5,
                              -1, 0, -1, 6,
                              -1, -1, -1, 7},
                             true);
    m_p2_ord = {3, 4, 5, 6, 7};

    m_p3 = DFS_Node({-1, -1, -1, -1,
                              -1, -1, -1, -1,
                              11, 0, 15, -1,
                              10, 9, 8, -1},
                             true);
    m_p3_ord = {11, 15, 10, 9, 8};
}