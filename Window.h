#pragma once
#include <SDL.h>
#include <string>

class Window {
public:
	Window(std::string windowTitle, int windowWidth, int windowHeight,bool fullscreen);
	Window(const Window& window) = delete;
	Window& operator=(const Window& window) = delete;
	~Window();
	void SetWindowIcon(std::string title);
	void ClearWindow();
	void PresentWindow();
	SDL_Renderer* renderer;
private:
	SDL_Window* window;
};
