#include "SDLSprite.h"
#include "SDLWindow.h"
#include <SDL_image.h>

void SDLSprite::LoadImage(const char* filepath)
{
    SDL_Surface* surface = IMG_Load(filepath);
    if (!surface) {
        SDL_Log("Failed to load image %s: %s", filepath, IMG_GetError());
        return;
    }

    SDL_Renderer* renderer = SDLWindow::GetRenderer();
    if (!renderer) {
		SDL_Log("Failed to get renderer: %s", SDL_GetError());
		return;
	}

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
    }

    width = surface->w;
    height = surface->h;

    // Cast the texture into a void* so it can be stored in the sprite
    data = texture;

    SDL_FreeSurface(surface);
}
