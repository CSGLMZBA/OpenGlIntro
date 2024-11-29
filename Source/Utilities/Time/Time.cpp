#include "Time.hpp"
TimeClass TimeClass::uniqueInstance;
const float& TimeClass::deltaTime(TimeManager::GetInstance().deltaTime);
const TimeClass& Time = TimeClass::GetInstance();