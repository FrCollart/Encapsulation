#pragma once

// Abstract class
#include "DisplayableObject.h"
#include "GameConsts.h"

class Ball : public DisplayableObject
{
public:

	Ball(float x, float y, float radius, float velocityX, float velocityY, class Sprite* sprite) : DisplayableObject(x, y, sprite), radius(radius), velocityX(velocityX), velocityY(velocityY) {}
	void SetOldX(float x) { this->oldX = x; }
	void SetOldY(float y) { this->oldY = y; }
	void SetRadius(float radius) { this->radius = radius; }
	void SetVelocityX(float x) { velocityX = x; }
	void SetVelocityY(float y) { velocityY = y; }
	void SetAccelerationX(float x) { accelerationX = x; }
	void SetAccelerationY(float y) { accelerationY = y; }
	void SetSimTimeRemaining(float time) { simTimeRemaining = time; }

	float GetOldX() { return oldX; }
	float GetOldY() { return oldY; }
	float GetRadius() const { return radius; }
	float GetVelocityX() const { return velocityX; }
	float GetVelocityY() const { return velocityY; }
	float GetAccelerationX() const { return accelerationX; }
	float GetAccelerationY() const { return accelerationY; }
	float GetSimTimeRemainging() const { return simTimeRemaining; }

private:

	float oldX = 0;
	float oldY = 0;
	float velocityX;
	float velocityY;
	float accelerationX = 0;
	float accelerationY = 0;
	float radius;
	float simTimeRemaining = 0;
};

