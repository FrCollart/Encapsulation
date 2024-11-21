// Base class
#include "EventHandler.h"

// C++ dependencies
#include <iostream>

// Project dependencies
#include "BallsManager.h"

void EventHandler::OnLeftClickPressed(int x, int y)
{
	pressedX = x;
	pressedY = y;
}

void EventHandler::OnLeftClickReleased(int x, int y)
{
	BallsManager::GetInstance()->HitWhiteBall(pressedX - x,pressedY - y);
}
