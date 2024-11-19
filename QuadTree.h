#pragma once

// C++ dependencies
#include <vector>

class Rectangle
{
public:
	Rectangle(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) {}
	bool Intersect(Rectangle* with);
	bool Contains(float x, float y);
	float x, y, w, h;
};

class QuadTree
{
public:
	QuadTree(Rectangle* rect, int capacity) : rect(rect), rectangleCapacity(capacity) {}
	void AddBall(class Ball* toInsert);
	void Subdivide();
	std::vector<class Ball*> Query(Rectangle* range);

private:
	QuadTree* subdivisions[4] = {}; //NW NE SW SE
	Rectangle* rect;
	std::vector<class Ball*> objects;
	int rectangleCapacity;
};

