#include "BallsManager.h"
#include "Ball.h"
#include "Sprite.h"
#include "SpritesLoader.h"
#include "QuadTree.h"
#include "App.h"

BallsManager* BallsManager::instance = nullptr;

void BallsManager::Initialize()
{
	// TEST ONLY
	Sprite* sprite = SpritesLoader::GetSprites()[0];
	Ball* ball = new Ball(100.0f, 100.0f, 50.0f, 100.0f, 1.0f, 1.0f, sprite);
	balls.push_back(ball);
}

void BallsManager::Update(float deltaTime)
{
	//Rectangle* rect = new Rectangle(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT);
	//delete quadTree;
	//quadTree = new QuadTree(rect, 4);
	//for (Ball* ball : balls)
	//{
	//	quadTree->InsertDisplayable(ball);
	//}

	//for (Ball* ball : balls)
	//{
	//	Rectangle* ballDetection = new Rectangle(ball->GetX(), ball->GetY(), ball->GetRadius() * 2, ball->GetRadius() * 2);
	//	std::vector<DisplayableObject*> others = quadTree->Query(ballDetection);
	//	for (DisplayableObject* displayable : others)
	//	{
	//	}
	//}
}

BallsManager* BallsManager::GetInstance()
{
	if (instance == nullptr) instance = new BallsManager();
	return instance;
}
