#include "utils.hpp"

void    throwError(std::string text)
{
    std::cerr << "ERROR: " << text << std::endl;
    exit(EXIT_FAILURE);
}