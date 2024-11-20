// Base class
#include "SDLInputListener.h"

// External dependencies
#include <SDL.h>
#include <iostream>

void SDLInputListener::OnLeftClickPressed(union SDL_Event event)
{
    std::cout << "Left button clicked at ("
        << event.button.x << ", " << event.button.y << ")\n";
}

void SDLInputListener::OnLeftClickReleased(union SDL_Event event)
{
    std::cout << "Left button released at ("
        << event.button.x << ", " << event.button.y << ")\n";
}
