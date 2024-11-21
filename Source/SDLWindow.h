#pragma once

// Abstract class
#include "Window.h"

// External Dependencies
#include <SDL_ttf.h>

class SDLWindow : public Window
{

public:
    void Initialize() override;
    void CreateWindow(int width, int height, const char* title) override;
    bool IsOpen() const override;
    void Clear() override;
    void BeginDraw() override;
    void EndDraw() override;
    void InternalDrawBackground() override;
    void InternalDrawSprite(class DisplayableObject* object) override;
    void InternalDrawFPS() override;
    void CleanUp() override;

    static struct SDL_Renderer* GetRenderer() { return renderer; }

public:
    static struct SDL_Renderer* renderer;

private:
    struct SDL_Window* window = nullptr;
    TTF_Font* font = nullptr;
};

