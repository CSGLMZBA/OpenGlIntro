#include "ElementBuffer.hpp"
namespace glu{
ElementBuffer::ElementBuffer(unsigned int aData[], unsigned int count, unsigned int usage):mData(aData)
{
    glGenBuffers(1, &mRendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(unsigned int)*count,aData,usage);
}

ElementBuffer::~ElementBuffer() 
{
}
void ElementBuffer::Bind() 
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID);
}   
void ElementBuffer::Unbind() 
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
}