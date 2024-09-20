#pragma once
#include <GLU/gluSet.hpp>
#include <iostream>
class gluContext
{
private:
    GLFWwindow* mWindow;
public:
    gluContext();
    gluContext(unsigned int MAJOR, unsigned int MINOR, unsigned int PROFILE);
    ~gluContext();
public:
    void AddWindow(GLFWwindow* aWindow);
    void CreateWindow(int width, int height, const char* title, 
    GLFWmonitor* monitor, GLFWwindow* share);

    
};
