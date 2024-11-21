#pragma once
class BallPreview
{
public:
	static BallPreview* GetInstance();
	class DisplayableObject* GetBallPreviewObject() { return ballPreviewObject; }
	void SetBallPreviewObject(class DisplayableObject* ballPreview) { this->ballPreviewObject = ballPreview; }

private:
	static BallPreview* instance;
	class DisplayableObject* ballPreviewObject = nullptr;
};

