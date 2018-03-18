#pragma once
#include <SDL.h>
#include <string>
#include "Texture.h"
class Character {
public:
	Character(int x,int y,std::string sprite, SDL_Renderer* renderer);
	Character(int x, int y, std::string sprite, SDL_Renderer* renderer,
		int transparentRed, int transparentBlue, int transparentGreen);
	~Character();
	void Render();
	void Update(std::string dir);
private:
	int x, y;
	SDL_Renderer* renderer;
	Texture* texture=nullptr;
};