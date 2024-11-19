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
    void InternalDraw() override;
    void InternalDrawFPS() override;
    void Cleanup() override;

    static struct SDL_Renderer* GetRenderer() { return renderer; }

private:
    void InternalDrawSprite(const class Sprite& sprite, int x, int y);

public:
    static struct SDL_Renderer* renderer;

private:
    struct SDL_Window* window = nullptr;
    bool isRunning = true;
    TTF_Font* font = nullptr;
};

