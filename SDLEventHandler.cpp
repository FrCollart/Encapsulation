// Base class
#include "SDLEventHandler.h"

// Project dependencies
#include "SDLInputListener.h"

// External dependencies
#include <SDL.h>

bool SDLEventHandler::isRunning = true;

SDLEventHandler::SDLEventHandler()
{
    inputListener = new SDLInputListener();
}

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
                inputListener->OnLeftClickPressed(event);
            }
            break;

        case SDL_MOUSEBUTTONUP:
            inputListener->OnLeftClickReleased(event);
            break;
        }
	}
}
