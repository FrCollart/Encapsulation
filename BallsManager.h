#pragma once

// C++ dependencies
#include <vector>

class BallsManager
{
public:

	void Initialize();
	void Update(float deltaTime);
	void CleanUp();
	void SpawnBalls();
	void SpawnEdges();

	void HitWhiteBall(int dirX, int dirY);

	static BallsManager* GetInstance();

	std::vector<class Ball*> GetBalls() const { return balls; }

private:

	static BallsManager* instance;
	std::vector<class Ball*> balls;
	std::vector<class Edge*> edges;
	class QuadTree* quadTree;
};

constexpr float FRICTION_FACTOR = 0.8f;

