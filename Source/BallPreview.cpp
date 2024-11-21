// Base class
#include "BallPreview.h"

// Project dependencies
#include "SpritesLoader.h"
#include "Sprite.h"
#include "DisplayableObject.h"

BallPreview* BallPreview::instance = nullptr;

BallPreview* BallPreview::GetInstance()
{
    if (instance == nullptr)
	{
		instance = new BallPreview();
	}
	return instance;
}
