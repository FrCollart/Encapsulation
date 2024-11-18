#pragma once
#include <vector>

class Sprite {

public:
    Sprite() : x(0), y(0), width(1), height(1){}
    Sprite(int inX, int inY) : x(inX), y(inY), width(1), height(1){}
    Sprite(int inX, int inY, int inWidth, int inHeight) : x(inX), y(inY), width(inWidth), height(inHeight){}
    virtual ~Sprite() = default;

    virtual void LoadImage(const char* filepath) = 0;

    inline const void* GetData() const { return data; }
    inline int GetX() const { return x; }
    inline int GetY() const { return y; }
    inline int GetWidth() const { return width; }
    inline int GetHeight() const { return height; }

    void SetPosition(int posX, int posY)
    {
        x = posX;
        y = posY;
    }

protected:
    int x;
    int y;
    int width;
    int height;
    void* data = nullptr;
};

