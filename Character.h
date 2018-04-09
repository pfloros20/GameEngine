#pragma once
#include <SDL.h>
#include <string>
#include "Sprite.h"
class Character {
public:
	Character(int x, int y, std::string sprite,
		int frameWidth,int frameHeight,int columns,int rows,Color chroma);
	~Character();
	void Render();
	void Update();
	int x, y;
private:
	Sprite* sprite=nullptr;
};