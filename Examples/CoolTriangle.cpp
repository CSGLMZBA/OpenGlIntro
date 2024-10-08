#include "pch.hpp"
#include <windows.h>
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main()
{
    //define __APPLE__ on macos devices in case its not working
    gluContext MainContext(4,3,GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(800, 600, "INTROOPENGL", NULL, NULL);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    MainContext.AddWindow(window);
    GLenum err = glewInit();
    if (GLEW_OK != err)
        std::cout << glewGetErrorString(err);
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSwapInterval(1);
    glDebugMessageCallback(GLDebugMessageCallback,0);
    //objects and vertex
    float vertices[] = {
    // positions // colors
        0.3f, -0.3f, 0.0f,1.0f, 1.0f, 0.0f, 0.0f, // bottom right
        -0.3f, -0.3f, 0.0f,1.0f, 0.0f, 1.0f, 0.0f, // bottom left
        0.0f, 0.3f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f // top
    };

    unsigned int indices[] = { // note that we start from 0!
    0, 1, 2
    };
    ElementBuffer EBO1(indices,3, GL_STATIC_DRAW);
    VertexBuffer VBO1(vertices,21,GL_STATIC_DRAW);
    Shader program1("Assets/Shaders/Vertex.glsl", "Assets/Shaders/Fragment.glsl");
    VertexLayout VL1(2);
    VL1.PushAtrrib<float>(4);
    VL1.PushAtrrib<float>(3);
    VertexArray VAO1(VBO1,VL1);
    EBO1.Bind();
    VAO1.Unbind();
    program1.Use();

    float x = 0.0f, y = 1.0f;
    program1.SetUniform(0,x,y,0.0f);
    
    //int width, height, nrChannels;  
    //unsigned char *data = stbi_load("Assets/Textures/container.jpg", &width, &height,
    //&nrChannels, 0);
    while(!glfwWindowShouldClose(window))
    {
        x = sin(glfwGetTime()/4);
        y = tan(x*8);
    
        processInput(window);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        VAO1.Bind();
        glDrawElements(GL_TRIANGLES, 3,GL_UNSIGNED_INT,0);
        glfwSwapBuffers(window);

        Sleep(1);
        glfwPollEvents();
        program1.SetUniform(0,x*0.7,y*0.7,0.0f);
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
