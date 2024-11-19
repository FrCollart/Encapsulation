#pragma once
#include <vector>

class Sprite {

public:
    Sprite() : width(1), height(1){}
    Sprite(int inX, int inY) : width(1), height(1){}
    Sprite(int inX, int inY, int inWidth, int inHeight) : width(inWidth), height(inHeight){}
    virtual ~Sprite() = default;

    virtual void LoadImage(const char* filepath) = 0;

    inline const void* GetData() const { return data; }
    inline int GetWidth() const { return width; }
    inline int GetHeight() const { return height; }

protected:
    int width;
    int height;
    void* data = nullptr;
};

