// Base class
#include "EventHandler.h"

// C++ dependencies
#include <iostream>

void EventHandler::OnLeftClickPressed(int x, int y)
{
	std::cout << "Left button clicked at ("
		<< x << ", " << y << ")\n";
}

void EventHandler::OnLeftClickReleased(int x, int y)
{
	std::cout << "Left button released at ("
		<< x << ", " << y << ")\n";
}
