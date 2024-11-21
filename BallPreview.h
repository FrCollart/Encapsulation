#pragma once
class BallPreview
{
public:
	static BallPreview* GetInstance();
	class DisplayableObject* GetBallPreview() { return ballPreview; }

private:
	static BallPreview* instance;
	class DisplayableObject* ballPreview;
};

