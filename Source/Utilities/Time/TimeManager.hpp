#pragma once
#include <GLFW\glfw3.h>
class TimeManager
{
    private:
    static float lastFrame; // Time of last frames
    static float currentFrame;
    static TimeManager uniqueInstance;  
    private:
    TimeManager(){}
    static float deltaTime; // Time between current frame and last frame

    TimeManager(const TimeManager&) = delete;
    public:
    static void UpdateTime()
    {
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
    }
    static TimeManager& GetInstance()
    {
        return uniqueInstance;
    }
    public: 
    friend class TimeClass;
    
};
TimeManager TimeManager::uniqueInstance;
float TimeManager::deltaTime(0);
float TimeManager::lastFrame(0);
float TimeManager::currentFrame(0);