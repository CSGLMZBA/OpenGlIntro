#include "TimeManager.hpp"
TimeManager TimeManager::uniqueInstance;
float TimeManager::deltaTime(0);
float TimeManager::lastFrame(0);
float TimeManager::currentFrame(0);