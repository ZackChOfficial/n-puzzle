#ifndef __HEURISTIC_FUNCTIONS_HPP
#define __HEURISTIC_FUNCTIONS_HPP
#include <vector>
#include <cmath>
#include <map>
#include <utility>
#include "utils.hpp"

static std::map<int, int> solution_indexs;

int        manhattan_distance(std::vector<int> &state, const std::vector<int> &goal);
int        linear_conflict(std::vector<int> &state, const std::vector<int> &goal);

#endif