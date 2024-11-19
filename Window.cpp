// Base Class
#include "Window.h"

// Project dependencies
#include "TimeModule.h"

void Window::Initialize()
{
	timeModule = TimeModule::GetInstance();
}

void Window::Draw()
{
	// Initialize drawing
	BeginDraw();

	// Clear the window
	Clear();

	// Draw all elements
	InternalDraw();

	// Display FPS
	InternalDrawFPS();

	// Finalize drawing
	EndDraw();
}
