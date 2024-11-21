// Base Class
#include "Window.h"

// Project dependencies
#include "TimeModule.h"
#include "BallsManager.h"
#include "BallPreview.h"
#include "Ball.h"

void Window::Initialize()
{
	timeModule = TimeModule::GetInstance();
}

void Window::Draw()
{
	BeginDraw();
	Clear();
	InternalDrawBackground();

	// Iterate through all known objects and draw them

	// Draw ball preview
	DisplayableObject* ballPreview = BallPreview::GetInstance()->GetBallPreviewObject();
	if (ballPreview != nullptr)
	{
		InternalDrawSprite(ballPreview);
	}

	// Draw all balls
	for (auto& ball : BallsManager::GetInstance()->GetBalls())
	{
		InternalDrawSprite(ball);
	}

	InternalDrawFPS(); // Future improvaments : REF this to InternalDrawUI
	EndDraw();
}
