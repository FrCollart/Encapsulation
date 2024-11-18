#include "Window.h"

void Window::Draw()
{
	// Initialize drawing
	BeginDraw();

	// Clear the window
	Clear();

	// Draw all elements
	InternalDraw();

	// Finalize drawing
	EndDraw();
}
