#include "pch.hpp"
#include <windows.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
int main()
{
    //define __APPLE__ on macos devices in case its not working
    glu::Context MainContext(4,3,GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(800, 600, "INTROOPENGL", NULL, NULL);
    MainContext.AddWindow(window);
    GLenum err = glewInit();
    if (GLEW_OK != err)
        std::cout << glewGetErrorString(err);
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    MainContext.EnableDebugCallbacks();
    glfwSwapInterval(1);
    //objects and vertex
    float vertices[] = {
    // positions // colors // texture coords
    0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
    0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
    -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f // top left
    };

    unsigned int indices[] = { // note that we start from 0!
    0, 1, 3,
    1, 2, 3
    };
    glu::ElementBuffer EBO1(indices,6, GL_STATIC_DRAW);
    glu::VertexBuffer VBO1(vertices,sizeof(vertices)/sizeof(float),GL_STATIC_DRAW);
    glu::Shader program1("Assets/Shaders/TexVertex.glsl", "Assets/Shaders/TexFragment.glsl");
    glu::VertexLayout VL1(3);
    VL1.PushAtrrib<float>(3);
    VL1.PushAtrrib<float>(3);
    VL1.PushAtrrib<float>(2);
    glu::VertexArray VAO1(VBO1,VL1);
    EBO1.Bind();
    VAO1.Unbind();
    program1.Use();
    
    int width, height, nrChannels;  
    unsigned char *data = stbi_load("Assets/Textures/container.jpg", &width, &height,
    &nrChannels, 0);
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
    GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindTexture(GL_TEXTURE_2D, texture);
    while(!glfwWindowShouldClose(window))
    {
    
        processInput(window);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        VAO1.Bind();
        glDrawElements(GL_TRIANGLES, 6,GL_UNSIGNED_INT,0);
        glfwSwapBuffers(window);

        Sleep(1);
        glfwPollEvents();
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
