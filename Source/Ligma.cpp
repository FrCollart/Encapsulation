//-------------------------------------------------------//
//		   	L I G M A   S O U R C E   F I L E	         //
//-------------------------------------------------------//
//														 //
// Owners:												 //
//	- François Collart									 //
//  - Raphaël Mateescu									 //
//														 //
//-------------------------------------------------------//
//														 //
// Dependencies:										 //
// - Raylib: https://www.raylib.com/                     //
// - SDL: https://www.libsdl.org/                        //
//                                                       //
//-------------------------------------------------------//
//                                                       //
//                 All rights reserved.                  //
//                                                       //
//-------------------------------------------------------//


// C++ dependencies
#include <cstdlib>

// Project dependencies
#include "SDLTests.h"
#include "RaylibTests.h"
#include "App.h"

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
	// It should display a Raylib Window with a white background and a text.

	/*
	if (RaylibTests::TestRaylib() == -1)
	{
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
	*/

	App* app = new App();
	app->Run();

	return EXIT_SUCCESS;
}
