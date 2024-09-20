#pragma once
#include <GLU/gluContext.hpp>
class EBO
{
private:
    unsigned int mRendererID;
    unsigned int* mData;
public:
    EBO(unsigned int aData[], unsigned int count, GLenum usage);
    ~EBO();
public:
    void Bind();
    void Unbind();
};


