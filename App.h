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
	void ChangeLib(RunState lib);
	void AddSprite(class Sprite* toAdd);
	std::vector<const class Sprite*> GetSprites() { return displayedSprites; }

private:

	void Run();

	RunState state = WaitForLib;
	std::vector<const class Sprite*> displayedSprites;

	class InputManager* inputManager = nullptr;
	class WindowManager* windowManager = nullptr;
};