#pragma once
#include "Game.h"
#include <iostream>
Game::Game(std::string windowTitle,int windowWidth,int windowHeight){
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "Failed to Initialize SDL: " << SDL_GetError() << std::endl;
		//TO-DO:Handle Error
	}
	window = SDL_CreateWindow(
		windowTitle.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		windowWidth,
		windowHeight,
		SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cout << "Failed to Create Window: " << SDL_GetError() << std::endl;
		//TO-DO:Handle Error
	}
	renderer = SDL_CreateRenderer(window,-1,0);
	if (renderer == nullptr) {
		std::cout << "Failed to Create Renderer: " << SDL_GetError() << std::endl;
		//TO-DO:Handle Error
	}

	//TEST CODE
	temp=SDL_LoadBMP("Resource Files/spooooooky.bmp");
	ex =new Character(0, 0, 248, 376, temp, renderer);
	//TEST CODE
}
Game::~Game() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
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
	SDL_RenderClear(renderer);
	//render stuff
	//TEST CODE
	ex->Render();
	//TEST CODE
	SDL_RenderPresent(renderer);
}

bool Game::State()
{
	return running;
}
