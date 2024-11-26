#pragma once
#include "Texture.hpp"
#include <string>
namespace glu
{
    class Texture2D: public Texture
    {
    public:
        Texture2D(const char* aPath, unsigned int aTextureSlot = 0, GLenum aFormat = GL_RGB,  GLenum aTextureType = GL_TEXTURE_2D);
        ~Texture2D();
        void Bind() override ;
        void Unbind() override;
    public:
        template <typename T>
            void SetParameter(GLenum parameterName, T parameterValue);
    };
}