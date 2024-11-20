#pragma once

// Abstract class
#include "Sprite.h"

class RaylibSprite : public Sprite
{
public:
	void LoadImage(const char* filepath, int width, int height) override;
};

