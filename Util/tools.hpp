#ifndef TOOLS_HPP
	#define TOOLS_HPP

#include <SDL2/SDL.h>
typedef struct Coord
{
	int x;
	int y;
	int h;
	int w;
}Coord;

namespace Tools
{
	bool collision(Coord position1,Coord position2);
	SDL_Rect coordToRect(Coord c);
	Coord rectToCoord(SDL_Rect c);
}


#endif