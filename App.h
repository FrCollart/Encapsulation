#pragma once
#include <vector>
#include <string>

enum RunState : uint8_t
{
	Close,
	SDLRun,
	RaylibRun,
	WaitForLib,
};

class App
{
public:
	App();
	~App() {}

	void ChangeState(RunState inState);
	void LoadInitialConfiguation();
	void Run();

private:

	void RunWindow();

private:

	RunState state = WaitForLib;

	class Window* currentWindow = nullptr;	
	class BallsManager* ballsManager = nullptr;
	class InputManager* inputManager = nullptr;	
	class TimeModule* timeModule = nullptr;
};