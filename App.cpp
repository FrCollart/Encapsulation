#include "App.h"
#include "WindowManager.h"


App::App()
{
}

void App::ChangeLib(RunState lib)
{
	windowManager->ChangeLib(lib);
	state = lib;
}

void App::Run()
{
	while (state != Close)
	{
		windowManager->Draw(displayedSprites);
	}
}

void App::AddSprite(Sprite* toAdd)
{
	displayedSprites.push_back(toAdd);
}