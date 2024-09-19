#pragma once
#include <GLU/gluSet.hpp>
class gluContext
{
private:
    /* data */
public:
    gluContext();
    gluContext(unsigned int MAJOR, unsigned int MINOR, unsigned int PROFILE);
    ~gluContext();
};
