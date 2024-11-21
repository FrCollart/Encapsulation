#pragma once

// Abstract class
#include "Object.h"

class DisplayableObject : public Object
{
public:
	DisplayableObject() : orientation(0.0f), sprite(nullptr) {}
	DisplayableObject(float x, float y, class Sprite* sprite) : Object(x, y), sprite(sprite) { orientation = 0.0f; }
	DisplayableObject(float x, float y, float orentation, class Sprite* sprite) : Object(x, y), orientation(orentation), sprite(sprite) {}

	float GetOrientation() const { return orientation; }
	class Sprite* GetSprite() const { return sprite; }

	void SetOrientation(float orientation) { this->orientation = orientation; }

protected:
	float orientation;
	class Sprite* sprite;
};

