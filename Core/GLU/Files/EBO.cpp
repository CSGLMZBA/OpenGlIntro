#include <GLU/EBO.hpp>

EBO::EBO(unsigned int aData[], unsigned int count, unsigned int usage):mData(aData)
{
    glGenBuffers(1, &mRendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(unsigned int)*count,aData,usage);
}

EBO::~EBO() {}
void EBO::Bind() 
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID);
}
void EBO::Unbind() 
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}