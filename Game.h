#pragma once
#include <SDL.h>
#include <string>

#include "Character.h"
#include "Window.h"
#include "Audio.h"

class Game {
public:
	Game();
	~Game();
	Game(const Game& game) = delete;
	Game& operator=(const Game& game) = delete;
	void HandleEvents();
	void Update();
	void Render();
	bool State();

private:
	Window* window;
	bool running = true;
};