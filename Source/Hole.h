#pragma once

// Abstract class
#include "Object.h"

class Hole : public Object
{
public:
	Hole(float x, float y, float radius) : Object(x, y), radius(radius) {}

	float GetRadius() { return radius; }


private:
	float radius;
};