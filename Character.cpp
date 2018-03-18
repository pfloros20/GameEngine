#include "Character.h"
#include <iostream>
Character::Character(int x, int y, int width, int height,
	SDL_Surface* sprite,SDL_Renderer* renderer)
	:characterRect({ x,y,width,height }),
	sprite(sprite),
	renderer(renderer)
{
	if (sprite == nullptr)
		std::cout << "Sprite didnt Load: " << SDL_GetError() << std::endl;
	texture = SDL_CreateTextureFromSurface(renderer, sprite);
}

Character::~Character()
{
	SDL_FreeSurface(sprite);
	SDL_DestroyTexture(texture);
}

void Character::Render()
{
	SDL_RenderCopy(renderer, texture,NULL,&characterRect);
	SDL_RenderPresent(renderer);
}

void Character::Update(std::string dir)
{
	if (dir == "RIGHT")
		characterRect.x += 10;
	else if (dir == "LEFT")
		characterRect.x -= 10;
	else if (dir == "UP")
		characterRect.y -= 10;
	else if (dir == "DOWN")
		characterRect.y += 10;
}
