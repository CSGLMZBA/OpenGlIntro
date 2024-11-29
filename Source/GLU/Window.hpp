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
        Window(){mWindow = NULL;mMonitor=NULL;mShare=NULL;mTitle="NULLWINDOW";};
        void operator[](Window& reassigned)
        {
            mWindow = reassigned.mWindow;
            mMonitor = reassigned.mMonitor;
            mShare = reassigned.mShare;
            mTitle = reassigned.mTitle;
            mWidth = reassigned.mWidth;
            mHeight = reassigned.mHeight;
            reassigned.mWindow = nullptr;
            reassigned.mMonitor = nullptr;
            reassigned.mShare = nullptr;
            reassigned.mTitle = nullptr;
            reassigned.mWidth = 0;
            reassigned.mHeight = 0;
            reassigned.~Window();
        }
        ~Window();
        void Bind();
        GLFWwindow* getWindowPointer()
        {
            return mWindow;
        }
        bool shouldClose()
        {
            return glfwWindowShouldClose(mWindow);
        }
        void abandonMemory();

    };
    
}