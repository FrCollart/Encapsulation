#include "BallsManager.h"
#include "Ball.h"
#include "Sprite.h"
#include "SpritesLoader.h"
#include "QuadTree.h"
#include "App.h"
#include "cmath"

BallsManager* BallsManager::instance = nullptr;

void BallsManager::Initialize()
{
	// TEST ONLY
	Sprite* sprite = SpritesLoader::GetSprites()[0];
	Ball* ball = new Ball(100.0f, 100.0f, 7.5f, 5.f, 1.0f, .0f, sprite);
	balls.push_back(ball);
	Ball* ball2 = new Ball(200.f, 100.0f, 7.5f, 5.f, -1.0f, .0f, sprite);
	balls.push_back(ball2);
}

void BallsManager::Update(float deltaTime)
{
	Rectangle* rect = new Rectangle(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT);
	delete quadTree;

	for (Ball* ball : balls)
	{
		ball->SetX(ball->GetX() + ball->GetDirX() * ball->GetSpeed() * deltaTime);
		ball->SetY(ball->GetY() + ball->GetDirY() * ball->GetSpeed() * deltaTime);
	}

	//Collision Detection
	quadTree = new QuadTree(rect, 4);
	for (Ball* ball : balls)
	{
		quadTree->AddBall(ball);
	}
	for (Ball* ball : balls)
	{
		Rectangle* ballDetection = new Rectangle(ball->GetX(), ball->GetY(), ball->GetRadius() * 4, ball->GetRadius() * 4);
		std::vector<Ball*> others = quadTree->Query(ballDetection);
		for (Ball* NearBall : others)
		{
			float range = NearBall->GetRadius() + ball->GetRadius();
			double distance = std::sqrt(std::pow((NearBall->GetX() - ball->GetX()), 2) + std::pow((NearBall->GetY() - ball->GetY()), 2));
			if (range >= distance && NearBall != ball)
			{
				ball->SetSpeed(0);
				NearBall->SetSpeed(0);
			}
		}
	}
}

void BallsManager::CleanUp()
{
	balls.clear();
}

BallsManager* BallsManager::GetInstance()
{
	if (instance == nullptr) instance = new BallsManager();
	return instance;
}
