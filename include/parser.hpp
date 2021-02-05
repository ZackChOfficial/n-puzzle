#ifndef __PARSER_H
#define __PARSER_H

#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <tuple>

#include "utils.hpp"
#include "options.hpp"

std::vector<int> parse();
Options cmd_args_parse(int argc, char **argv);

#endif
