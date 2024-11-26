#pragma once 
#include "gluSet.hpp"

namespace glu
{
    class Window
    {
    private:
        GLFWwindow* mWindow;
        GLFWmonitor *mMonitor;
        GLFWwindow *mShare;
        const char* mTitle;
        unsigned int mWidth, mHeight;
    public:
        Window(unsigned int width, unsigned int height, const char* title = "Window");
        ~Window();
        void Bind();
        GLFWwindow* getWindowPointer()
        {
            return mWindow;
        }

    };
    
}