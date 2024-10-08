#pragma once
#include <GLU/gluSet.hpp>
#include <string>
namespace glu
{
    class Texture
    {
    private:
        unsigned int mRendererID;

    public:
        Texture(const char* aPath);
        ~Texture();
        void Bind();
        void Unbind();
    };
}