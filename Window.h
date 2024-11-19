#pragma once
#include <vector>

class Window
{
public:
	virtual ~Window() = default;

	virtual void Initialize();
    virtual void CreateWindow(int width, int height, const char* title) = 0;
    virtual bool IsOpen() const = 0;
    virtual void Clear() = 0;
    virtual void BeginDraw() = 0;
    virtual void EndDraw() = 0;
    virtual void Cleanup() = 0;

    void Draw();

protected:
    virtual void InternalDraw() = 0;
    virtual void InternalDrawFPS() = 0;

    class TimeModule* timeModule = nullptr;
};

