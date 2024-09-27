#include "pch.hpp"
#include <windows.h>
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
struct Name
{
    double y=0;
    int w = 0;
    unsigned char a= 0;
};
int main()
{
    //define __APPLE__ on macos devices in case its not working
    gluContext MainContext(4,3,GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(800, 600, "INTROOPENGL", NULL, NULL);
    MainContext.AddWindow(window);
    GLenum err = glewInit();
    if (GLEW_OK != err)
        std::cout << glewGetErrorString(err);
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSwapInterval(1);
    //objects and vertex
    float vertices[] = {
    // positions // colors
        0.5f, -0.5f, 0.0f,1.0f, 1.0f, 0.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,1.0f, 0.0f, 1.0f, 0.0f, // bottom left
        0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f // top
    };

    unsigned int indices[] = { // note that we start from 0!
    0, 1, 2
    };
    EBO EBO1(indices,3, GL_STATIC_DRAW);
    VBO VBO1(vertices,21,GL_STATIC_DRAW);
    Shader program1("Assets/Shaders/Vertex.glsl", "Assets/Shaders/Fragment.glsl");
    VAO VAO1(2);
    VAO1.PushAtrrib<float>(4);
    VAO1.PushAtrrib<float>(3);
    VAO1.AddBuffer(VBO1);
    EBO1.Bind();
    VAO1.Unbind();
    program1.Use();

    float x = 0.0f, y = 1.0f;
    program1.SetUniform(0,x,y,0.0f);
    while(!glfwWindowShouldClose(window))
    {
        x = sin(glfwGetTime()/2);
        y = tan(x*4);
    
        processInput(window);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        VAO1.Bind();
        glDrawElements(GL_TRIANGLES, 3,GL_UNSIGNED_INT,0);
        glfwSwapBuffers(window);

        Sleep(1);
        glfwPollEvents();
        program1.SetUniform(0,x/2,y,0.0f);
    }

    return 0;
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if(glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

}
