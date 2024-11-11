#pragma once
#include "GLsetup.hpp"
#include "pch.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void processInput(GLFWwindow *window,Camera& cam1);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

void setWindowCallbacks()
{
    glfwSetFramebufferSizeCallback(*window, framebuffer_size_callback);
    glfwSetKeyCallback(*window, key_callback);
    glfwSetCursorPosCallback(*window, mouse_callback);
    glfwSetScrollCallback(*window, scroll_callback);
}
