#include "SDLSprite.h"
#include <SDL_image.h>

void SDLSprite::LoadImage(const char* filepath)
{
    SDL_Surface* surface = IMG_Load(filepath);

    SDL_Window* window = SDL_CreateWindow("LoadImageWindow", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1, 1, SDL_WINDOW_HIDDEN);

    if (window == nullptr)
    {
        SDL_Log("Window could not be created! SDL_Error: %s", SDL_GetError());
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("Renderer could not be created! SDL_Error: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    if (!surface) {
        SDL_Log("Failed to load image %s: %s", filepath, IMG_GetError());
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
    }

    // Cast the texture into a void* so it can be stored in the sprite
    data = texture;

    SDL_FreeSurface(surface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
