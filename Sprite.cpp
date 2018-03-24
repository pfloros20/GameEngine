#include "Sprite.h"
#include "Window.h"
#include "Color.h"
#include "SDL.h"
Sprite::Sprite(std::string title, int frameWidth, int frameHeight,
	int rows,int columns,Color chroma)
	:frameWidth(frameWidth),
	frameHeight(frameHeight),
	rows(rows),
	columns(columns)
{
	currentPos = 0;
	currentAnimation = 0;
	sprite = new Texture(title, { chroma.r, chroma.g, chroma.b });
}

Sprite::~Sprite()
{
	delete sprite;
	sprite = nullptr;
}

void Sprite::Render(int x, int y)
{
	sprite->Render({ x, y,frameWidth,frameHeight }, { currentPos*frameWidth, currentAnimation*frameHeight,frameWidth,frameHeight });
	currentPos++;
	SDL_Delay(500/columns);
	if (currentPos == columns)
		currentPos = 0;
}

void Sprite::SwitchAnimation(int i)
{
	currentAnimation = i;
}
