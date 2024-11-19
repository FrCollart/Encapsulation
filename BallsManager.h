#pragma once
#include <vector>

class BallsManager
{
public:
	void Initialize();
	void Update();

	std::vector<class Ball*> GetBalls() const { return balls; }

private:

	std::vector<class Ball*> balls;
};

