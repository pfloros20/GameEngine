#pragma once
#include <SDL.h>
#include <string>
class Game {
public:
	Game(std::string windowTitle, int windowWidth, int windowHeight);
	~Game();
	void HandleEvents();
	void Update();
	void Render();
	bool State();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool running = true;
};