#pragma once

class DisplayableObject
{
public:
	DisplayableObject(float x, float y, class Sprite* sprite) : x(x), y(y), sprite(sprite) { orientation = 0.0f; }
	DisplayableObject(float x, float y, float orentation, class Sprite* sprite) : x(x), y(y), orientation(orentation), sprite(sprite) {}

	float GetX() const { return x; }
	float GetY() const { return y; }
	class Sprite* GetSprite() const { return sprite; }

protected:
	float x;
	float y;
	float orientation;
	class Sprite* sprite;
};

