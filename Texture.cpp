#include "Texture.h"
#include <iostream>
Texture::Texture(std::string title,SDL_Renderer* renderer)
	:renderer(renderer)
{
	SDL_Surface* sprite = SDL_LoadBMP(title.c_str());
	if (sprite == nullptr)
		std::cout << "Sprite didnt Load: " << SDL_GetError() << std::endl;
	texture = SDL_CreateTextureFromSurface(renderer, sprite);
	if (texture == nullptr)
		std::cout << "Texture didnt Load: " << SDL_GetError() << std::endl;
	width = sprite->w;
	height = sprite->h;
	SDL_FreeSurface(sprite);
}

Texture::Texture(std::string title, SDL_Renderer* renderer,
	int transparentRed, int transparentBlue, int transparentGreen)
	:renderer(renderer)
{
	SDL_Surface* sprite = SDL_LoadBMP(title.c_str());
	if (sprite == nullptr)
		std::cout << "Sprite didnt Load: " << SDL_GetError() << std::endl;
	SDL_SetColorKey(sprite, SDL_TRUE, SDL_MapRGB(sprite->format
		, transparentRed, transparentGreen, transparentBlue));
	texture = SDL_CreateTextureFromSurface(renderer, sprite);
	if (texture == nullptr)
		std::cout << "Texture didnt Load: " << SDL_GetError() << std::endl;
	width = sprite->w;
	height = sprite->h;
	SDL_FreeSurface(sprite);
}

Texture::~Texture()
{
	SDL_DestroyTexture(texture);
}

void Texture::Render(int x, int y)
{
	SDL_Rect temp = { x,y,width,height };
	SDL_RenderCopy(renderer, texture, NULL,&temp );
}
