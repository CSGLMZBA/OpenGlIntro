#pragma once
#include "GLsetup.hpp"
#include "pch.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void processInput(GLFWwindow *window,Camera& cam1);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

void setCallbacks()
{
    glfwSetFramebufferSizeCallback(*window, framebuffer_size_callback);
    glfwSetKeyCallback(*window, key_callback);
    glfwSetCursorPosCallback(*window, mouse_callback);
    glfwSetScrollCallback(*window, scroll_callback);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS)
    {
        switch(key)
        {
            case GLFW_KEY_P: 
                glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
            break;
            default: break;
        }
    }
    else if(action == GLFW_RELEASE)
    {
        switch(key)
        {
            case GLFW_KEY_P: 
                glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
            break;
            case GLFW_KEY_ESCAPE: 
                glfwSetWindowShouldClose(window, true);
            break;
            default: break;
        }
    }
    
}
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    cam1.ChangeFov(-(float)yoffset*10.0f);
}