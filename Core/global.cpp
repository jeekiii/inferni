/// *********************16/02/2013***********************///


#include "global.hpp"

namespace Global
{
	SDL_Window *screen=NULL;
	SDL_Renderer *renderer=NULL;

	int screenWidth=1000;
	int screenHeight=700;

	std::vector<GameState*> state;

}
