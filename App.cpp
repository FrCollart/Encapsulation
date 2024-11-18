#include "App.h"
#include "WindowManager.h"
#include "Window.h"
#include "SDLWindow.h"
#include "RaylibWindow.h"

App::App()
{
}

void App::ChangeState(RunState inState)
{
	switch (state)
	{
	case Close:
		break;
	case SDLRun:
		delete currentWindow;
		break;
	case RaylibRun:
		delete currentWindow;
		break;
	case WaitForLib:
		if (inState == SDLRun)
		{
			currentWindow = new SDLWindow();
		}
		else if (inState == RunState::RaylibRun)
		{
			currentWindow = new RaylibWindow();
		}
		break;
	}
	state = inState;
}

void App::Run()
{
	while (state != Close)
	{
		currentWindow->Draw(displayedSprites);
	}
}

void App::AddSprite(Sprite* toAdd)
{
	displayedSprites.push_back(toAdd);
}