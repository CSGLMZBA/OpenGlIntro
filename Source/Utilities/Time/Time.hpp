#pragma once
#include "TimeManager.hpp"
class TimeClass
{
    private:
    TimeClass(){}
    static TimeClass uniqueInstance;
    public:
    static const float& deltaTime;
    public:
    TimeClass(const TimeClass&) = delete;
    static TimeClass& GetInstance()
    {
        return uniqueInstance;
    }
    
};

