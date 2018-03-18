#include "Character.h"
#include <iostream>
Character::Character(int x, int y,std::string sprite,SDL_Renderer* renderer)
	:x(x),
	y(y),
	renderer(renderer)
{
	texture = new Texture(sprite,renderer);
}

Character::Character(int x, int y, std::string sprite, SDL_Renderer* renderer,
	int transparentRed, int transparentBlue, int transparentGreen)
	:x(x),
	y(y),
	renderer(renderer)
{
	texture = new Texture(sprite, renderer,transparentRed,transparentGreen,transparentBlue);
}

Character::~Character()
{
	delete texture;
	texture = nullptr;
}

void Character::Render()
{
	texture->Render(x, y);
}

void Character::Update(std::string dir)
{
	if (dir == "RIGHT")
		x += 10;
	else if (dir == "LEFT")
		x -= 10;
	else if (dir == "UP")
		y -= 10;
	else if (dir == "DOWN")
		y += 10;
}
