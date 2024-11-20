// Base Class
#include "SpritesLoader.h"

// C++ dependencies
#include <string>

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
	std::string path = std::string(BALL_TEXTURE_PATH) + "10.png";
	sprite->LoadImage(path.c_str(), BALL_RADIUS * 2, BALL_RADIUS * 2);
	sprites.push_back(sprite);
}

void SpritesLoader::RaylibLoadSprites()
{
	UnloadSprites();
	RaylibSprite* sprite = new RaylibSprite();
	std::string path = std::string(BALL_TEXTURE_PATH) + "10.png";
	sprite->LoadImage(path.c_str(), BALL_RADIUS * 2, BALL_RADIUS * 2);
	sprites.push_back(sprite);
}

void SpritesLoader::UnloadSprites()
{
	sprites.clear();
}
