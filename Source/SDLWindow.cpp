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
#include "SpritesLoader.h"
#include "SDLEventHandler.h"
#include "BallPreview.h"

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
	return SDLEventHandler::IsRunning();
}

void SDLWindow::Clear()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White background
	SDL_RenderClear(renderer);
}

void SDLWindow::BeginDraw()
{
	// No need to do anything here
}

void SDLWindow::EndDraw()
{
	SDL_RenderPresent(renderer);
}

void SDLWindow::InternalDrawBackground()
{
	// Draw Background
	SDL_Rect destRect = SDL_Rect();
	destRect.x = 0;
	destRect.y = 0;
	destRect.w = WINDOW_WIDTH;
	destRect.h = WINDOW_HEIGHT;

	// Interprete the sprite data as a SDL texture
	Sprite* backgroundSprite = SpritesLoader::GetSprites()[4];
	const void* data = backgroundSprite->GetData();
	SDL_Texture* texture = (SDL_Texture*)data;

	// Draw
	SDL_RenderCopy(renderer, texture, nullptr, &destRect);
}

void SDLWindow::InternalDrawFPS()
{
	std::string fpsText = "FPS: " + std::to_string((int)timeModule->GetAverageFPS());

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

	int padding = 10; // Padding around the text
	SDL_Rect rect = { WINDOW_WIDTH - textWidth - 100 - padding, 10 - padding, textWidth + 2 * padding, textHeight + 2 * padding };

	// Render the white rectangle
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color
	SDL_RenderFillRect(renderer, &rect);


	SDL_Rect dstRect = { WINDOW_WIDTH - textWidth - 100, 10, textWidth, textHeight };

	SDL_RenderCopy(renderer, texture, NULL, &dstRect);

	SDL_DestroyTexture(texture);
}

void SDLWindow::InternalDrawSprite(DisplayableObject* object)
{
	SDL_Rect destRect = SDL_Rect();
	destRect.x = (int)object->GetX();
	destRect.y = (int)object->GetY();

	Sprite* sprite = object->GetSprite();
	destRect.w = sprite->GetWidth();
	destRect.h = sprite->GetHeight();

	// Interprete the sprite data as a SDL texture
	const void* data = sprite->GetData();
	SDL_Texture* texture = (SDL_Texture*)data;

	SDL_Point center = { destRect.w / 2, destRect.h / 2 };

	// Draw
	SDL_RenderCopyEx(renderer, texture, nullptr, &destRect, object->GetOrientation(), &center, SDL_FLIP_NONE);
}

void SDLWindow::CleanUp()
{
	// If the user closes the window, we need to check if the renderer and window are valid before destroying them
	if (renderer) SDL_DestroyRenderer(renderer);
	if (window) SDL_DestroyWindow(window);

	TTF_Quit();
	SDL_Quit();
}
