#include <GLU/VertexLayout.hpp>
VertexLayout::VertexLayout(unsigned int aNumberOfAttributes, 
unsigned int aStride,unsigned int aOffset):
mAttributeCount(aNumberOfAttributes),mStride(aStride), mOffset(aOffset),mSetStride(aStride)
{
}
template <typename T>
void VertexLayout::PushAtrrib(unsigned int count, bool aNormalized)
{

}
template<>
void VertexLayout::PushAtrrib<float>(unsigned int count, bool aNormalized)
{
        mAttributes.push_back({count,GL_FLOAT,mOffset,aNormalized});
        mOffset+=count*sizeof(float);
        if(!mSetStride)
            mStride = mOffset;
}
template<>
void VertexLayout::PushAtrrib<int>(unsigned int count, bool aNormalized)
{
        mAttributes.push_back({count,GL_INT,mOffset,aNormalized});
        mOffset+=count*sizeof(int);
        if(!mSetStride)
            mStride = mOffset;
}
