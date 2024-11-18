#include "RaylibWindow.h"
#include "raylib.h"
#include "Sprite.h"

void RaylibWindow::Initialize()
{

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

void RaylibWindow::Draw(const std::vector<const class Sprite*>& spritesList)
{
	BeginDrawing();
	for (const auto& sprite : spritesList)
	{
		InternalDrawSprite(*sprite);
	}
	EndDrawing();
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
