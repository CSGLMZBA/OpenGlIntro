#include "Window.hpp"
namespace glu
{
    Window::Window(unsigned int width, unsigned int height, const char* title)
        :mTitle(title),mWidth(width),mHeight(height)
    {
        mMonitor = NULL;
        mShare = NULL;
        mWindow = glfwCreateWindow(width, height, title, mMonitor, mShare);
        if(mWindow == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
        }
    }
    Window::~Window()
    {
        if(mWindow!=NULL)
            glfwDestroyWindow(mWindow);
    }
    void Window::Bind()
    {
        if(mWindow!=NULL){
            glfwMakeContextCurrent(mWindow);
        }
        else
            std::cout << "invalid glfw window" << std::endl;
    }
    
}