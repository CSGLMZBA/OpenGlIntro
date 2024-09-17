#include "GLU/gluContext.hpp"

gluContext::gluContext()
{
    glfwInit();
}

gluContext::gluContext(unsigned int MAJOR, unsigned int MINOR, unsigned int PROFILE)
{
    glfwInit();
    gluSet(MAJOR,MINOR,PROFILE);
}

gluContext::~gluContext()
{
    glfwTerminate();
}