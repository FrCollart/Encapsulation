// Base Class
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
	currentFPS = 1.0f / deltaTime;
	
	// Calcuate average FPS
	cumulativeTime += deltaTime;
	cumulativeFPS += currentFPS;
	frameCount++;

	if (cumulativeTime >= .5f)
	{
		averageFPS = cumulativeFPS / frameCount;
		cumulativeTime = 0.0f;
		cumulativeFPS = 0.0f;
		frameCount = 0;
	}
}
