#pragma once 
#include <GLU/gluSet.hpp>
#include <GLU/VertexBuffer.hpp>
#include <GLU/VertexLayout.hpp>
namespace glu{
class VertexArray
{
private:
    /* data */
    unsigned int mRendererID;

public:
    VertexArray();
    VertexArray(VertexBuffer& aVertexBuffer);
    VertexArray(VertexBuffer& aVertexBuffer,VertexLayout& VL);
    ~VertexArray();
    void AddBuffer(VertexBuffer& aVertexBuffer);
    void AddLayout(VertexLayout& VL);
    void Bind();
    void Unbind();
};
}