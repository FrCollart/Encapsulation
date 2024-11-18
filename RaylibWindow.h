#pragma once
#include "Window.h"

class RaylibWindow : public Window
{
public:
    void Initialize() override;
    void CreateWindow(int width, int height, const char* title) override;
    bool IsOpen() const override;
    void Clear() override;
    void Draw(const std::vector<class Sprite>& spritesList) override;
    void Cleanup() override;

private:
    void InternalDrawSprite(const Sprite& sprite);

};

