#pragma once

class DisplayableObject
{
public:
	DisplayableObject(float x, float y, class Sprite* sprite) : x(x), y(y), sprite(sprite) { orientation = 0.0f; }
	DisplayableObject(float x, float y, float orentation, class Sprite* sprite) : x(x), y(y), orientation(orentation), sprite(sprite) {}

	float GetX() const { return x; }
	float GetY() const { return y; }
	float GetOrientation() const { return orientation; }
	class Sprite* GetSprite() const { return sprite; }

	void SetX(float x) { this->x = x; }
	void SetY(float y) { this->y = y; }
	void SetOrientation(float orientation) { this->orientation = orientation; }

protected:
	float x;
	float y;
	float orientation;
	class Sprite* sprite;
};

