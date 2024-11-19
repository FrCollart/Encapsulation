#include "RaylibWindow.h"
#include "raylib.h"
#include "Sprite.h"
#include "BallsManager.h"
#include "Ball.h"

void RaylibWindow::Initialize()
{
	// No need to initialize in Raylib
}

void RaylibWindow::CreateWindow(int width, int height, const char* title)
{
	InitWindow(width, height, title);
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

void RaylibWindow::InternalDrawSprite(const Sprite& sprite, int x, int y)
{
	const void* data = sprite.GetData();
	Texture2D* texture = (Texture2D*)data;

	DrawTexture(*texture, x, y, WHITE);
}

void RaylibWindow::Cleanup()
{
	CloseWindow();
}
