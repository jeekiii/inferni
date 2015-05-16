/// *********************16/02/2013***********************///


#include  <SDL2/SDL.h>
#include "global.hpp"

namespace Global
{
SDL_Window *screen=NULL;
SDL_Renderer *renderer=NULL;

int screen_width=1000;
int screen_height=1000;

std::vector<cGameState*> state;

}
