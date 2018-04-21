#include "Texture.h"
#include <iostream>
#include  "Window.h"
Texture::Texture(std::string title)
{
	SDL_Surface* surface = SDL_LoadBMP(title.c_str());
	if (surface == nullptr)
		std::cout << "surface didnt Load: " << SDL_GetError() << std::endl;
	texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
	if (texture == nullptr)
		std::cout << "Texture didnt Load: " << SDL_GetError() << std::endl;
	width = surface->w;
	height = surface->h;
	SDL_FreeSurface(surface);
}

Texture::Texture(std::string title,Color chroma)
{
	SDL_Surface* surface = SDL_LoadBMP(title.c_str());
	if (surface == nullptr)
		std::cout << "surface didnt Load: " << SDL_GetError() << std::endl;
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format
		, chroma.r, chroma.g, chroma.b));
	texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
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
	SDL_RenderCopy(Window::renderer, texture, NULL,&temp );
}

void Texture::RenderMirrored(int x, int y)
{
	SDL_Rect temp = { x,y,width,height };
	SDL_RenderCopyEx(Window::renderer, texture, NULL, &temp,0,NULL,SDL_FLIP_HORIZONTAL);
}

void Texture::Render(Rect source, Rect dest)
{
	SDL_Rect sdlsource = dest.ConvertToSDL();
	SDL_Rect sdldest = source.ConvertToSDL();
	SDL_RenderCopy(Window::renderer, texture, &sdlsource, &sdldest);
}

void Texture::RenderMirrored(Rect source, Rect dest)
{

	SDL_Rect sdlsource = dest.ConvertToSDL();
	SDL_Rect sdldest = source.ConvertToSDL();
	SDL_RenderCopyEx(Window::renderer, texture, &sdlsource, &sdldest,0,NULL,SDL_FLIP_HORIZONTAL);
}
