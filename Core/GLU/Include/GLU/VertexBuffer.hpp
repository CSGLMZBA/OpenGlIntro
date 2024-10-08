#pragma once
#include <GLU/gluSet.hpp>
namespace glu{
class VertexBuffer
{
private:
    unsigned int mRendererID;
public:
    template <typename P>
    VertexBuffer(P *aData, unsigned int count, unsigned int usage)
    {
        glGenBuffers(1,&mRendererID);
        glBindBuffer(GL_ARRAY_BUFFER,mRendererID);
        glBufferData(GL_ARRAY_BUFFER,sizeof(P)*count,aData,usage);
    }
    VertexBuffer(void *aData, unsigned int size, unsigned int usage)
    {
        glGenBuffers(1,&mRendererID);
        glBindBuffer(GL_ARRAY_BUFFER,mRendererID);
        glBufferData(GL_ARRAY_BUFFER,size,aData,usage);
    }
    ~VertexBuffer();
public: 
    void Bind();
    void Unbind();
};
}