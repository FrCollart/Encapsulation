#include "App.h"
#include "Window.h"
#include "SDLWindow.h"
#include "RaylibWindow.h"
#include "BallsManager.h"
#include "SpritesLoader.h"
#include <iostream>

App::App()
{
	ballsManager = BallsManager::GetInstance();
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

		if (inState == RaylibRun)
		{
			currentWindow = new RaylibWindow();
		}

		currentWindow->Initialize();
		currentWindow->CreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

		// Need SDL & Raylib Init here
		if (inState == SDLRun)
		{
			SpritesLoader::SDLLoadSprites();
		}

		if (inState == RaylibRun)
		{
			SpritesLoader::RaylibLoadSprites();
		}

		LoadInitialConfiguation();
		break;
	}
	state = inState;
}

void App::LoadInitialConfiguation()
{
	ballsManager->Initialize();
}

void App::Run()
{
	while (1)
	{
		std::cout << "Enter 1 for SDL, 2 for Raylib, 0 to close" << std::endl;
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
			std::cout << "Invalid input, Try again" << std::endl;
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