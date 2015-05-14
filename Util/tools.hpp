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
	bool collision(coord coord1,coord coord2);
	SDL_Rect coordToRect(coord c);
	coord rectToCoord(SDL_Rect c);
}


#endif