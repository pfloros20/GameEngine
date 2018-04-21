#pragma once
#include "Texture.h"
#include "Color.h"
class Sprite {
public:
	Sprite(std::string title, int frameWidth, int frameHeight,
		int rows,int columns,Color chroma);
	Sprite(const Sprite& sprite) = delete;
	Sprite& operator=(const Sprite& sprite) = delete;
	~Sprite();
	void Render(int x,int y);
	void RenderFrame(int x, int y, int row,int column);
	void RenderMirrored(int x, int y);
	void SwitchAnimation(int i);
private:
	Texture* sprite;
	int frameWidth;
	int frameHeight;
	int rows, columns;
	int currentPos;
	int currentAnimation;
};