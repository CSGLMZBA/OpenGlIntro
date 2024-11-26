#include "VertexArray.hpp"

namespace glu{
VertexArray::VertexArray(){
    glGenVertexArrays(1, &mRendererID);
    glBindVertexArray(mRendererID);
}
VertexArray::VertexArray(VertexBuffer& aVertexBuffer) {
    glGenVertexArrays(1, &mRendererID);
    glBindVertexArray(mRendererID);
    AddBuffer(aVertexBuffer);
}

VertexArray::VertexArray(VertexBuffer& aVertexBuffer,VertexLayout& VL) {
    glGenVertexArrays(1, &mRendererID);
    glBindVertexArray(mRendererID);
    AddBuffer(aVertexBuffer);
    AddLayout(VL);
}

VertexArray::~VertexArray() {
}

void VertexArray::AddBuffer(VertexBuffer& aVertexBuffer) {
    aVertexBuffer.Bind();
}

void VertexArray::AddLayout(VertexLayout& VL) 
{
    for(int i = 0; i < VL.getAttribs().size(); i++)
    {
        glVertexAttribPointer(i, VL[i].count, VL[i].type, VL[i].normalized, VL.stride(),(void*)VL[i].offset);
        glEnableVertexAttribArray(i);
    }
}
void VertexArray::Bind() 
{
    glBindVertexArray(mRendererID);
}

void VertexArray::Unbind() 
{
    glBindVertexArray(0);
}

}