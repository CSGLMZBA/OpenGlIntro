#pragma once
#include <GLU/gluSet.hpp>
namespace glu{
class ElementBuffer
{
private:
    unsigned int mRendererID;
    unsigned int* mData;
public:
    ElementBuffer(unsigned int aData[], unsigned int count, unsigned int usage);
    ~ElementBuffer();
public:
    void Bind();
    void Unbind();
};
}

