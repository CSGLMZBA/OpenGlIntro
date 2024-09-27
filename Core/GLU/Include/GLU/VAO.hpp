#pragma once 
#include <GLU/gluSet.hpp>
#include <vector>
#include <GLU/VBO.hpp>
struct Attribute
{
    unsigned int count;
    unsigned int type;
    unsigned int offset;
    bool normalized;
};
class VAO
{
private:
    /* data */
    std::vector<Attribute> mAttributes;
    unsigned int mRendererID,mOffset,mStride;
    bool mCalculateStride;
public:
    VAO(/* args */);
    VAO(unsigned int aNumberOfAttributes,int aStride = -1);
    ~VAO();
    void AddBuffer(VBO& aVertexBuffer);
    void Bind();
    void Unbind();
public:
template <typename T>
void PushAtrrib(unsigned int count, bool aNormalized = 0);

};

