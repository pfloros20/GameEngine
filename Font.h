#pragma once
#include <string>
#include "Sprite.h"
#include <memory>
class Font {
public:
	Font(std::string title, int width, int height, Color chroma);
	void RenderText(std::string text, int x, int y);
private:
	std::unique_ptr<Sprite> fontSprite;
	int width, height;
};