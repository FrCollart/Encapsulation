#pragma once

class Hole
{
public:
	Hole(float x, float y, float radius) : posX(x), posY(y), radius(radius) {}

	float GetX() { return posX; }
	float GetY() { return posY; }
	float GetRadius() { return radius; }


private:
	float posX;
	float posY;
	float radius;
};