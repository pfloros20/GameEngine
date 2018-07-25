#include "Game.h"
#include "SDL.h"
bool check = false;
std::unique_ptr<std::runtime_error> e;
Game::Game(){
	window = std::make_unique<Window>("Window", 800, 600, false);
	
}

void Game::HandleEvents()
{
	SDL_Event event;
	while(SDL_PollEvent(&event)!=0)
		switch (event.type) {
		case SDL_QUIT:
			running = false;
			break;
		}
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_RIGHT]) {
	}
	if (state[SDL_SCANCODE_LEFT]) {
	}
	if (state[SDL_SCANCODE_UP]) {
	}
	if (state[SDL_SCANCODE_DOWN]) {
	}
}

void Game::Update()
{
}

void Game::Render()
{
	window->ClearWindow();
	//render stuff
	window->PresentWindow();
}

bool Game::State()
{
	return running;
}
