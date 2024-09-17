#include <GL/glew.h>
#include <GLFW\glfw3.h>
#include "gluSet.hpp"
class gluContext
{
private:
    /* data */
public:
    gluContext();
    gluContext(unsigned int MAJOR, unsigned int MINOR, unsigned int PROFILE);
    ~gluContext();
};
