#pragma once

// Abstract class
#include "InputListener.h"

class SDLInputListener : public InputListener
{
public:
	void OnLeftClickPressed(union SDL_Event);
	void OnLeftClickReleased(union SDL_Event);

private:
	static SDL_Event event;
};

