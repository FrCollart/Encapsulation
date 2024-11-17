#pragma once

class Window
{
public:
	virtual ~Window() = default;

	virtual void initialize() = 0;
    virtual void createWindow(int width, int height, const char* title) = 0;
    virtual bool isOpen() const = 0;
    virtual void clear() = 0;
    virtual void drawSprite() = 0;
    virtual void cleanup() = 0;
};

