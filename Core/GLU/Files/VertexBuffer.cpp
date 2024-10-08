#include <GLU/VertexBuffer.hpp>
namespace glu{
VertexBuffer::~VertexBuffer() {}

void VertexBuffer::Bind() 
{
    glBindBuffer(GL_ARRAY_BUFFER,mRendererID);
}

void VertexBuffer::Unbind() 
{
    glBindBuffer(GL_ARRAY_BUFFER,0);
}
}