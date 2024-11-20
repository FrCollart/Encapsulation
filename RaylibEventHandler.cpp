// Base class
#include "RaylibEventHandler.h"

// External dependencies
#include "raylib.h"

void RaylibEventHandler::HandleEvents()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Vector2 mousePosition = GetMousePosition();
		OnLeftClickPressed(mousePosition.x, mousePosition.y);
	}

	if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
	{
		Vector2 mousePosition = GetMousePosition();
		OnLeftClickReleased(mousePosition.x, mousePosition.y);
	}
}
