// Base class
#include "BallsManager.h"

// C++ dependencies
#include <cmath>

// Project dependecies
#include "Ball.h"
#include "Edge.h"
#include "Sprite.h"
#include "SpritesLoader.h"
#include "QuadTree.h"
#include "GameConsts.h"

BallsManager* BallsManager::instance = nullptr;

void BallsManager::Initialize()
{

	SpawnBalls();

	SpawnEdges();
}

void BallsManager::Update(float deltaTime)
{
	Rectangle* rect = new Rectangle(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT);
	std::vector<std::pair<Ball*, Ball*>> vecCollidingPairs;

	// to decompose one frame into nSimulationUpdates frames
	int nSimulationUpdates = 4;
	float simulatedDeltaTime = deltaTime / (float)nSimulationUpdates;
	int maxSimulationSteps = 15;

	for (int i = 0; i < nSimulationUpdates; i++)
	{
		delete quadTree;

		//Setup Collision Detection for balls
		for (Ball* ball : balls)
		{

			ball->SetSimTimeRemaining(simulatedDeltaTime);
		}

		for (int j = 0; j < maxSimulationSteps; j++)
		{

			for (Ball* ball : balls)
			{
				//ball displacement
				if (ball->GetSimTimeRemainging() > 0.0f)
				{
					ball->SetOldX(ball->GetX());
					ball->SetOldY(ball->GetY());
					ball->SetAccelerationX(ball->GetVelocityX() * -1 * .8f);
					ball->SetAccelerationY(ball->GetVelocityY() * -1 * .8f);
					ball->SetVelocityX(ball->GetVelocityX() + (ball->GetAccelerationX() * ball->GetSimTimeRemainging()));
					ball->SetVelocityY(ball->GetVelocityY() + (ball->GetAccelerationY() * ball->GetSimTimeRemainging()));
					ball->SetX(ball->GetX() + (ball->GetVelocityX() * ball->GetSimTimeRemainging()));
					ball->SetY(ball->GetY() + (ball->GetVelocityY() * ball->GetSimTimeRemainging()));

					// if velocity is negligeable set it to null
					if (std::fabs(ball->GetVelocityX() * ball->GetVelocityX() + ball->GetVelocityY() * ball->GetVelocityY()) < 5.f)
					{
						ball->SetVelocityX(0);
						ball->SetVelocityY(0);
					}
				}
			}
			for (Ball* ball : balls)
			{
				//ball / ball collision check 
				Rectangle* ballDetection = new Rectangle(ball->GetX(), ball->GetY(), ball->GetRadius() * 4, ball->GetRadius() * 4);
				for (Ball* NearBall : balls)
				{
					float range = NearBall->GetRadius() + ball->GetRadius();
					float distance = std::sqrtf(std::powf((NearBall->GetX() - ball->GetX()), 2) + std::powf((NearBall->GetY() - ball->GetY()), 2));
					if (range > distance && NearBall != ball)
					{
						vecCollidingPairs.push_back({ ball, NearBall });

						float overlap = 0.5f * (distance - ball->GetRadius() - NearBall->GetRadius());

						ball->SetX(ball->GetX() - overlap * (ball->GetX() - NearBall->GetX()) / distance);
						ball->SetY(ball->GetY() - overlap * (ball->GetY() - NearBall->GetY()) / distance);

						NearBall->SetX(NearBall->GetX() + overlap * (ball->GetX() - NearBall->GetX()) / distance);
						NearBall->SetY(NearBall->GetY() + overlap * (ball->GetY() - NearBall->GetY()) / distance);
					}
				}
				delete ballDetection;

				//ball / Edge Collision
				for (Edge* edge : edges)
				{
					float lineX1 = edge->GetEndX() - edge->GetStartX();
					float lineY1 = edge->GetEndY() - edge->GetStartY();

					float lineX2 = ball->GetX() - edge->GetStartX();
					float lineY2 = ball->GetY() - edge->GetStartY();

					float edgeLength = lineX1 * lineX1 + lineY1 * lineY1;

					float t = std::max(0.f, std::min(edgeLength, (lineX1 * lineX2 + lineY1 * lineY2))) / edgeLength;

					float closestPointX = edge->GetStartX() + t * lineX1;
					float closestPointY = edge->GetStartY() + t * lineY1;

					float distance = std::sqrtf(std::pow(ball->GetX() - closestPointX, 2) + std::powf(ball->GetY() - closestPointY, 2));

					if (distance <= (ball->GetRadius() + edge->GetRadius()))
					{
						// collision occured

						float distance = std::sqrtf(std::powf((closestPointX - ball->GetX()), 2) + std::powf((closestPointY - ball->GetY()), 2));

						//Normal
						float nx = (closestPointX - ball->GetX()) / distance;
						float ny = (closestPointY - ball->GetY()) / distance;

						//tangent
						float tx = -ny;
						float ty = nx;

						//Dot product tangent
						float dpTan1 = ball->GetVelocityX() * tx + ball->GetVelocityY() * ty;
						float dpTan2 = -ball->GetVelocityX() * tx - ball->GetVelocityY() * ty;

						//Dot produc normal
						float dpNorm1 = ball->GetVelocityX() * nx + ball->GetVelocityY() * ny;
						float dpNorm2 = -ball->GetVelocityX() * nx - ball->GetVelocityY() * ny;

						ball->SetVelocityX(tx * dpTan1 + nx * dpNorm2);
						ball->SetVelocityY(ty * dpTan1 + ny * dpNorm2);
					}

				}

				//time displacement
				float intendedSpeed = std::sqrtf(ball->GetAccelerationX() * ball->GetAccelerationX() +
					ball->GetAccelerationY() * ball->GetAccelerationY());
				float intendedDistance = intendedSpeed * ball->GetSimTimeRemainging();
				float actualDistance = std::sqrtf(std::powf(ball->GetX() - ball->GetOldX(), 2) + std::powf(ball->GetY() - ball->GetOldY(), 2));
				float actualTime = actualDistance / intendedSpeed;

				ball->SetSimTimeRemaining(ball->GetSimTimeRemainging() - actualTime);
			}

			// calculate all dynamic collisions at the same time
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
	}
}

void BallsManager::CleanUp()
{
	balls.clear();
	edges.clear();
}

void BallsManager::SpawnBalls()
{
	//white
	Sprite* sprite = SpritesLoader::GetSprites()[0];
	Ball* ball = new Ball(WINDOW_WIDTH * 1.75f / 7.f, WINDOW_HEIGHT / 2.f - BALL_RADIUS, BALL_RADIUS, 0.f, 0.f, sprite);
	balls.push_back(ball);

	//red and blue from left to right and top to bot

	//frontmost
	sprite = SpritesLoader::GetSprites()[1];
	ball = new Ball(WINDOW_WIDTH * 5.f / 7.f, WINDOW_HEIGHT / 2.f - BALL_RADIUS, BALL_RADIUS, 0.0f, 0.0f, sprite);
	balls.push_back(ball);

	//col 2
	sprite = SpritesLoader::GetSprites()[1];
	ball = new Ball(WINDOW_WIDTH * 5.f / 7.f + BALL_RADIUS * 1.75f, WINDOW_HEIGHT / 2.f - BALL_RADIUS * 2.f, BALL_RADIUS, 0.0f, 0.0f, sprite);
	balls.push_back(ball);
	sprite = SpritesLoader::GetSprites()[2];
	ball = new Ball(WINDOW_WIDTH * 5.f / 7.f + BALL_RADIUS * 1.75f, WINDOW_HEIGHT / 2.f + BALL_RADIUS * .1f, BALL_RADIUS, 0.0f, 0.0f, sprite);
	balls.push_back(ball);

	//col3
	sprite = SpritesLoader::GetSprites()[2];
	ball = new Ball(WINDOW_WIDTH * 5.f / 7.f + BALL_RADIUS * 3.5f, WINDOW_HEIGHT / 2.f - BALL_RADIUS * 3.f, BALL_RADIUS, 0.0f, 0.0f, sprite);
	balls.push_back(ball);
	sprite = SpritesLoader::GetSprites()[3];
	ball = new Ball(WINDOW_WIDTH * 5.f / 7.f + BALL_RADIUS * 3.5f, WINDOW_HEIGHT / 2.f - BALL_RADIUS * 1.f, BALL_RADIUS, 0.0f, 0.0f, sprite);
	balls.push_back(ball);
	sprite = SpritesLoader::GetSprites()[1];
	ball = new Ball(WINDOW_WIDTH * 5.f / 7.f + BALL_RADIUS * 3.5f, WINDOW_HEIGHT / 2.f + BALL_RADIUS * 1.f, BALL_RADIUS, 0.0f, 0.0f, sprite);
	balls.push_back(ball);

	//col4
	sprite = SpritesLoader::GetSprites()[1];
	ball = new Ball(WINDOW_WIDTH * 5.f / 7.f + BALL_RADIUS * 5.25f, WINDOW_HEIGHT / 2.f - BALL_RADIUS * 4.f, BALL_RADIUS, 0.0f, 0.0f, sprite);
	balls.push_back(ball);
	sprite = SpritesLoader::GetSprites()[2];
	ball = new Ball(WINDOW_WIDTH * 5.f / 7.f + BALL_RADIUS * 5.25f, WINDOW_HEIGHT / 2.f - BALL_RADIUS * 2.f, BALL_RADIUS, 0.0f, 0.0f, sprite);
	balls.push_back(ball);
	sprite = SpritesLoader::GetSprites()[1];
	ball = new Ball(WINDOW_WIDTH * 5.f / 7.f + BALL_RADIUS * 5.25f, WINDOW_HEIGHT / 2.f + BALL_RADIUS * .1f, BALL_RADIUS, 0.0f, 0.0f, sprite);
	balls.push_back(ball);
	sprite = SpritesLoader::GetSprites()[2];
	ball = new Ball(WINDOW_WIDTH * 5.f / 7.f + BALL_RADIUS * 5.25f, WINDOW_HEIGHT / 2.f + BALL_RADIUS * 2.1f, BALL_RADIUS, 0.0f, 0.0f, sprite);
	balls.push_back(ball);

	//col5
	sprite = SpritesLoader::GetSprites()[2];
	ball = new Ball(WINDOW_WIDTH * 5.f / 7.f + BALL_RADIUS * 7.f, WINDOW_HEIGHT / 2.f - BALL_RADIUS * 5.f, BALL_RADIUS, 0.0f, 0.0f, sprite);
	balls.push_back(ball);
	sprite = SpritesLoader::GetSprites()[2];
	ball = new Ball(WINDOW_WIDTH * 5.f / 7.f + BALL_RADIUS * 7.f, WINDOW_HEIGHT / 2.f - BALL_RADIUS * 3.f, BALL_RADIUS, 0.0f, 0.0f, sprite);
	balls.push_back(ball);
	sprite = SpritesLoader::GetSprites()[1];
	ball = new Ball(WINDOW_WIDTH * 5.f / 7.f + BALL_RADIUS * 7.f, WINDOW_HEIGHT / 2.f - BALL_RADIUS * 1.f, BALL_RADIUS, 0.0f, 0.0f, sprite);
	balls.push_back(ball);
	sprite = SpritesLoader::GetSprites()[2];
	ball = new Ball(WINDOW_WIDTH * 5.f / 7.f + BALL_RADIUS * 7.f, WINDOW_HEIGHT / 2.f + BALL_RADIUS * 1.f, BALL_RADIUS, 0.0f, 0.0f, sprite);
	balls.push_back(ball);
	sprite = SpritesLoader::GetSprites()[1];
	ball = new Ball(WINDOW_WIDTH * 5.f / 7.f + BALL_RADIUS * 7.f, WINDOW_HEIGHT / 2.f + BALL_RADIUS * 3.f, BALL_RADIUS, 0.0f, 0.0f, sprite);
	balls.push_back(ball);
}

void BallsManager::SpawnEdges()
{
	//Create pool edges
	float lineRadius = BALL_RADIUS * 1.5f;

	//horizontal
	Edge* edge = new Edge(WINDOW_WIDTH - lineRadius * 4.3f, WINDOW_HEIGHT - lineRadius * 1.5f, WINDOW_WIDTH / 2 + lineRadius * 2, WINDOW_HEIGHT - lineRadius * 1.5f, lineRadius); //bot right
	edges.push_back(edge);
	edge = new Edge(WINDOW_WIDTH / 2 - lineRadius * 3, WINDOW_HEIGHT - lineRadius * 1.5f, lineRadius * 3.f, WINDOW_HEIGHT - lineRadius * 1.5f, lineRadius); //bot left
	edges.push_back(edge);

	edge = new Edge(WINDOW_WIDTH - lineRadius * 4.3f, lineRadius * .25f, WINDOW_WIDTH / 2 + lineRadius * 2, lineRadius * .25f, lineRadius); //top right
	edges.push_back(edge);
	edge = new Edge(WINDOW_WIDTH / 2 - lineRadius * 3, lineRadius * .25f, lineRadius * 3.f, lineRadius * .25f, lineRadius); //top left
	edges.push_back(edge);

	//vertical
	edge = new Edge(lineRadius * .25f, WINDOW_HEIGHT - lineRadius * 4, lineRadius * .25f, lineRadius * 3, lineRadius); //left
	edges.push_back(edge);

	edge = new Edge(WINDOW_WIDTH - lineRadius * 1.6f, WINDOW_HEIGHT - lineRadius * 4, WINDOW_WIDTH - lineRadius * 1.6f, lineRadius * 3, lineRadius); //right
	edges.push_back(edge);
}

void BallsManager::HitWhiteBall(int dirX, int dirY)
{
	Ball* whiteBall = balls[0];
	whiteBall->SetVelocityX(dirX * 5.0f);
	whiteBall->SetVelocityY(dirY * 5.0f);
}

BallsManager* BallsManager::GetInstance()
{
	if (instance == nullptr) instance = new BallsManager();
	return instance;
}
