// Base class
#include "RaylibSprite.h"

// C++ dependencies
#include <fstream>

// External dependencies
#include "raylib.h"
#include "GameConsts.h"

void RaylibSprite::LoadImage(const char* filepath, int width, int height)
{
    std::ifstream file(filepath);
    if (!file) {
        TraceLog(LOG_ERROR, "File not found: %s", filepath);
        return;
    }

	Image image = ::LoadImage(filepath);
    

    if (image.data == nullptr) {
        TraceLog(LOG_ERROR, "Failed to load image from %s", filepath);
        return;
    }

    ImageResize(&image, width, height);

    Texture2D texture = LoadTextureFromImage(image);

    UnloadImage(image);

    if (texture.id == 0) {
        TraceLog(LOG_ERROR, "Failed to create texture from image: %s", filepath);
        return;
    }

    this->width = texture.width;
    this->height = texture.height;

    data = new Texture2D(texture);
}
