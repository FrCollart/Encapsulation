#pragma once

// Abstract class
#include "EventHandler.h"

class SDLEventHandler : public EventHandler
{
public:
	SDLEventHandler();
	void HandleEvents() override;

	static bool IsRunning() { return isRunning; }

private:
	static bool isRunning;
	bool isLeftClickHeld = false;
};
