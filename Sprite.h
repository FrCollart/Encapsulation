#pragma once

class Sprite {

public:
    virtual ~Sprite() = default;

    virtual void LoadImage(const char* filepath) = 0;
    virtual const void* GetData() const = 0;

    void SetPosition(int posX, int posY) {
        x = posX;
        y = posY;
    }

protected:
    int x;
    int y;
};

