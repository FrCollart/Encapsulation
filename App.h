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

	static App* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new App();
		}
		return instance;
	}

	void ChangeState(RunState inState);
	void AddSprite(class Sprite* toAdd);
	std::vector<const class Sprite*> GetSprites() { return displayedSprites; }
	void Run();

private:

	void RunWindow();

private:
	static App* instance;

	RunState state = WaitForLib;

	class Window* currentWindow = nullptr;	
	std::vector<const class Sprite*> displayedSprites;
	class InputManager* inputManager = nullptr;	
};

constexpr int windowWidth = 800;
constexpr int windowHeight = 600;
constexpr const char* windowTitle = "Ligma";