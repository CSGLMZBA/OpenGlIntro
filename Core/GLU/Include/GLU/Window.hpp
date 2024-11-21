#pragma once 
#include <GLU/gluset.hpp>

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
        void resize(float aWidth, float aHeight);
        GLFWwindow* getWindow()
        {
            return mWindow;
        }
        GLFWwindow* operator*()
        {
            return mWindow;
        }

    };
    
}