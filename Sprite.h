#pragma once
#include "Texture.h"
#include "Color.h"
class Sprite {
public:
	Sprite(std::string title,Window* window, int frameWidth, int frameHeight,
		int rows,int columns,Color chroma);
	Sprite(const Sprite& sprite) = delete;
	Sprite& operator=(const Sprite& sprite) = delete;
	~Sprite();
	void Render(int x,int y);
	void SwitchAnimation(int i);
private:
	Texture* sprite;
	int frameWidth;
	int frameHeight;
	int rows, columns;
	int currentPos;
	int currentAnimation;
};