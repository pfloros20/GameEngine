#pragma once
#include "SDL.h"
#include "Window.h"
#include "Color.h"
#include "Rect.h"
#include <string>

class Texture {
public:
	Texture(std::string title);
	Texture(std::string title, Color chroma);
	Texture(const Texture& texture) = delete;
	Texture& operator=(const Texture& texture) = delete;
	~Texture();
	void Render(int x,int y);
	void Render(Rect source,Rect dest);
private:
	SDL_Texture* texture;
	int width, height;
};