/// *********************16/02/2013***********************///
/* This file contains the global variables to be
included into other cpp files
*/

#ifndef _GLOBAL_HPP_
    #define _GLOBAL_HPP_

#include "game_state.hpp"
#include <vector>
#include <SDL.h>
namespace Global
{
extern SDL_Window *screen;
extern SDL_Renderer *renderer;

extern int screen_width;
extern int screen_height;



extern std::vector<cGameState*> state;

}



#endif
