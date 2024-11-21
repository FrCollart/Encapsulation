// Base class
#include "SDLEventHandler.h"

// External dependencies
#include <SDL.h>

bool SDLEventHandler::isRunning = true;

void SDLEventHandler::HandleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;

        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT) {
                OnLeftClickPressed(event.button.x, event.button.y);
                isLeftClickHeld = true;
            }
            break;

        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT) {
				OnLeftClickReleased(event.button.x, event.button.y);
                isLeftClickHeld = false;
			}
            break;
        }
	}

    if (isLeftClickHeld)
    {
		int x, y;
		SDL_GetMouseState(&x, &y);
		OnLeftClickHeld(x, y);
	}
}
