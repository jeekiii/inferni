#ifndef _TOOLS_HPP_
	#define _TOOLS_HPP_

#include <SDL2/SDL.h>
typedef struct coord
{
	int x;
	int y;
	int h;
	int w;
}coord;

namespace Tools
{
	bool Collision(coord coord1,coord coord2);
	SDL_Rect CoordToRect(coord c);
	coord RectToCoord(SDL_Rect c);
}


#endif