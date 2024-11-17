#pragma once

class Sprite {

public:
    virtual ~Sprite() = default;

    virtual void loadImage(const char* filepath) = 0;
    virtual const void* getData() const = 0;

    void setPosition(int posX, int posY) {
        x = posX;
        y = posY;
    }

protected:
    int x;
    int y;
};

