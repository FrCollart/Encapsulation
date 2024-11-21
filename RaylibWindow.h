#pragma once

// Abstract Class
#include "Window.h"

// External Dependencies
#include <raylib.h>

class RaylibWindow : public Window
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
    void Cleanup() override;

private:
    Font font;
};

