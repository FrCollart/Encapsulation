#include "QuadTree.h"
#include "DisplayableObject.h"
#include "Sprite.h"

void QuadTree::InsertDisplayable(DisplayableObject* toInsert)
{
	//if displayable pos is outside rect
	float spriteWidth = toInsert->GetSprite()->GetHeight();
	float spriteHeight = toInsert->GetSprite()->GetWidth();

	if (!rect->Contains(toInsert->GetX(), toInsert->GetY()))
	{
		return;
	}

	if (objects.size() < rectangleCapacity) objects.push_back(toInsert);
	else if (!subdivisions[0])
	{
		Subdivide();
	}
	for (int i = 0; i < 4; i++)
	{
		subdivisions[i]->InsertDisplayable(toInsert);
	}
}

void QuadTree::Subdivide()
{
	Rectangle* nwRect = new Rectangle(rect->x - rect->x / 2, rect->y - rect->h / 2, rect->w / 2, rect->h / 2);
	subdivisions[0] = new QuadTree(nwRect, rectangleCapacity);

	Rectangle* neRect = new Rectangle(rect->x + rect->x / 2, rect->y - rect->h / 2, rect->w / 2, rect->h / 2);
	subdivisions[1] = new QuadTree(neRect, rectangleCapacity);

	Rectangle* swRect = new Rectangle(rect->x - rect->x / 2, rect->y + rect->h / 2, rect->w / 2, rect->h / 2);
	subdivisions[2] = new QuadTree(swRect, rectangleCapacity);

	Rectangle* seRect = new Rectangle(rect->x + rect->x / 2, rect->y + rect->h / 2, rect->w / 2, rect->h / 2);
	subdivisions[3] = new QuadTree(seRect, rectangleCapacity);

}

std::vector<DisplayableObject*> QuadTree::Query(Rectangle* range)
{
	std::vector<DisplayableObject*> found;
	if (!rect->Intersect(range)) return found;

	if (subdivisions[0])
	{
		for (int i = 0; i < 4; i++)
		{
			std::vector<DisplayableObject*> toAdd = subdivisions[i]->Query(range);
			found.insert(found.end(), toAdd.begin(), toAdd.end());
		}
	}
	else
	{
		for (int i = 0; i < objects.size(); i++)
		{
			if (range->Contains(objects[i]->GetX(), objects[i]->GetY()))
			{
				found.push_back(objects[i]);
			}
		}
	}
	
	return found;
}

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
