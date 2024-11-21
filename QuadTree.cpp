// Base class
#include "QuadTree.h"

bool Rectangle::Intersect(Rectangle* with)
{
	return !(with->x - with->w > x + w ||
		with->x + with->w < x - w ||
		with->y + with->h < y + h ||
		with->y + with->h < y - h);
}

bool Rectangle::Contains(float x, float y)
{
	return (x >= this->x - this->w &&
		x <= this->x + this->w &&
		y >= this->y - this->h &&
		y <= this->y + this->h);
}
