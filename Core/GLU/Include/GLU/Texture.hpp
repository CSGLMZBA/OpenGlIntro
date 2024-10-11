#pragma once
#include <GLU/gluSet.hpp>
#include <string>
namespace glu
{
    class Texture
    {
    private:
        unsigned int mRendererID,mTextureSlot;
        GLenum mTextureType;
    public:
        Texture(const char* aPath, unsigned int aTextureSlot = 0, GLenum aFormat = GL_RGB,  GLenum aTextureType = GL_TEXTURE_2D);
        ~Texture();
        void Bind();
        void Unbind();
    public:
        template <typename T>
            void SetParameter(GLenum parameterName, T parameterValue);
    };
}