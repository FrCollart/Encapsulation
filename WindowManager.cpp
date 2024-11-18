#include "WindowManager.h"
#include "App.h"
#include "SDLWindow.h"
#include "RaylibWindow.h"

WindowManager::WindowManager()
{
}

void WindowManager::Draw(const std::vector<const class Sprite*>& spritesList)
{
	if (!currentWindow) return;
	currentWindow->Draw(spritesList);
}

void WindowManager::ChangeLib(RunState lib)
{
	delete currentWindow;
	switch (lib)
	{
	case Close:
		break;
	case SDLRun:
		currentWindow = new SDLWindow();
		break;
	case RaylibRun:
		currentWindow = new RaylibWindow();
		break;
	case WaitForLib:
		break;
	}
}
