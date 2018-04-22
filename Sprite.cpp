#include "Sprite.h"
Sprite::Sprite(std::string title, int frameWidth, int frameHeight,
	int rows,int columns,Color chroma)
	:frameWidth(frameWidth),
	frameHeight(frameHeight),
	rows(rows),
	columns(columns)
{
	last = std::chrono::steady_clock::now();
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
	if (columns != 1) {
		std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
		if ((now - last).count() >= 500000000 / columns) {
			currentPos++;
			if (currentPos == columns)
				currentPos = 0;
			last = now;
		}
	}
	sprite->Render({ x, y,frameWidth,frameHeight }, { currentPos*frameWidth, currentAnimation*frameHeight,frameWidth,frameHeight });

}

void Sprite::RenderFrame(int x,int y,int row, int column)
{
	sprite->Render({ x, y,frameWidth,frameHeight }, { column*frameWidth, row*frameHeight,frameWidth,frameHeight });
}

void Sprite::RenderMirrored(int x, int y)
{

	if (columns != 1) {
		std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
		if ((now - last).count() >= 500000000 / columns) {
			currentPos++;
			if (currentPos == columns)
				currentPos = 0;
			last = now;
		}
	}
	sprite->RenderMirrored({ x, y,frameWidth,frameHeight }, { currentPos*frameWidth, currentAnimation*frameHeight,frameWidth,frameHeight });
}

void Sprite::SwitchAnimation(int i)
{
	currentAnimation = i;
}
