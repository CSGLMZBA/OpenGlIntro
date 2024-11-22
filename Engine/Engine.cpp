#include "pch.hpp"
#include "GLsetup.hpp"
#include <windows.h>
#include "Utilities/Time/Time.hpp"
#include "Objects/Camera.hpp"
class InputManager
{
    private: 
    private:
    static glu::Window& currentWindow;
    InputManager(glu::Window& InitialWindow){currentWindow = InitialWindow;};
    public:
    static InputManager SingleInstance;
    static void SetWindow(glu::Window& NewWindow)
    {
        currentWindow = NewWindow;
    }
    static GLFWwindow* GetWindow()
    {
        return currentWindow.getWindowPointer();
    }

};
Camera cam1;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void key_callback2(GLFWwindow* window, int key, int scancode, int action, int mods);
void processInput(GLFWwindow *window,Camera& cam1);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void SetCallbacks()
{
    GLFWwindow* window = InputManager::GetWindow();
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
}
int main()
{
    //define __APPLE__ on macos devices in case its not working
    
    setup::InnitGlfw();
    glu::Window window(800,600);
    setup::InnitGlew();
    InputManager InputManager::SingleInstance(window);
    glViewport(0, 0, 800, 600);
    glEnable(GL_DEPTH_TEST);
    
    setup::EnableDebugCallbacks();
    glfwSwapInterval(1);
    glfwSetInputMode(InputManager::GetWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
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
    glm::mat4 model= glm::mat4(1.0f);
    float angle;
    int i = 0;
    while(!glfwWindowShouldClose(InputManager::GetWindow()))
    {
        TimeManager::UpdateTime();
        glfwGetTime();
        processInput(InputManager::GetWindow(),cam1);
        program1.SetUniform("view", cam1.GetViewMatrix());
        program1.SetUniform("projection", cam1.GetProjectionMatrix());
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
        glfwSwapBuffers(InputManager::GetWindow());
        Sleep(1);
        glfwPollEvents();
        
    }
    glfwTerminate();
    return 0;
}
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
    cam1.SetDimentions(width,height);
    std::cout << width << " x " << height << std::endl;
}
void processInput(GLFWwindow *window,Camera& cam1)
{   
    static float cameraSpeed = 0;
    cameraSpeed = 2.0f * Time.deltaTime; // adjust accordingly
    glm::vec3 MoveVec(0.0f);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    MoveVec.z+=cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    MoveVec.z-=cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    MoveVec.x -= cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    MoveVec.x += cameraSpeed;
    cam1.MovePos(MoveVec);
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
void key_callback2(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS)
    {
        switch(key)
        {
            case GLFW_KEY_Q: 
                glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
            break;
            default: break;
        }
    }
    
}
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    cam1.ChangeFov(-(float)yoffset*10.0f);
}