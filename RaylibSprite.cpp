// Base class
#include "RaylibSprite.h"

// External dependencies
#include "raylib.h"

void RaylibSprite::LoadImage(const char* filepath)
{
	Image image = ::LoadImage(filepath);

    if (image.data == nullptr) {
        TraceLog(LOG_ERROR, "Failed to load image from %s", filepath);
        return;
    }

    Texture2D texture = LoadTextureFromImage(image);

    UnloadImage(image);

    if (texture.id == 0) {
        TraceLog(LOG_ERROR, "Failed to create texture from image: %s", filepath);
        return;
    }

    width = texture.width;
    height = texture.height;

    data = new Texture2D(texture);
}
