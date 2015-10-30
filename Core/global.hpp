/// *********************16/02/2013***********************///
/* This file contains the global variables to be
included into other cpp files
*/

#ifndef GLOBAL_HPP
    #define GLOBAL_HPP

#include "game_state.hpp"
#include <vector>
#include <SDL2/SDL.h>
namespace Global
{
	extern SDL_Window *screen;
	extern SDL_Renderer *renderer;
	extern int screenWidth;
	extern int screenHeight;



	extern std::vector<GameState*> state;

}



#endif
