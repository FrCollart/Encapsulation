// Base class
#include "SDLWindow.h"

// C++ dependencies
#include <string>

// Project dependencies
#include "Sprite.h"
#include "BallsManager.h"
#include "Ball.h"
#include "TimeModule.h"
#include "GameConsts.h"

// External dependencies
#include <SDL.h>

SDL_Renderer* SDLWindow::renderer = nullptr;

void SDLWindow::Initialize()
{
	Window::Initialize();

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Log("SDL could not initialize! SDL_Error: %s", SDL_GetError());
		return;
	}

	if (TTF_Init() == -1)
	{
		SDL_Log("SDL_TTF could not initialize! SDL_Error: %s", TTF_GetError());
	}

	font = TTF_OpenFont(FONT_PATH, 24);
	if (!font)
	{
		SDL_Log("Failed to load font: %s", TTF_GetError());
		return;
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
		InternalDrawSprite(*ball->GetSprite(), (int)ball->GetX(), (int)ball->GetY());
	}
}

void SDLWindow::InternalDrawFPS()
{
	std::string fpsText = "FPS: " + std::to_string((int)(timeModule->GetFPS()));

	SDL_Color color = { 0, 0, 0, 255 };
	SDL_Surface* surface = TTF_RenderText_Solid(font, fpsText.c_str(), color);

	if (!surface)
	{
		SDL_Log("Failed to create text surface: %s", TTF_GetError());
		TTF_CloseFont(font);
		return;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	if (!texture)
	{
		SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
		TTF_CloseFont(font);
		return;
	}

	int textWidth = 0, textHeight = 0;
	SDL_QueryTexture(texture, NULL, NULL, &textWidth, &textHeight);

	SDL_Rect dstRect = { WINDOW_WIDTH - textWidth - 10, 10, textWidth, textHeight };

	SDL_RenderCopy(renderer, texture, NULL, &dstRect);

	SDL_DestroyTexture(texture);
}

void SDLWindow::InternalDrawSprite(const Sprite& sprite, int x, int y)
{
	SDL_Rect destRect = SDL_Rect();
	destRect.x = x;
	destRect.y = y;
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

	TTF_Quit();
	SDL_Quit();
}
