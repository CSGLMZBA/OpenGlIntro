    #include "InputManager.hpp"
    InputManager::InputManager(GLFWwindow* inpw, Camera* cam):inputWindow(inpw),eventCamera(cam)
    {

    }
    void InputManager::Start()
    {
        glfwSetInputMode(inputWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        glfwSetFramebufferSizeCallback(inputWindow, framebuffer_size_callback);
        glfwSetKeyCallback(inputWindow, key_callback);
        glfwSetCursorPosCallback(inputWindow, mouse_callback);
        glfwSetScrollCallback(inputWindow, scroll_callback);
    }


    void mouse_callback(GLFWwindow* window, double xpos, double ypos)
    {    
        
        InputManager *inputManager =
        reinterpret_cast<InputManager*>(glfwGetWindowUserPointer(window));
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
        inputManager->eventCamera->ChangeAngle(xoffset,yoffset);
    }


    void InputManager::processInput()
    {   
        static float cameraSpeed = 0;
        cameraSpeed = 2.0f * TimeClass::deltaTime; // adjust accordingly
        glm::vec3 MoveVec(0.0f);
        if (glfwGetKey(inputWindow, GLFW_KEY_W) == GLFW_PRESS)
        MoveVec.z+=cameraSpeed;
        if (glfwGetKey(inputWindow, GLFW_KEY_S) == GLFW_PRESS)
        MoveVec.z-=cameraSpeed;
        if (glfwGetKey(inputWindow, GLFW_KEY_A) == GLFW_PRESS)
        MoveVec.x -= cameraSpeed;
        if (glfwGetKey(inputWindow, GLFW_KEY_D) == GLFW_PRESS)
        MoveVec.x += cameraSpeed;
        eventCamera->MovePos(MoveVec);
    }
    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        static InputManager *inputManager =
        reinterpret_cast<InputManager*>(glfwGetWindowUserPointer(window));
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
        static InputManager *inputManager = 
        reinterpret_cast<InputManager*>(glfwGetWindowUserPointer(window));
        inputManager->eventCamera->ChangeFov(-(float)yoffset*10.0f);
    }
    void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        static InputManager *inputManager =
        reinterpret_cast<InputManager*>(glfwGetWindowUserPointer(window));
        glViewport(0, 0, width, height);
        inputManager->eventCamera->SetDimentions(width,height);
        std::cout << width << " x " << height << std::endl;
    }
