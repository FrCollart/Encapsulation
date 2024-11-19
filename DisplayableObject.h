#pragma once

class DisplayableObject
{
public:

	DisplayableObject(int x, int y, class Sprite* sprite) : x(x), y(y), sprite(sprite) {}
	float GetX() const { return x; }
	float GetY() const { return y; }
	Sprite* GetSprite() const { return sprite; }

protected:
	float x;
	float y;
	class Sprite* sprite;
};

