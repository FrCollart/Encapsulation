#pragma once
#include "Sprite.h"

class RaylibSprite : public Sprite
{
public:
	void LoadImage(const char* filepath) override;
};

