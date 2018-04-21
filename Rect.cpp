#include "Rect.h"

Rect::Rect(int x, int y, int width, int height)
	:x(x),y(y),width(width),height(height)
{
}

SDL_Rect Rect::ConvertToSDL()
{
	return{ x,y,width,height };
}
//AABB Collision
bool Rect::Collision(const Rect & rect) const
{
	return !(y>rect.y+rect.height
		|| y+height<rect.y
		|| x>rect.x+rect.width
		|| x+width<rect.x);
}

void Rect::Render()
{
	SDL_Rect rect = ConvertToSDL();
	SDL_RenderDrawRect(Window::renderer,&rect);
}
