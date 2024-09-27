#include <GLU/VAO.hpp>

VAO::VAO():mOffset(0),mStride(0),mCalculateStride(1) {
    glGenVertexArrays(1, &mRendererID);
    glBindVertexArray(mRendererID);
}
VAO::VAO(unsigned int aNumberOfAttributes, int aStride):mOffset(0) {
    mAttributes.reserve(aNumberOfAttributes);
    glGenVertexArrays(1, &mRendererID);
    glBindVertexArray(mRendererID);
    if(aStride!=-1)
    {
        mCalculateStride = false;
        mStride = aStride;
    }
}

VAO::~VAO() {
}


void VAO::AddBuffer(VBO& aVertexBuffer) {
    aVertexBuffer.Bind();
    for(int i = 0; i < mAttributes.size(); i++)
    {
        glVertexAttribPointer(i, mAttributes[i].count, mAttributes[i].type, mAttributes[i].normalized, mStride,(void*)mAttributes[i].offset);
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

template <typename T>
void VAO::PushAtrrib(unsigned int count, bool aNormalized)
{

}
template<>
void VAO::PushAtrrib<float>(unsigned int count, bool aNormalized)
{
        mAttributes.push_back({count,GL_FLOAT,mOffset,aNormalized});
        mOffset+=count*sizeof(float);
        if(mCalculateStride)
            mStride = mOffset;
}