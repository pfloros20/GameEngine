#include "Character.h"
#include "SDL.h"
Character::Character(int x, int y, std::string sprite,
	int frameWidth, int frameHeight, int columns, int rows,	Color chroma)
	:x(x),
	y(y)
{
	Color c = { chroma.r,chroma.g,chroma.b };
	this->sprite = std::make_unique<Sprite>(sprite,frameWidth,frameHeight,columns,rows, c);
}
void Character::Render()
{
	sprite->RenderFrame(x,y,0,0);
}

void Character::Update(button input)
{
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (input==RIGHT) {
		x += 10;
	}
	if (input == LEFT) {
		x -= 10;
	}
	if (input == UP) {
		y -= 10;
	}
	if (input == DOWN) {
		y += 10;
	}
}
