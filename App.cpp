#include "App.h"
#include "Window.h"
#include "SDLWindow.h"
#include "RaylibWindow.h"

App* App::instance = nullptr;

App::App()
{
}

void App::ChangeState(RunState inState)
{
	switch (state)
	{
	case Close:
		return;
	case SDLRun:
		delete currentWindow;
		break;
	case RaylibRun:
		delete currentWindow;
		break;
	case WaitForLib:
		if (inState == Close) return;

		if (inState == SDLRun)
		{
			currentWindow = new SDLWindow();
		}
		else if (inState == RaylibRun)
		{
			currentWindow = new RaylibWindow();
		}
		currentWindow->Initialize();
		currentWindow->CreateWindow(windowWidth, windowHeight, windowTitle);
		break;
	}
	state = inState;
}

void App::Run()
{
	// TEST ONLY
	ChangeState(RunState::SDLRun);

	while (currentWindow->IsOpen())
	{
		currentWindow->Draw();
	}
}

void App::AddSprite(Sprite* toAdd)
{
	displayedSprites.push_back(toAdd);
}