#pragma once
#include <vector>

class SpritesLoader
{
public:
	SpritesLoader() {}
	~SpritesLoader() {}

	static void SDLLoadSprites();
	static void RaylibLoadSprites();
	static void UnloadSprites();

	static std::vector<class Sprite*> GetSprites() { return sprites; }

public:
	static std::vector<class Sprite*> sprites;
};

