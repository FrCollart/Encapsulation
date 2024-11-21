#pragma once

// C++ dependencies
#include <vector>

class Rectangle
{
public:
	~Rectangle() {}
	Rectangle(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) {}
	bool Intersect(Rectangle* with);
	bool Contains(float x, float y);
	float x, y, w, h;
};

