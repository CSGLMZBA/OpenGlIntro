#include "Callbacks.hpp"

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{    
    
    static float lastX = xpos, lastY = ypos;
    static bool firstMouse = false;
    if (!firstMouse)
    {
        lastX = 400;
        lastY = 300;
    }
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed: y ranges bottom to top
    lastX = xpos;
    lastY = ypos;
    static const float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;
    cam1.ChangeAngle(xoffset,yoffset);
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}