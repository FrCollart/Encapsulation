#include "App.h"
#include "Window.h"
#include "SDLWindow.h"
#include "RaylibWindow.h"
#include <iostream>

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
	while (1)
	{
		std::cout << "Enter 1 for SDL, 2 for Raylib, 0 to close\n";
		char input;
		std::cin >> input;

		switch (input)
		{
		case '1':
			ChangeState(RunState::SDLRun);
			break;
		case '2':
			ChangeState(RunState::RaylibRun);
			break;
		case '0':
			return;
		default:
			std::cout << "Invalid input\n";
			continue;
		}

		RunWindow();

		currentWindow->Cleanup();
		ChangeState(WaitForLib);
	}
}

void App::RunWindow()
{
	while (currentWindow->IsOpen())
	{
		currentWindow->Draw();
	}
}

void App::AddSprite(Sprite* toAdd)
{
	displayedSprites.push_back(toAdd);
}