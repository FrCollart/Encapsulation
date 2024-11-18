#pragma once
#include "App.h"
#include <vector>

class WindowManager
{
public:
	WindowManager();
	void ChangeLib(RunState lib);
	void Draw(const std::vector<const class Sprite*>& spritesList);

private:
	class Window* currentWindow;
};