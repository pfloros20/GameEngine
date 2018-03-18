#pragma once
#include "SDL.h"
#include <string>

class Texture {
public:
	Texture(std::string title,SDL_Renderer* renderer);
	Texture(std::string title, SDL_Renderer* renderer,
		int transparentRed,int transparentBlue,int transparentGreen);
	~Texture();
	void Render(int x,int y);
private:
	SDL_Texture* texture;
	SDL_Renderer* renderer;
	int width, height;
};