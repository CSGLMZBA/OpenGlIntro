#pragma once
#include <GLU/gluSet.hpp>
#include <vector>
namespace glu{
struct Attribute
{
    unsigned int count;
    unsigned int type;
    unsigned int offset;
    bool normalized;
};
class VertexLayout
{
private:
    std::vector<Attribute> mAttributes;
    unsigned int mAttributeCount = 0, mStride = 0, mOffset = 0;
    bool mSetStride = false;
public:
    VertexLayout() = default;
    VertexLayout(unsigned int aNumberOfAttributes, unsigned int aStride = 0,unsigned int aOffset = 0);
    ~VertexLayout() = default;
    unsigned int vertexCount(){return mAttributes.size();}
    unsigned int stride(){return mStride;}
    std::vector<Attribute>& getAttribs(){return mAttributes;}
    Attribute& operator[](unsigned int attributePos){return mAttributes[attributePos];}
public:
    template <typename T>
    void PushAtrrib(unsigned int count, bool aNormalized = 0);
};
}