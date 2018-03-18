#include "Texture.h"
#include <iostream>
Texture::Texture(std::string title,SDL_Renderer* renderer)
	:renderer(renderer)
{
	SDL_Surface* surface = SDL_LoadBMP(title.c_str());
	if (surface == nullptr)
		std::cout << "surface didnt Load: " << SDL_GetError() << std::endl;
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == nullptr)
		std::cout << "Texture didnt Load: " << SDL_GetError() << std::endl;
	width = surface->w;
	height = surface->h;
	SDL_FreeSurface(surface);
}

Texture::Texture(std::string title, SDL_Renderer* renderer,
	int transparentRed, int transparentBlue, int transparentGreen)
	:renderer(renderer)
{
	SDL_Surface* surface = SDL_LoadBMP(title.c_str());
	if (surface == nullptr)
		std::cout << "surface didnt Load: " << SDL_GetError() << std::endl;
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format
		, transparentRed, transparentGreen, transparentBlue));
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == nullptr)
		std::cout << "Texture didnt Load: " << SDL_GetError() << std::endl;
	width = surface->w;
	height = surface->h;
	SDL_FreeSurface(surface);
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
