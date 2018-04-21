#pragma once
#include"SDL.h"
#include"Window.h"
class Rect {
public:
	Rect(int x, int y, int width, int height);
	SDL_Rect ConvertToSDL();
	bool Collision(const Rect& rect) const;
	void Render();
private:
	int x, y, width, height;
};