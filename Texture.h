#pragma once
#include "SDL.h"
#include "Window.h"
#include "Color.h"
#include "Rect.h"
#include <string>

class Texture {
public:
	Texture(std::string title,Window* window);
	Texture(std::string title, Window* window, Color chroma);
	Texture(const Texture& texture) = delete;
	Texture& operator=(const Texture& texture) = delete;
	~Texture();
	void Render(int x,int y);
	void Render(int x, int y,Rect frame);
private:
	Window* window;
	SDL_Texture* texture;
	int width, height;
};