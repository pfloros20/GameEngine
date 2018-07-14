#include "Font.h"
Font::Font(std::string title, int width, int height, Color chroma)
	:width(width),
	height(height)
{
	fontSprite = std::make_unique<Sprite>(title, width, height, 3, 32, chroma);
}

void Font::RenderText(std::string text, int x, int y)
{
	const char *chars = text.c_str();
	int length = (unsigned)strlen(chars);
	int screenIndex = 0;
	for (int i = 0; i < length; i++) {
		int index = chars[i] - 32;
		if (chars[i] == '\n') {
			screenIndex = 0;
			y += height;
		}else {
			fontSprite->RenderFrame(screenIndex*width + x, y, index / 32, index % 32);
			screenIndex++;
		}
	}
}