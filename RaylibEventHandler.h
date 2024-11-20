#pragma once

// Abstract class
#include "EventHandler.h"

class RaylibEventHandler : public EventHandler
{
public:
	void HandleEvents() override;
};

