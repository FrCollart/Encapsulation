#include "SpriteManager.h"
#include "Sprite.h"
#include "Window.h"


SpriteManager::SpriteManager(Libs lib)
{

}

void SpriteManager::AddSprite(Sprite* toAdd)
{
	displayedSprites.push_back(toAdd);
}
