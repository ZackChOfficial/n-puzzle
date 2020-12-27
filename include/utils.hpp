#ifndef __UTILS_H
#define __UTILS_H
#include <string>
#include <iostream>
#include <memory>
#include "Board.class.hpp"

void    throwError(std::string text = "Invalid Input");


template <typename T>
std::vector<std::shared_ptr<T>> gen_next_states(std::shared_ptr<T> b);

#endif
