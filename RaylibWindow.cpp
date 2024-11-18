#include "RaylibWindow.h"
#include "raylib.h"
#include "Sprite.h"
#include "App.h"

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
	for (const auto& sprite : App::GetInstance()->GetSprites())
	{
		InternalDrawSprite(*sprite);
	}
}

void RaylibWindow::InternalDrawSprite(const Sprite& sprite)
{
	const void* data = sprite.GetData();
	Texture2D* texture = (Texture2D*)data;

	DrawTexture(*texture, sprite.GetX(), sprite.GetY(), WHITE);
}

void RaylibWindow::Cleanup()
{
	CloseWindow();
}
