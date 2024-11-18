#include "SDLWindow.h"
#include "SDL.h"
#include "Sprite.h"

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
}

bool SDLWindow::IsOpen() const
{
	return (renderer != nullptr);
}

void SDLWindow::Clear()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void SDLWindow::Draw(const std::vector<class Sprite>& spritesList)
{
	for (auto& sprite : spritesList)
	{
		DrawSprite(sprite);
	}
}

void SDLWindow::DrawSprite(const class Sprite& sprite)
{
	SDL_Rect destRect;
	destRect.x = sprite.GetX();
	destRect.y = sprite.GetY();
	destRect.w = sprite.GetWidth();
	destRect.h = sprite.GetHeight();

	// Reconstruct Texture from data
	const void* pixels = sprite.GetData();
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, sprite.GetWidth(), sprite.GetHeight());
	SDL_UpdateTexture(texture, nullptr, pixels, sprite.GetWidth() * sizeof(Uint32));

	// Draw
	SDL_RenderCopy(renderer, texture, nullptr, &destRect);
}

void SDLWindow::Cleanup()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
