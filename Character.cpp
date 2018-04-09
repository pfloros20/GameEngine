#include "Character.h"
#include <iostream>
#include "Window.h"
#include "SDL.h"
Character::Character(int x, int y, std::string sprite,
	int frameWidth, int frameHeight, int columns, int rows,	Color chroma)
	:x(x),
	y(y)
{
	this->sprite = new Sprite(sprite,frameWidth,frameHeight,columns,rows, { chroma.r,chroma.g,chroma.b });
}

Character::~Character()
{
	delete sprite;
	sprite = nullptr;
}

void Character::Render()
{
	sprite->Render(x,y);
}

void Character::Update()
{
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_RIGHT]) {
		x += 10;
		sprite->SwitchAnimation(1);
	}
	if (state[SDL_SCANCODE_LEFT]) {
		x -= 10;
		sprite->SwitchAnimation(3);
	}
	if (state[SDL_SCANCODE_UP]) {
		y -= 10;
		sprite->SwitchAnimation(0);
	}
	if (state[SDL_SCANCODE_DOWN]) {
		y += 10;
		sprite->SwitchAnimation(2);
	}
}
