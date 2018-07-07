#pragma once
#include<string>
#include "Sprite.h"
class Font {
public:
	Font(std::string title, int width, int height, Color chroma);
	~Font();
	Font(const Font& font) = delete;
	Font& operator=(const Font& font) = delete;
	void RenderText(std::string text, int x, int y);
private:
	Sprite* fontSprite;
	int width, height;
};