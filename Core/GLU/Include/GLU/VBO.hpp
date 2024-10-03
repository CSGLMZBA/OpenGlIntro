#pragma once
#include <GLU/gluContext.hpp>
class VBO
{
private:
    unsigned int mRendererID;
public:
    template <typename P>
    VBO(P *aData, unsigned int count, unsigned int usage)
    {
        glGenBuffers(1,&mRendererID);
        glBindBuffer(GL_ARRAY_BUFFER,mRendererID);
        glBufferData(GL_ARRAY_BUFFER,sizeof(P)*count,aData,usage);
    }
    VBO(void *aData, unsigned int size, unsigned int usage)
    {
        glGenBuffers(1,&mRendererID);
        glBindBuffer(GL_ARRAY_BUFFER,mRendererID);
        glBufferData(GL_ARRAY_BUFFER,size,aData,usage);
    }
    ~VBO();
public: 
    void Bind();
    void Unbind();
};
