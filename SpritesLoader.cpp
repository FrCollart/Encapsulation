#include "SpritesLoader.h"
#include "Sprite.h"
#include "SDLSprite.h"
#include "RaylibSprite.h"

std::vector<Sprite*> SpritesLoader::sprites;

void SpritesLoader::SDLLoadSprites()
{
	UnloadSprites();
	SDLSprite* sprite = new SDLSprite();
	sprite->LoadImage("Textures/ball.png");
	sprites.push_back(sprite);
}

void SpritesLoader::RaylibLoadSprites()
{
	UnloadSprites();
	RaylibSprite* sprite = new RaylibSprite();
	sprite->LoadImage("Textures/ball.png");
	sprites.push_back(sprite);
}

void SpritesLoader::UnloadSprites()
{
	sprites.clear();
}
