#pragma once 
#include <GLU/gluSet.hpp>
#include <GLU/VBO.hpp>
#include <GLU/VertexLayout.hpp>
class VAO
{
private:
    /* data */
    unsigned int mRendererID;

public:
    VAO();
    VAO(VBO& aVertexBuffer);
    VAO(VBO& aVertexBuffer,VertexLayout& VL);
    ~VAO();
    void AddBuffer(VBO& aVertexBuffer);
    void AddLayout(VertexLayout& VL);
    void Bind();
    void Unbind();
};

