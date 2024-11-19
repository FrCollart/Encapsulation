// Base class
#include "BallsManager.h"

// C++ dependencies
#include <cmath>

// Project dependecies
#include "Ball.h"
#include "Sprite.h"
#include "SpritesLoader.h"
#include "QuadTree.h"
#include "GameConsts.h"

BallsManager* BallsManager::instance = nullptr;

void BallsManager::Initialize()
{
	// TEST ONLY
	Sprite* sprite = SpritesLoader::GetSprites()[0];
	Ball* ball = new Ball(400.0f, 100.0f, 7.5f, 100.0f, 0.f, sprite);
	balls.push_back(ball);
	Ball* ball2 = new Ball(600.f, 95.0f, 7.5f, -200.0f, 0.0f, sprite);
	balls.push_back(ball2);
}

void BallsManager::Update(float deltaTime)
{
	Rectangle* rect = new Rectangle(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT);
	delete quadTree;
	std::vector<std::pair<Ball*, Ball*>> vecCollidingPairs;

	//Collision Detection
	quadTree = new QuadTree(rect, 4);
	for (Ball* ball : balls)
	{
		quadTree->AddBall(ball);
	}
	for (Ball* ball : balls)
	{
		ball->AddAccelerationX(ball->GetVelocityX() * -1 * .8f * deltaTime);
		ball->AddAccelerationY(ball->GetVelocityY() * -1 * .8f * deltaTime);
		ball->SetVelocityX(ball->GetVelocityX() + (ball->GetAccelerationX() * deltaTime));
		ball->SetVelocityY(ball->GetVelocityY() + (ball->GetAccelerationY() * deltaTime));
		ball->SetX(ball->GetX() + (ball->GetVelocityX() * deltaTime));
		ball->SetY(ball->GetY() + (ball->GetVelocityY() * deltaTime));

		if (std::fabs(ball->GetVelocityX() * ball->GetVelocityX() + ball->GetVelocityY() * ball->GetVelocityY()) < 0.1f)
		{
			ball->SetVelocityX(0);
			ball->SetVelocityY(0);
			ball->SetAccelerationX(0);
			ball->SetAccelerationY(0);
		}
	}
	for (Ball* ball : balls)
	{
		Rectangle* ballDetection = new Rectangle(ball->GetX(), ball->GetY(), ball->GetRadius() * 4, ball->GetRadius() * 4);
		std::vector<Ball*> others = quadTree->Query(ballDetection);
		for (Ball* NearBall : others)
		{
			float range = NearBall->GetRadius() + ball->GetRadius();
			float distance = std::sqrtf(std::powf((NearBall->GetX() - ball->GetX()), 2) + std::powf((NearBall->GetY() - ball->GetY()), 2));
			if (range >= distance && NearBall != ball)
			{
				vecCollidingPairs.push_back({ ball, NearBall });

				float overlap = 0.5f * (distance - ball->GetRadius() - NearBall->GetRadius());

				ball->SetX(ball->GetX() - overlap * (ball->GetX() - NearBall->GetX()) / distance);
				ball->SetY(ball->GetY() - overlap * (ball->GetY() - NearBall->GetY()) / distance);

				NearBall->SetX(NearBall->GetX() + overlap * (ball->GetX() - NearBall->GetX()) / distance);
				NearBall->SetY(NearBall->GetY() + overlap * (ball->GetY() - NearBall->GetY()) / distance);
			}
		}
	}


	for (std::pair<Ball*, Ball*> pair : vecCollidingPairs)
	{
		Ball* b1 = pair.first;
		Ball* b2 = pair.second;

		float distance = std::sqrtf(std::powf((b2->GetX() - b1->GetX()), 2) + std::powf((b2->GetY() - b1->GetY()), 2));

		//Normal
		float nx = (b2->GetX() - b1->GetX()) / distance;
		float ny = (b2->GetY() - b1->GetY()) / distance;

		//tangent
		float tx = -ny;
		float ty = nx;

		//Dot product tangent
		float dpTan1 = b1->GetVelocityX() * tx + b1->GetVelocityY() * ty;
		float dpTan2 = b2->GetVelocityX() * tx + b2->GetVelocityY() * ty;

		//Dot produc normal
		float dpNorm1 = b1->GetVelocityX() * nx + b1->GetVelocityY() * ny;
		float dpNorm2 = b2->GetVelocityX() * nx + b2->GetVelocityY() * ny;

		b1->SetVelocityX(tx * dpTan1 + nx * dpNorm2);
		b1->SetVelocityY(ty * dpTan1 + ny * dpNorm2);
		b2->SetVelocityX(tx * dpTan2 + nx * dpNorm1);
		b2->SetVelocityY(ty * dpTan2 + ny * dpNorm1);

	}
	vecCollidingPairs.clear();
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
