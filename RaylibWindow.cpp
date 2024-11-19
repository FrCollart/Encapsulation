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

void RaylibWindow::InternalDraw()
{
	for (const auto& ball : BallsManager::GetInstance()->GetBalls())
	{
		InternalDrawSprite(*ball->GetSprite(), (int)ball->GetX(), (int)ball->GetY());
	}
}

void RaylibWindow::InternalDrawFPS()
{
	std::string fpsText = "FPS: " + std::to_string((int)(timeModule->GetFPS()));

	Vector2 textSize = MeasureTextEx(font, fpsText.c_str(), 20, 1.0f);
	Vector2 position = { WINDOW_WIDTH - textSize.x - 10, 10 };

	DrawTextEx(font, fpsText.c_str(), position, 20, 1.0f, BLACK);
}

void RaylibWindow::InternalDrawSprite(const Sprite& sprite, int x, int y)
{
	const void* data = sprite.GetData();
	Texture2D* texture = (Texture2D*)data;

	DrawTexture(*texture, x, y, WHITE);
}

void RaylibWindow::Cleanup()
{
	UnloadFont(font);
	CloseWindow();
}
