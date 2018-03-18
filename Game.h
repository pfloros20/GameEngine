#pragma once
#include <SDL.h>
#include <string>

#include "Character.h"

class Game {
public:
	Game(std::string windowTitle, int windowWidth, int windowHeight);
	~Game();
	void HandleEvents();
	void Update();
	void Render();
	bool State();

	SDL_Renderer* renderer;
private:
	SDL_Window* window;
	bool running = true;
	//TEST CODE
	std::string dir;
	SDL_Surface* temp;
	Character* ex;
	//TEST CODE
};