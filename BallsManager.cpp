#include "BallsManager.h"
#include "Ball.h"
#include "Sprite.h"
#include "SpritesLoader.h"

BallsManager* BallsManager::instance = nullptr;

void BallsManager::Initialize()
{
	// TEST ONLY
	Sprite* sprite = SpritesLoader::GetSprites()[0];
	Ball* ball = new Ball(100.0f, 100.0f, 50.0f, 100.0f, 1.0f, 1.0f, sprite);
	balls.push_back(ball);
}

BallsManager* BallsManager::GetInstance()
{
    if (instance == nullptr) instance = new BallsManager();
	return instance;
}
