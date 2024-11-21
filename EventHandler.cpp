// Base class
#include "EventHandler.h"

// C++ dependencies
#include <iostream>

// Project dependencies
#include "BallsManager.h"
#include "BallPreview.h"
#include "DisplayableObject.h"
#include "Sprite.h"
#include "SpritesLoader.h"
#include "Ball.h"

void EventHandler::OnLeftClickPressed(int x, int y)
{
	pressedX = BallsManager::GetInstance()->GetBalls()[0]->GetX();
	pressedY = BallsManager::GetInstance()->GetBalls()[0]->GetY();

	ballPreview = BallPreview::GetInstance();
	Sprite* sprite = SpritesLoader::GetSprites()[5];
	ballPreviewObject = new DisplayableObject(0.0f, 0.0f, sprite);
	ballPreview->SetBallPreviewObject(ballPreviewObject);
}

void EventHandler::OnLeftClickHeld(int x, int y)
{
	float orientation = 180.0f + atan2f(y - pressedY, x - pressedX) * 180.0f / 3.14159f;
	ballPreviewObject->SetOrientation(orientation);
	ballPreview->SetBallPreviewObject(ballPreviewObject);
}

void EventHandler::OnLeftClickReleased(int x, int y)
{
	BallsManager::GetInstance()->HitWhiteBall(pressedX - x,pressedY - y);
	ballPreview->SetBallPreviewObject(nullptr);
}
