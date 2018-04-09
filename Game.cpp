#pragma once
#include "Game.h"
#include <iostream>
Game::Game(){
	window =new Window("Moving Character", 448, 448, false);
	window->SetWindowIcon("Resource Files/spooooooky.bmp");
}

Game::~Game()
{
	delete window;
	window = nullptr;
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
