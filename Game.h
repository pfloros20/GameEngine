#pragma once
#include "SDL.h"
#include <string>
#include <memory>
#include "Character.h"
#include "Window.h"
#include "Audio.h"
#include "Font.h"

class Game {
public:
	Game();
	void HandleEvents();
	void Update();
	void Render();
	bool State();

private:
	std::unique_ptr<Window> window;
	bool running = true;
};