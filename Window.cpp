#include "Window.h"
#include <stdexcept>

SDL_Renderer* Window::renderer = nullptr;

Window::Window(std::string windowTitle, int windowWidth, int windowHeight,bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::string err = "Failed to Initialize SDL: " + std::string(SDL_GetError());
		throw std::runtime_error(err);
	}
	window = SDL_CreateWindow(
		windowTitle.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		windowWidth,
		windowHeight,
		fullscreen ? SDL_WINDOW_FULLSCREEN:SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::string err = "Failed to Create Window: " + std::string(SDL_GetError());
		throw std::runtime_error(err);
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		std::string err = "Failed to Create Renderer: " + std::string(SDL_GetError());
		throw std::runtime_error(err);
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
	if (temp == NULL) {
		std::string err = "Could not Load Window Icon: " + title + " " + std::string(SDL_GetError());
		throw std::runtime_error(err);
	}
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
