#include "BallsManager.h"

BallsManager* BallsManager::instance = nullptr;

BallsManager* BallsManager::GetInstance()
{
    if (instance == nullptr) instance = new BallsManager();
	return instance;
}
