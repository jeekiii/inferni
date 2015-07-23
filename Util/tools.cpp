#include "tools.hpp"

bool Tools::Collision(coord coord1,coord coord2)
{
	if (coord1.x+coord1.w < coord2.x)
		return false;
    if (coord1.x > coord2.x+coord2.w)
    	return false;
    if (coord1.y+coord1.h < coord2.y)
    	return false;
    if (coord1.y > coord2.y+coord1.h)
    	return false;

    return true; // boxes overlap
}

coord Tools::RectToCoord(SDL_Rect c)
{
	coord result; 
	result.x = c.x;
	result.y = c.y;
	result.w = c.w;
	result.h = c.h;
	return result;
}

SDL_Rect Tools::CoordToRect(coord c)
{
	SDL_Rect result;
	result.x = c.x;
	result.y = c.y;
	result.w = c.w;
	result.h = c.h;
	return result;
}