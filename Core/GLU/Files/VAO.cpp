#include <GLU/VAO.hpp>

VAO::VAO(){
    glGenVertexArrays(1, &mRendererID);
    glBindVertexArray(mRendererID);
}
VAO::VAO(VBO& aVertexBuffer) {
    glGenVertexArrays(1, &mRendererID);
    glBindVertexArray(mRendererID);
    AddBuffer(aVertexBuffer);
}

VAO::VAO(VBO& aVertexBuffer,VertexLayout& VL) {
    glGenVertexArrays(1, &mRendererID);
    glBindVertexArray(mRendererID);
    AddBuffer(aVertexBuffer);
    AddLayout(VL);
}

VAO::~VAO() {
}

void VAO::AddBuffer(VBO& aVertexBuffer) {
    aVertexBuffer.Bind();
}

void VAO::AddLayout(VertexLayout& VL) 
{
    for(int i = 0; i < VL.getAttribs().size(); i++)
    {
        glVertexAttribPointer(i, VL[i].count, VL[i].type, VL[i].normalized, VL.stride(),(void*)VL[i].offset);
        glEnableVertexAttribArray(i);
    }
}
void VAO::Bind() 
{
    glBindVertexArray(mRendererID);
}

void VAO::Unbind() 
{
    glBindVertexArray(0);
}


