#include "Sprite.h"
#include "Window.h"
#include "Color.h"
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
	if(columns!=1)
		SDL_Delay(500/columns);
	if (currentPos == columns)
		currentPos = 0;
}

void Sprite::RenderFrame(int x,int y,int row, int column)
{
	sprite->Render({ x, y,frameWidth,frameHeight }, { column*frameWidth, row*frameHeight,frameWidth,frameHeight });
}

void Sprite::RenderMirrored(int x, int y)
{
	sprite->RenderMirrored({ x, y,frameWidth,frameHeight }, { currentPos*frameWidth, currentAnimation*frameHeight,frameWidth,frameHeight });
	currentPos++;
	if (columns != 1)
		SDL_Delay(500 / columns);
	if (currentPos == columns)
		currentPos = 0;
}

void Sprite::SwitchAnimation(int i)
{
	currentAnimation = i;
}
