#pragma once
#include <vector>

class BallsManager
{
public:
	
	void Initialize();
	void Update(float deltaTime);
	void CleanUp();

	static BallsManager* GetInstance();

	std::vector<class Ball*> GetBalls() const { return balls; }

private:

	static BallsManager* instance;
	std::vector<class Ball*> balls;
	class QuadTree* quadTree;
};

