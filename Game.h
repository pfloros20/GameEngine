#pragma once
#include <SDL.h>
#include <string>

#include "Character.h"
#include "Window.h"

class Game {
public:
	Game();
	~Game();
	Game(const Window& window) = delete;
	Game& operator=(const Window& window) = delete;
	void HandleEvents();
	void Update();
	void Render();
	bool State();

private:
	Window* window;
	bool running = true;
	//TEST CODE
	std::string dir;
	Character* ex;
	//TEST CODE
};