#pragma once
#include "gluSet.hpp"
namespace glu
{
    class Texture
    {
    protected:
        unsigned int mRendererID,mTextureSlot;
        GLenum mTextureType;
    public:
        Texture(unsigned int aTextureSlot, GLenum aTextureType):mTextureSlot(aTextureSlot),mTextureType(aTextureType){}
        virtual ~Texture() {}
        virtual void Bind() {};
        virtual void Unbind() {};
    public:
            virtual void SetParameter() {};
    };
}