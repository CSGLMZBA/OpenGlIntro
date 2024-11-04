#include "pch.hpp"
#include <windows.h>
class Timeclass
{
    private:
    public:
    float deltaTime = 0.0f; // Time between current frame and last frame
    float lastFrame = 0.0f; // Time of last frame
    Timeclass() = default;
};
Timeclass Time;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
glm::vec3 Translate(float x = 0.0f, float y = 0.0f, float z = 0.0f);
void processInput(GLFWwindow *window,glm::vec3& cameraPos,const glm::vec3& cameraFront, const glm::vec3& cameraUp);
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
    glfwSetKeyCallback(window, key_callback);
    MainContext.EnableDebugCallbacks();
    glfwSwapInterval(1);
    glEnable(GL_DEPTH_TEST);
    //objects and vertex
    float vertices[] = {
    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
    0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
    0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
    -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
    0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
    0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
    0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
    -0.5f, 0.5f, -0.5f, 0.0f, 1.0f
    };
    glm::vec3 cubePositions[] = {
    glm::vec3( 0.0f, 0.0f, 0.0f),
    glm::vec3( 2.0f, 5.0f, -15.0f),
    glm::vec3(-1.5f, -2.2f, -2.5f),
    glm::vec3(-3.8f, -2.0f, -12.3f),
    glm::vec3( 2.4f, -0.4f, -3.5f),
    glm::vec3(-1.7f, 3.0f, -7.5f),
    glm::vec3( 1.3f, -2.0f, -2.5f),
    glm::vec3( 1.5f, 2.0f, -2.5f),
    glm::vec3( 1.5f, 0.2f, -1.5f),
    glm::vec3(-1.3f, 1.0f, -1.5f)
    };
    glu::VertexBuffer VBO1(vertices,sizeof(vertices)/sizeof(float),GL_STATIC_DRAW);
    glu::Shader program1("Assets/Shaders/MvpVertex.glsl", "Assets/Shaders/MvpFragment.glsl");
    glu::VertexLayout VL1(2);
    VL1.PushAtrrib<float>(3);
    VL1.PushAtrrib<float>(2);
    glu::VertexArray VAO1(VBO1,VL1);
    VAO1.Unbind();
    program1.Use();
    glu::Texture2D Tex1("Assets/Textures/container.jpg",1);
    glu::Texture2D Tex2("Assets/Textures/awesomeface.png", 0, GL_RGBA);
    program1.SetUniform("texture1", (int)0);
    program1.SetUniform("texture2", (int)1);
    const float radius = 10.0f;
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, -1.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    program1.SetUniform("view", view);
    glm::mat4 projection = glm::perspective(glm::radians(80.0f), 800.0f / 600.0f, 0.2f,
    100.0f);
    program1.SetUniform("projection", projection);
    glm::mat4 model= glm::mat4(1.0f);
    float angle;
    int i = 0;
    while(!glfwWindowShouldClose(window))
    {
        processInput(window,cameraPos,cameraFront, cameraUp);
        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        program1.SetUniform("view", view);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        VAO1.Bind();
        for(i = 0; i < 10; i++)
        {
            angle = glm::radians((!(i%3))*(glfwGetTime() * 25.0f));
            model = glm::mat4(1.0f);
            model = glm::translate(model,cubePositions[i]);
            model = glm::rotate(model, angle ,glm::vec3(0.5f, 1.0f, 0.0f));
            program1.SetUniform("model",model);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
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
glm::vec3 Translate(float x, float y, float z)
{
    static glm::vec3 CamPos = glm::vec3( 0.0f, 0.0f, 0.0f);
    CamPos += glm::vec3(x,y,z);
    return CamPos;
}
void processInput(GLFWwindow *window,glm::vec3& cameraPos,const glm::vec3& cameraFront, const glm::vec3& cameraUp)
{
    const float cameraSpeed = 0.05f; // adjust accordingly
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
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