#include "GLsetup.hpp"
#include "pch.hpp"
#include <windows.h>

class Timeclass
{
    private:
    public:
    float deltaTime = 0.0f; // Time between current frame and last frame
    float lastFrame = 0.0f; // Time of last frame
    float currentFrame = 0.0f;
    void NewFrame()
    {
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
    }
    float DeltaTime(){return deltaTime;}
    Timeclass() = default;
};
Timeclass Time;
class Camera
{
    private:
    glm::vec3 direction;
    float pitch,yaw,fov;
    glm::vec3 cameraPos;
    glm::vec3 cameraFront;
    glm::vec3 cameraUp;
    glm::mat4 view;
    glm::mat4 projection;

    public:
    Camera()
    {
        pitch = 00.0f;
        yaw  = 00.0f;
        fov = 80.0f;
        cameraPos = glm::vec3(-10.0f, 0.0f, 3.0f);
        direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        direction.y = sin(glm::radians(pitch));
        direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        cameraFront = glm::normalize(direction);
        cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        projection = glm::perspective(glm::radians(fov), 800.0f / 600.0f, 0.2f,
        100.0f);
    }
    void MovePos(glm::vec3& Val)
    {
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * Val.x;

        cameraPos += Val.y * cameraUp;

        cameraPos += Val.z * cameraFront;

        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    }
    void ChangeAngle(float& aYaw, float& aPitch)
    {
        yaw = aYaw;
        pitch = aPitch;
        if(pitch > 89.0f)
            pitch = 89.0f;
        if(pitch < -89.0f)
            pitch = -89.0f;

        direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        direction.y = sin(glm::radians(pitch));
        direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        cameraFront = glm::normalize(direction);
        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    }
    void ChangeFov(float changeval)
    {
        fov+= changeval;
        if (fov < 1.0f)
            fov = 1.0f;
        if (fov > 80.0f)
            fov = 80.0f;
        projection = glm::perspective(glm::radians(fov), 800.0f / 600.0f, 0.2f,
        100.0f);
    }
    glm::mat4& GetViewMatrix()
    {
        return view;
    }
    glm::mat4& GetProjectionMatrix()
    {
        return projection;
    }
    
};
Camera cam1;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void processInput(GLFWwindow *window,Camera& cam1);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
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
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
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
    while(!glfwWindowShouldClose(window))
    {
        Time.NewFrame();
        processInput(window,cam1);
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
        glfwSwapBuffers(window);
        Sleep(1);
        glfwPollEvents();
        
    }
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
}
void processInput(GLFWwindow *window,Camera& cam1)
{
    static float cameraSpeed = 0;
    cameraSpeed = 2.0f * Time.DeltaTime(); // adjust accordingly
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
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    cam1.ChangeFov(-(float)yoffset*10.0f);
}