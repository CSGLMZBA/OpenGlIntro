#pragma once
#include <GLU/gluSet.hpp>
#include <GLU/DebugCallback.hpp>
#include <iostream>
namespace glu{
class Context
{
private:
    GLFWwindow* mWindow;
public:
    Context();
    Context(unsigned int MAJOR, unsigned int MINOR, unsigned int PROFILE);
    ~Context();
public:
    void AddWindow(GLFWwindow* aWindow);
    void CreateWindow(int width, int height, const char* title, 
    GLFWmonitor* monitor, GLFWwindow* share);
    void EnableDebugCallbacks()
    {
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(GLDebugMessageCallback,0);
    }
    
};
}