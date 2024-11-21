#pragma once

// Abstract class
#include "Object.h"

class Edge : public Object
{
public :
	Edge(float startX, float startY, float endX, float endY, float radius) : radius(radius), Object(startX, startY), endX(endX), endY(endY) {}

	float GetStartX() { return GetX(); }
	float GetStartY() { return GetY(); }
	float GetEndX() { return endX; }
	float GetEndY() { return endY; }
	float GetRadius() { return radius; }

private:
	float endX, endY;
	float radius;
};