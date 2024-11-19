#pragma once
#include "Window.h"

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
    void Cleanup() override;

    static class SDL_Renderer* GetRenderer() { return renderer; }

private:
    void InternalDrawSprite(const class Sprite& sprite, int x, int y);

public:
    static class SDL_Renderer* renderer;

private:
    class SDL_Window* window = nullptr;
    bool isRunning = true;
};

