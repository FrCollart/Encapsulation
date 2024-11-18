#pragma once
#include "Sprite.h"

class SDLSprite : public Sprite
{
public:
	void LoadImage(const char* filepath) override;
};

