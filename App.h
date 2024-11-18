#pragma once
#include <vector>

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
	void ChangeState(RunState inState);
	void AddSprite(class Sprite* toAdd);
	std::vector<const class Sprite*> GetSprites() { return displayedSprites; }

private:

	void Run();

private:

	RunState state = WaitForLib;

	class Window* currentWindow = nullptr;	
	std::vector<const class Sprite*> displayedSprites;
	class InputManager* inputManager = nullptr;
	
};