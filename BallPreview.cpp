// Base class
#include "BallPreview.h"

BallPreview* BallPreview::instance = nullptr;

BallPreview* BallPreview::GetInstance()
{
    if (instance == nullptr)
	{
		instance = new BallPreview();
	}
	return instance;
}
