#pragma once

// Abstract class
#include "DisplayableObject.h"

class Ball : public DisplayableObject
{
public:

	Ball(float x, float y, float radius, float velocityX, float velocityY, class Sprite* sprite) : DisplayableObject(x, y, sprite), radius(radius), velocityX(velocityX), velocityY(velocityY), accelerationX(0), accelerationY(0) {}
	void SetX(float x) { this->x = x; }
	void SetY(float y) { this->y = y; }
	void SetRadius(float radius) { radius = radius; }
	void SetVelocityX(float x) { velocityX = x; }
	void SetVelocityY(float y) { velocityY = y; }
	void SetAccelerationX(float x) { accelerationX = x; }
	void SetAccelerationY(float y) { accelerationY = y; }
	void AddAccelerationX(float x) { accelerationX += x; }
	void AddAccelerationY(float y) { accelerationY += y; }

	float GetRadius() const { return radius; }
	float GetVelocityX() const { return velocityX; }
	float GetVelocityY() const { return velocityY; }
	float GetAccelerationX() const { return accelerationX; }
	float GetAccelerationY() const { return accelerationY; }

private:

	float velocityX;
	float velocityY;
	float accelerationX;
	float accelerationY;
	float radius;
};

