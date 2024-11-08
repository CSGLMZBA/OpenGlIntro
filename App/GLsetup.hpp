#pragma once
#include <GL/glew.h>
#include <GLFW\glfw3.h>
void InnitGl()
{
    glfwInit();
    unsigned int MAJOR =4, MINOR = 3, PROFILE = GLFW_OPENGL_CORE_PROFILE;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, MAJOR);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, MINOR);
    glfwWindowHint(GLFW_OPENGL_PROFILE, PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
    #ifdef _DEBUG
        glfwWindowHint (GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
    #endif
}

void CreateWindow(GLFWwindow* window)
{
    unsigned int width = 800, height = 600;
    const char *title = "INTRO OPEN GL";
    GLFWmonitor *monitor = NULL;
    GLFWwindow *share = NULL;
    window =glfwCreateWindow(width, height, title, monitor, share);
    if(window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();}
    else
    {
        glfwMakeContextCurrent(window);
    }
}