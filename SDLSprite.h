#pragma once
#include "Sprite.h"

class SDLSprite : public Sprite
{
public:
	virtual void LoadImage(const char* filepath) override;
	virtual const void* GetData() const override;
};

