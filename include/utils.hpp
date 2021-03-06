#ifndef __UTILS_H
#define __UTILS_H
#include <string>
#include <iostream>
#include <memory>

#include "Node.class.hpp"
#include "options.hpp"

void throwError(std::string text = "Invalid Input");
template <typename T>
std::string describe(Node &, Options opts);

#endif
