#pragma once

// C++ dependencies
#include <chrono>

class TimeModule
{
public:
	TimeModule() : deltaTime(0.0f), FPS(0.0f)
	{
		previousTime = std::chrono::high_resolution_clock::now();
	}

	~TimeModule() {}

	static TimeModule* GetInstance();

	void Update();
	float GetDeltaTime() { return deltaTime; }
	float GetFPS() { return FPS; }

private:
	static TimeModule* instance;

	float deltaTime = 0.0f;
	float FPS = 0.0f;

	std::chrono::steady_clock::time_point previousTime;
};

