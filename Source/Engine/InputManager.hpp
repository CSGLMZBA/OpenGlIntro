#pragma once
#include "../Precompile.hpp"
#include "../MyLibs.hpp"

#include "GLsetup.hpp"
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
class InputManager
{
    public:
    GLFWwindow* inputWindow;
    Camera* eventCamera;
    public:
    InputManager(GLFWwindow* inpw, Camera* cam);
    InputManager(){}
    void operator=(const InputManager &old){inputWindow=old.inputWindow; eventCamera=old.eventCamera;}
    void processInput();
    void Start();
};
