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
            }
            break;

        case SDL_MOUSEBUTTONUP:
            OnLeftClickReleased(event.button.x, event.button.y);
            break;
        }
	}
}
