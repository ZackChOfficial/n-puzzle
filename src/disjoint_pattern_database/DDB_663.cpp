#include "Disjoint_database.hpp"

DDB_663::DDB_663()
{
    P1_DB_FILE_NAME = "DPDB_663_1.bin";
    P2_DB_FILE_NAME = "DPDB_663_2.bin";
    P3_DB_FILE_NAME = "DPDB_663_3.bin";

    m_p1 = DFS_Node({1, 2, 3 - 1,
                     12, -1, -1, -1,
                     11, 0, -1, -1,
                     10, -1, -1, -1},
                    true);
    m_p1_ord = {1, 2, 3, 12, 11, 10};

    m_p2 = DFS_Node({-1, -1, -1, 4,
                     -1, -1, -1, 5,
                     -1, 0, -1, 6,
                     -1, 9, 8, 7},
                    true);
    m_p2_ord = {4, 5, 6, 9, 8, 7};

    m_p3 = DFS_Node({-1, -1, -1, -1,
                     -1, 13, 14, -1,
                     -1, 0, 15, -1,
                     -1, -1, -1, -1},
                    true);
    m_p3_ord = {13, 14, 15};
}