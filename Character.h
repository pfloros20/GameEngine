#pragma once
#include <string>
#include "Sprite.h"
#include <memory>
class Character {
public:
	enum button { UP, DOWN, RIGHT, LEFT };
	Character(int x, int y, std::string sprite,
		int frameWidth,int frameHeight,int columns,int rows,Color chroma);
	void Render();
	void Update(button input);
private:
	std::unique_ptr<Sprite> sprite;
	int x, y;
};