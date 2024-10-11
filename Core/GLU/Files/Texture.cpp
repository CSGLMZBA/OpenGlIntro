
#include "GLU/Texture.hpp"
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
namespace glu {

    Texture::Texture(const char* aPath, unsigned int aTextureSlot, GLenum aFormat, GLenum aTextureType):mTextureSlot(aTextureSlot),mTextureType(aTextureType)
    {
        int width, height, nrChannels;  
        stbi_set_flip_vertically_on_load(true);
        unsigned char *data = stbi_load(aPath, &width, &height, &nrChannels, 0);
        if (!data)
        {   
            std::cout << aPath << " could not be read" << std::endl;
            return;
        }
        glGenTextures(1, &mRendererID);
        glActiveTexture(GL_TEXTURE0 + mTextureSlot);
        glBindTexture(aTextureType, mRendererID);
        glTexImage2D(aTextureType, 0, GL_RGB, width, height, 0, aFormat,
        GL_UNSIGNED_BYTE, data);
        stbi_image_free(data);
        glTexParameteri(aTextureType, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(aTextureType, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(aTextureType, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(aTextureType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glGenerateMipmap(aTextureType);
    }

    Texture::~Texture() {
        
    }
    void Texture::Bind()
    {
        glActiveTexture(GL_TEXTURE0 + mTextureSlot);
        glBindTexture(mTextureType, mRendererID);
    }
    void Texture::Unbind()
    {
        glActiveTexture(GL_TEXTURE0 + mTextureSlot);
        glBindTexture(mTextureType, 0);
    }
    template <typename T>
        void Texture::SetParameter(GLenum parameterName, T parameterValue)
        {

        }
    template <>
        void Texture::SetParameter<float>(GLenum parameterName, GLfloat parameterValue)
        {

            glTextureParameteri(mRendererID, parameterName, parameterValue);
        }
    template <>
        void Texture::SetParameter<int>(GLenum parameterName, GLint parameterValue)
        {

            glTextureParameteri(mRendererID, parameterName, parameterValue);
        }
}