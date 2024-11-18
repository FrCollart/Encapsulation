#include <cstdlib>

#include "SDLTests.h"
#include "RaylibTests.h"

int main(int argc, char* argv[])
{
	// Uncomment this to test SDL lib importation
	// It should display a SDL Window with a blue background.

	/*
	if (SDLTests::TestSDL() == -1)
	{
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
	*/

	// Uncomment this to test Raylib importation
	// It should display a Raylib Window with a white background.

	/*
	if (RaylibTests::TestRaylib() == -1)
	{
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
	*/

	return EXIT_SUCCESS;
}
