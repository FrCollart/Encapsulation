// Base class
#include "RaylibWindow.h"

// C++ dependencies
#include <string>

// Project dependencies
#include "Sprite.h"
#include "BallsManager.h"
#include "TimeModule.h"
#include "Ball.h"
#include "GameConsts.h"
#include "SpritesLoader.h"

void RaylibWindow::Initialize()
{
	Window::Initialize();
	// No need to initialize Raylib
}

void RaylibWindow::CreateWindow(int width, int height, const char* title)
{
	InitWindow(width, height, title);
	font = LoadFont(FONT_PATH);
}

bool RaylibWindow::IsOpen() const
{
	return !WindowShouldClose();
}

void RaylibWindow::Clear()
{
	ClearBackground(WHITE);
	
}

void RaylibWindow::BeginDraw()
{
	BeginDrawing();
}

void RaylibWindow::EndDraw()
{
	EndDrawing();
}

void RaylibWindow::InternalDrawBackground()
{
	Sprite* tableSprite = SpritesLoader::GetSprites()[4];
	const void* data = tableSprite->GetData();
	Texture2D* texture = (Texture2D*)data;

	DrawTexture(*texture, 0, 0, WHITE);
}

void RaylibWindow::InternalDrawFPS()
{
	std::string fpsText = "FPS: " + std::to_string((int)(timeModule->GetAverageFPS()));

	Vector2 textSize = MeasureTextEx(font, fpsText.c_str(), 20, 1.0f);
	Vector2 position = { WINDOW_WIDTH - textSize.x - 100, 10 };

	int padding = 10; // Padding around the text
	Rectangle rect = { position.x - padding, position.y - padding, textSize.x + 2 * padding, textSize.y + 2 * padding };

	DrawRectangleRec(rect, WHITE);

	DrawTextEx(font, fpsText.c_str(), position, 20, 1.0f, BLACK);
}

void RaylibWindow::InternalDrawSprite(DisplayableObject* object)
{
	Sprite* sprite = object->GetSprite();
	const void* data = sprite->GetData();
	Texture2D* texture = (Texture2D*)data;

	Vector2 position = { object->GetX(), object->GetY() };
	Vector2 origin = { (float)texture->width / 2.0f, (float)texture->height / 2.0f };

	DrawTexturePro(
		*texture,
		{ 0, 0, (float)texture->width, (float)texture->height }, // Source rectangle
		{ position.x + origin.x, position.y + origin.y, (float)texture->width, (float)texture->height }, // Destination rectangle
		origin, // Rotation origin
		object->GetOrientation(), // Rotation angle in degrees
		WHITE // Tint
	);
}

void RaylibWindow::CleanUp()
{
	UnloadFont(font);
	CloseWindow();
}
