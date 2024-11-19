#pragma once

class DisplayableObject
{
public:

	DisplayableObject(float x, float y, class Sprite* sprite) : x(x), y(y), sprite(sprite) {}

	float GetX() const { return x; }
	float GetY() const { return y; }
	class Sprite* GetSprite() const { return sprite; }

protected:
	float x;
	float y;
	class Sprite* sprite;
};

