#pragma once
#include <GLU/gluContext.hpp>
class VBO
{
private:
    unsigned int mRendererID;
    const void* mData;

public:
    template <typename P>
    VBO(P *aData, unsigned int count, GLenum usage) :mData(aData)
    {
        glGenBuffers(1,&mRendererID);
        glBindBuffer(GL_ARRAY_BUFFER,mRendererID);
        glBufferData(GL_ARRAY_BUFFER,sizeof(P)*count,aData,usage);
    }
    ~VBO();
public: 
    void Bind();
    void Unbind();
};
