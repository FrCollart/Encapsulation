#pragma once
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
	void InsertDisplayable(class DisplayableObject* toInsert);
	void Subdivide();
	std::vector<class DisplayableObject*> Query(Rectangle* range);

private:
	QuadTree* subdivisions[4] = {}; //NW NE SW SE
	Rectangle* rect;
	std::vector<class DisplayableObject*> objects;
	int rectangleCapacity;
};

