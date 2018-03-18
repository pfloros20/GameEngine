#pragma once
#include <SDL.h>
#include <string>
class Character {
public:
	Character(int x,int y,int width,int height,
		SDL_Surface* sprite, SDL_Renderer* renderer);
	~Character();
	void Render();
	void Update(std::string dir);
private:
	SDL_Rect characterRect;
	SDL_Renderer* renderer;
	SDL_Surface* sprite=nullptr;
	SDL_Texture* texture=nullptr;
};