#pragma once
#include "InputManager.hpp"
    
class Engine
{
    private:
    glu::Window engineWindow;
    Camera engineCamera;
    InputManager engineInput;
    public:
    Engine();
    ~Engine() {}
    void Init();
    void Run();
    void End();
    void FrameLoop();
    void SetCallbacks();
};