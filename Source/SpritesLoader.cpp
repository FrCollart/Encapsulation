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

	// White ball
	SDLSprite* whiteBallSprite = new SDLSprite();
	whiteBallSprite->LoadImage(WHITE_BALL_TEXTURE_PATH, BALL_RADIUS * 2, BALL_RADIUS * 2);
	sprites.push_back(whiteBallSprite);


	// Numbered balls
	for (int ballNumber = 1; ballNumber < 4; ballNumber++)
	{
		SDLSprite* numberedBallSprite = new SDLSprite();
		std::string path = std::string(BALL_TEXTURE_PATH) + std::to_string(ballNumber) + ".png";
		numberedBallSprite->LoadImage(path.c_str(), BALL_RADIUS * 2, BALL_RADIUS * 2);
		sprites.push_back(numberedBallSprite);
	}

	// Table
	SDLSprite* tableSprite = new SDLSprite();
	tableSprite->LoadImage(TABLE_TEXTURE_PATH, WINDOW_WIDTH, WINDOW_HEIGHT);
	sprites.push_back(tableSprite);

	// Ball prediction
	SDLSprite* ballPredictionSprite = new SDLSprite();
	ballPredictionSprite->LoadImage(BALL_PREDICTION_TEXTURE_PATH, BALL_RADIUS * 15, BALL_RADIUS * 15);
	sprites.push_back(ballPredictionSprite);
}

void SpritesLoader::RaylibLoadSprites()
{
	UnloadSprites();

	// White ball
	RaylibSprite* sprite = new RaylibSprite();
	sprite->LoadImage(WHITE_BALL_TEXTURE_PATH, BALL_RADIUS * 2, BALL_RADIUS * 2);
	sprites.push_back(sprite);

	// Numbered balls
	for (int ballNumber = 1; ballNumber < 4; ballNumber++)
	{
		RaylibSprite* sprite = new RaylibSprite();
		std::string path = std::string(BALL_TEXTURE_PATH) + std::to_string(ballNumber) + ".png";
		sprite->LoadImage(path.c_str(), BALL_RADIUS * 2, BALL_RADIUS * 2);
		sprites.push_back(sprite);
	}

	// Table
	RaylibSprite* tableSprite = new RaylibSprite();
	tableSprite->LoadImage(TABLE_TEXTURE_PATH, WINDOW_WIDTH, WINDOW_HEIGHT);
	sprites.push_back(tableSprite);

	// Ball prediction
	RaylibSprite* ballPredictionSprite = new RaylibSprite();
	ballPredictionSprite->LoadImage(BALL_PREDICTION_TEXTURE_PATH, BALL_RADIUS * 15, BALL_RADIUS * 15);
	sprites.push_back(ballPredictionSprite);
}

void SpritesLoader::UnloadSprites()
{
	for (Sprite* sprite : sprites)
	{
		delete sprite;
	}
	sprites.clear();
}
