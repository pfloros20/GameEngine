#include "Font.h"
Font::Font(std::string title, int width, int height, Color chroma)
	:width(width),
	height(height)
{
	fontSprite = new Sprite(title, width, height, 3, 32, chroma);
}

Font::~Font()
{
	delete fontSprite;
}

void Font::RenderText(std::string text, int x, int y)
{
	const char *chars = text.c_str();
	int length = (unsigned)strlen(chars);
	for (int i = 0; i < length; i++) {
		int index = chars[i] - 32;
		fontSprite->RenderFrame(i*width+x, y, index / 32, index % 32);
	}
}