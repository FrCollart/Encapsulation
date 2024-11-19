#include "TimeModule.h"

TimeModule* TimeModule::instance = nullptr;

TimeModule* TimeModule::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new TimeModule();
	}
	return instance;
}

void TimeModule::Update()
{
	auto currentTime = std::chrono::high_resolution_clock::now();
	deltaTime = std::chrono::duration<float>(currentTime - previousTime).count();
	previousTime = currentTime;
	FPS = 1.0f / deltaTime;
}
