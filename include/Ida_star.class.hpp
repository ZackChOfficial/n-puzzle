#ifndef __IDA_STAR_CLASS_HPP
#define __IDA_STAR_CLASS_HPP

#include "Node.class.hpp"

class IDA_STAR
{
private:
    void    search(const Node& node, int g, int threshold);

public:
    void    run();
};

#endif