#include "Window.h"
#include <iostream>

SDL_Renderer* Window::renderer = nullptr;

Window::Window(std::string windowTitle, int windowWidth, int windowHeight,bool fullscreen)
{
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
		fullscreen ? SDL_WINDOW_FULLSCREEN:SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cout << "Failed to Create Window: " << SDL_GetError() << std::endl;
		//TO-DO:Handle Error
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		std::cout << "Failed to Create Renderer: " << SDL_GetError() << std::endl;
		//TO-DO:Handle Error
	}

}

Window::~Window()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Window::SetWindowIcon(std::string title)
{
	SDL_Surface* temp = SDL_LoadBMP(title.c_str());
	if (temp == NULL)
		std::cout << "Could not Load Window Icon: " << SDL_GetError();
	SDL_SetWindowIcon(window, temp);
}

void Window::ClearWindow()
{
	SDL_RenderClear(renderer);
}

void Window::PresentWindow()
{
	SDL_RenderPresent(renderer);
}
