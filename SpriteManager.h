#pragma once
#include <vector>

enum Libs
{
	SDL,
	Raylib,
};

class SpriteManager
{

public:
	SpriteManager(Libs lib);

	void AddSprite(class Sprite* toAdd);

private:

	std::vector<class Sprite*> displayedSprites;
	class Window* currentWindow;
};

