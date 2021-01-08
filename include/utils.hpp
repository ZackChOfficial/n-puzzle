#ifndef __UTILS_H
#define __UTILS_H
#include <string>
#include <iostream>
#include <memory>
#include "Board.class.hpp"

void    throwError(std::string text = "Invalid Input");


template <typename T>
std::vector<T> gen_next_states(T b);

#endif
