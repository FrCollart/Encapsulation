#include "SDLWindow.h"
#include "SDL.h"
#include "Sprite.h"
#include "BallsManager.h"
#include "Ball.h"


void SDLWindow::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Log("SDL could not initialize! SDL_Error: %s", SDL_GetError());
	}
}

void SDLWindow::CreateWindow(int width, int height, const char* title)
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	
	if (window == nullptr)
	{
		SDL_Log("Window could not be created! SDL_Error: %s", SDL_GetError());
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer) {
		SDL_Log("Renderer could not be created! SDL_Error: %s", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	SDL_SetWindowTitle(window, title);
}

bool SDLWindow::IsOpen() const
{
	return isRunning;
}

void SDLWindow::Clear()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White background
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void SDLWindow::BeginDraw()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			isRunning = false;
		}
	}
}

void SDLWindow::EndDraw()
{
	SDL_RenderPresent(renderer);
}

void SDLWindow::InternalDraw()
{
	for (const auto& ball : BallsManager::GetInstance()->GetBalls())
	{
		InternalDrawSprite(*ball->GetSprite());
	}
}

void SDLWindow::InternalDrawSprite(const Sprite& sprite)
{
	SDL_Rect destRect;
	destRect.x = sprite.GetX();
	destRect.y = sprite.GetY();
	destRect.w = sprite.GetWidth();
	destRect.h = sprite.GetHeight();

	// Interprete the sprite data as a SDL texture
	const void* data = sprite.GetData();
	SDL_Texture* texture = (SDL_Texture*)data;

	// Draw
	SDL_RenderCopy(renderer, texture, nullptr, &destRect);
	
}

void SDLWindow::Cleanup()
{
	// If the user closes the window, we need to check if the renderer and window are valid before destroying them
	if (renderer) SDL_DestroyRenderer(renderer);
	if (window) SDL_DestroyWindow(window);
	SDL_Quit();
}
