#pragma once

// C++ dependencies
#include <chrono>

class TimeModule
{
public:
	TimeModule() : deltaTime(0.0f), currentFPS(0.0f)
	{
		previousTime = std::chrono::high_resolution_clock::now();
	}

	~TimeModule() {}

	static TimeModule* GetInstance();

	void Update();
	float GetDeltaTime() { return deltaTime; }
	float GetCurrentFPS() { return currentFPS; }
	float GetAverageFPS() { return averageFPS; }

private:
	static TimeModule* instance;
	std::chrono::steady_clock::time_point previousTime;

	float deltaTime = 0.0f;
	float cumulativeTime = 0.0f;

	float currentFPS = 0.0f;
	float averageFPS = 0.0f;

	float cumulativeFPS;
	int frameCount = 0;
};

