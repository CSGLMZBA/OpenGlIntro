#include "GLU/Context.hpp"
namespace glu{
Context::Context()
{
    glfwInit();
    #ifdef _DEBUG
        glfwWindowHint (GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
    #endif
}

Context::Context(unsigned int MAJOR, unsigned int MINOR, unsigned int PROFILE)
{
    glfwInit();
    gluSet(MAJOR,MINOR,PROFILE);
    #ifdef _DEBUG
        glfwWindowHint (GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
    #endif
}

void Context::AddWindow(GLFWwindow *aWindow) 
{
    
    if(aWindow == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }else
    {
        mWindow = aWindow;
        glfwMakeContextCurrent(mWindow);
    }
}
void Context::CreateWindow(int width, int height, const char *title,
                                GLFWmonitor *monitor, GLFWwindow *share) 
{
    mWindow =glfwCreateWindow(width, height, title, monitor, share);
    if(mWindow == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();}
    else
        glfwMakeContextCurrent(mWindow);
}
Context::~Context()
{
    glfwTerminate();
}
}