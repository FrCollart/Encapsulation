#pragma once

class EventHandler
{
public:
	virtual void HandleEvents() = 0;

	void OnLeftClickPressed(int x, int y);
	void OnLeftClickHeld(int x, int y);
	void OnLeftClickReleased(int x, int y);

private:
	int pressedX = 0;
	int pressedY = 0;
	class BallPreview* ballPreview;
	class DisplayableObject* ballPreviewObject;
};

