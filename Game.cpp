#pragma once
#include "Game.h"
#include <iostream>
Game::Game(){
	window =new Window("Moving Character", 800, 600, true);
	//TEST CODE
	ex =new Character(0, 0, "Resource Files/spooooooky.bmp",
		window->renderer,35,35,35);
	//TEST CODE
}

Game::~Game()
{
	delete window;
	window = nullptr;
	//TEST CODE
	delete ex;
	//TEST CODE
}

void Game::HandleEvents()
{
	SDL_Event event;
	while(SDL_PollEvent(&event)!=0)
		switch (event.type) {
		case SDL_QUIT:
				running = false;
				break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
				case SDLK_DOWN:
					std::cout << "Down" << std::endl;
					dir = "DOWN";
					break;
				case SDLK_UP:
					std::cout << "Up" << std::endl;
					dir = "UP";
					break;
				case SDLK_LEFT:
						std::cout << "Left" << std::endl;
						dir = "LEFT";
						break;
				case SDLK_RIGHT:
						std::cout << "Right" << std::endl;
						dir = "RIGHT";
						break;
			}
			break;
		case SDL_KEYUP:
			dir = "NONE";
			break;
		}
}

void Game::Update()
{
	ex->Update(dir);
}

void Game::Render()
{
	window->ClearWindow();
	//render stuff
	//TEST CODE
	ex->Render();
	//TEST CODE
	window->PresentWindow();
}

bool Game::State()
{
	return running;
}
