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
	BeginDraw();
	Clear();
	InternalDrawBackground();
	InternalDraw();             // Draw all elements
	InternalDrawFPS();
	EndDraw();
}
