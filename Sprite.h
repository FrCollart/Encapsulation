#pragma once
#include <vector>

class Sprite {

public:
    Sprite() : x(0), y(0), width(1), height(1){}
    Sprite(int inX, int inY) : x(inX), y(inY), width(1), height(1){}
    Sprite(int inX, int inY, int inWidth, int inHeight) : x(inX), y(inY), width(inWidth), height(inHeight){}
    virtual ~Sprite() = default;

    virtual void LoadImage(const char* filepath) = 0;
    virtual const void* GetData() const = 0;

    int GetX() const { return x; }
    int GetY() const { return y; }
    int GetWidth() const { return width; }
    int GetHeight() const { return height; }

    void SetPosition(int posX, int posY) {
        x = posX;
        y = posY;
    }

protected:
    int x;
    int y;
    int width;
    int height;
};

