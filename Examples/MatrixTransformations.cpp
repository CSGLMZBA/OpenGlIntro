#include "pch.hpp"
#include <windows.h>

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
    0.5f, 0.5f, 0.0f, 1.0f, 1.0f, // top right
    0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
    -0.5f, 0.5f, 0.0f, 0.0f, 1.0f // top left
    };

    unsigned int indices[] = { // note that we start from 0!
    0, 1, 3,
    1, 2, 3
    };
    glu::ElementBuffer EBO1(indices,6, GL_STATIC_DRAW);
    glu::VertexBuffer VBO1(vertices,sizeof(vertices)/sizeof(float),GL_STATIC_DRAW);
    glu::Shader program1("Assets/Shaders/Mat4Vertex.glsl", "Assets/Shaders/Mat4Fragment.glsl");
    glu::VertexLayout VL1(2);
    VL1.PushAtrrib<float>(3);
    VL1.PushAtrrib<float>(2);
    glu::VertexArray VAO1(VBO1,VL1);
    EBO1.Bind();
    VAO1.Unbind();
    program1.Use();
    glu::Texture2D Tex1("Assets/Textures/container.jpg",1);
    glu::Texture2D Tex2("Assets/Textures/awesomeface.png", 0, GL_RGBA);
    program1.SetUniform("texture1", (int)0);
    program1.SetUniform("texture2", (int)1);
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::rotate(trans, glm::radians((float)glfwGetTime()), glm::vec3(0.0, 0.0, 1.0));
    trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
    program1.SetUniform("transform", trans);
    glm::mat4 trans2 = glm::mat4(1.0f);
    trans2 = glm::translate(trans2, glm::vec3(-0.5f, 0.5f, 0.0f));
    float scale = sin(glfwGetTime())/2 +0.5;
    trans2 = glm::scale(trans2,glm::vec3(scale,scale,1.0f));
    while(!glfwWindowShouldClose(window))
    {
    
        processInput(window);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        VAO1.Bind();
        program1.SetUniform("transform", trans);
        glDrawElements(GL_TRIANGLES, 6,GL_UNSIGNED_INT,0);
        program1.SetUniform("transform", trans2);
        glDrawElements(GL_TRIANGLES, 6,GL_UNSIGNED_INT,0);
        glfwSwapBuffers(window);

        Sleep(1);
        trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
        trans = glm::rotate(trans, glm::radians((float)glfwGetTime()), glm::vec3(0.0, 0.0, 1.0));
        trans2 = glm::mat4(1.0f);
        trans2 = glm::translate(trans2, glm::vec3(-0.5f, 0.5f, 0.0f));
        scale = (sin(glfwGetTime())+2);
        trans2 = glm::scale(trans2,glm::vec3(scale,scale,1.0f));
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