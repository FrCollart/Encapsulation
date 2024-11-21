#pragma once
class Object
{
public:
	Object() : x(0), y(0) {}
	Object(float x, float y) : x(x), y(y) {}

	float GetX() const { return x; }
	float GetY() const { return y; }

	void SetX(float x) { this->x = x; }
	void SetY(float y) { this->y = y; }

private:
	float x;
	float y;
};

