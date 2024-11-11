#include "GLU/Context.hpp"
namespace glu{
    void EnableDebugCallbacks()
    {
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(GLDebugMessageCallback,0);
    }
}