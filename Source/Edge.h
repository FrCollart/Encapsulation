#pragma once
#include "DisplayableObject.h"


class Edge
{
public :
	Edge(float startX, float startY, float endX, float endY, float radius) : radius(radius), startX(startX), startY(startY), endX(endX), endY(endY) {}

	float GetStartX() { return startX; }
	float GetStartY() { return startY; }
	float GetEndX() { return endX; }
	float GetEndY() { return endY; }
	float GetRadius() { return radius; }

private:
	float startX, startY;
	float endX, endY;
	float radius;
};