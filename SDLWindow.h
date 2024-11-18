#pragma once
#include "Window.h"

class SDLWindow : public Window
{

public:
    virtual void Initialize() override;
    virtual void CreateWindow(int width, int height, const char* title) override;
    virtual bool IsOpen() const override;
    virtual void Clear() override;
    virtual void Draw(const std::vector<class Sprite>& spritesList) override;
    virtual void Cleanup() override;

private:
    void InternalDrawSprite(const class Sprite& sprite);

private:
    class SDL_Window* window = nullptr;
    class SDL_Renderer* renderer = nullptr;
};

