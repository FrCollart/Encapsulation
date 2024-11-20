#pragma once

class EventHandler
{
public:
	virtual void HandleEvents() = 0;

	void OnLeftClickPressed(int x, int y);
	void OnLeftClickReleased(int x, int y);
};

