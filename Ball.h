#pragma once
#include "DisplayableObject.h"
class Ball : public DisplayableObject
{
public:

	Ball(float x, float y, float radius, float speed, float dirX, float dirY, class Sprite* sprite) : DisplayableObject(x, y, sprite), radius(radius), speed(speed), dirX(dirX), dirY(dirY) {}
	void SetDirX(float dirX) { this->dirX = dirX; }
	void SetDirY(float dirY) { this->dirY = dirY; }
	void SetX(float x) { this->x = x; }
	void SetY(float y) { this->y = y; }
	float GetDirX() const { return dirX; }
	float GetDirY() const { return dirY; }
	float GetRadius() const { return radius; }
	float GetSpeed() const { return speed; }
	void SetSpeed(float speed) { this->speed = speed; }
	void SetRadius(float radius) { this->radius = radius; }

private:

	float radius;
	float speed;
	float dirX;
	float dirY;
};

