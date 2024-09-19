#include <GLU/VBO.hpp>

VBO::~VBO() {}

void VBO::Bind() 
{
    glBindBuffer(GL_ARRAY_BUFFER,mRendererID);
}

void VBO::Unbind() 
{
    glBindBuffer(GL_ARRAY_BUFFER,0);
}
