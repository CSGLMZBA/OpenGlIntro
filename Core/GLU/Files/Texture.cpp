
#include "GLU/Texture.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
namespace glu {

    Texture::Texture(const char* aPath) 
    {
        int width, height, nrChannels;  
        unsigned char *data = stbi_load(aPath, &width, &height,
        &nrChannels, 0);
        glGenTextures(1, &mRendererID);
        glBindTexture(GL_TEXTURE_2D, mRendererID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
        GL_UNSIGNED_BYTE, data);
        stbi_image_free(data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    Texture::~Texture() {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    void Texture::Bind()
    {
        glBindTexture(GL_TEXTURE_2D, mRendererID);
    }
    void Texture::Unbind()
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

}