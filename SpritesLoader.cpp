// Base Class
#include "SpritesLoader.h"

// Project dependencies
#include "Sprite.h"
#include "SDLSprite.h"
#include "RaylibSprite.h"
#include "GameConsts.h"

std::vector<Sprite*> SpritesLoader::sprites;

void SpritesLoader::SDLLoadSprites()
{
	UnloadSprites();
	SDLSprite* sprite = new SDLSprite();
	sprite->LoadImage(TEXTURE_PATH);
	sprites.push_back(sprite);
}

void SpritesLoader::RaylibLoadSprites()
{
	UnloadSprites();
	RaylibSprite* sprite = new RaylibSprite();
	sprite->LoadImage(TEXTURE_PATH);
	sprites.push_back(sprite);
}

void SpritesLoader::UnloadSprites()
{
	sprites.clear();
}
