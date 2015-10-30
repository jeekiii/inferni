#include "tools.hpp"

bool Tools::collision(Coord position1,Coord position2)
{
	if (position1.x+position1.w < position2.x)
		return false;
    if (position1.x > position2.x+position2.w)
    	return false;
    if (position1.y+position1.h < position2.y)
    	return false;
    if (position1.y > position2.y+position1.h)
    	return false;

    return true; // boxes overlap
}

Coord Tools::rectToCoord(SDL_Rect c)
{
	Coord result; 
	result.x = c.x;
	result.y = c.y;
	result.w = c.w;
	result.h = c.h;
	return result;
}

SDL_Rect Tools::coordToRect(Coord c)
{
	SDL_Rect result;
	result.x = c.x;
	result.y = c.y;
	result.w = c.w;
	result.h = c.h;
	return result;
}