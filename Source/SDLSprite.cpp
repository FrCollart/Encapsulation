// Base class
#include "SDLSprite.h"

// C++ dependencies
#include <fstream>
#include <iostream>

// Project dependencies
#include "SDLWindow.h"
#include "GameConsts.h"

// External dependencies
#include <SDL_image.h>

void SDLSprite::LoadImage(const char* filepath, int width, int height)
{
    std::ifstream file(filepath);
    if (!file) {
        std::cout << "Failed to open file: " << filepath << std::endl;
        return;
    }

    SDL_Surface* surface = IMG_Load(filepath);
    if (!surface)
    {
        SDL_Log("Failed to load image %s: %s", filepath, IMG_GetError());
        return;
    }

    SDL_Renderer* renderer = SDLWindow::GetRenderer();
    if (!renderer)
    {
		SDL_Log("Failed to get renderer: %s", SDL_GetError());
        SDL_FreeSurface(surface);
		return;
	}

    // Create a new surface with the desired size
    SDL_Surface* resizedSurface = SDL_CreateRGBSurface(0, width, height, surface->format->BitsPerPixel,
        surface->format->Rmask, surface->format->Gmask,
        surface->format->Bmask, surface->format->Amask);

    if (!resizedSurface) {
        SDL_Log("Failed to create resized surface: %s", SDL_GetError());
        SDL_FreeSurface(surface);
        return;
    }

    // Scale the original surface into the resized surface
    if (SDL_BlitScaled(surface, nullptr, resizedSurface, nullptr) < 0) {
        SDL_Log("Failed to scale surface: %s", SDL_GetError());
        SDL_FreeSurface(surface);
        SDL_FreeSurface(resizedSurface);
        return;
    }

    // Create the texture from the resized surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, resizedSurface);
    if (!texture) {
        SDL_Log("Failed to create texture from resized surface: %s", SDL_GetError());
        SDL_FreeSurface(surface);
        SDL_FreeSurface(resizedSurface);
        return;
    }

    this->width = resizedSurface->w;
    this->height = resizedSurface->h;

    // Cast the texture into a void* so it can be stored in the sprite
    data = texture;

    SDL_FreeSurface(surface);
    SDL_FreeSurface(resizedSurface);
}
