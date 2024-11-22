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
const float& TimeClass::deltaTime(TimeManager::GetInstance().deltaTime);
const TimeClass& Time = TimeClass::GetInstance();
