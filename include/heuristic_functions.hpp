#ifndef __HEURISTIC_FUNCTIONS_HPP
#define __HEURISTIC_FUNCTIONS_HPP
#include <vector>
#include <cmath>
#include <unordered_map>
#include <utility>
#include "utils.hpp"

static std::unordered_map<int, int> solution_indexs;

int        manhattan_distance(std::vector<int> &state, const std::vector<int> &goal,const int size);
int        linear_conflict(std::vector<int> &state, const std::vector<int> &goal,const int size);
int        dpdb_555(std::vector<int> &state, const std::vector<int> &goal, const int size);

#endif
