#include "Texture.h"
#include <iostream>
#include  "Window.h"
Texture::Texture(std::string title,Window* window)
	:window(window)
{
	SDL_Surface* surface = SDL_LoadBMP(title.c_str());
	if (surface == nullptr)
		std::cout << "surface didnt Load: " << SDL_GetError() << std::endl;
	texture = SDL_CreateTextureFromSurface(window->renderer, surface);
	if (texture == nullptr)
		std::cout << "Texture didnt Load: " << SDL_GetError() << std::endl;
	width = surface->w;
	height = surface->h;
	SDL_FreeSurface(surface);
}

Texture::Texture(std::string title,Window* window,Color chroma)
	:window(window)
{
	SDL_Surface* surface = SDL_LoadBMP(title.c_str());
	if (surface == nullptr)
		std::cout << "surface didnt Load: " << SDL_GetError() << std::endl;
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format
		, chroma.r, chroma.g, chroma.b));
	texture = SDL_CreateTextureFromSurface(window->renderer, surface);
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
	SDL_RenderCopy(window->renderer, texture, NULL,&temp );
}

void Texture::Render(int x, int y, Rect frame)
{
	SDL_Rect source = { frame.x,frame.y,frame.width,frame.height };
	SDL_Rect dest = { x,y,frame.width,frame.height };
	SDL_RenderCopy(window->renderer, texture, &source, &dest);
}
