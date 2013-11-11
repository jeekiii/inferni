/// *********************16/02/2013***********************///


#include  <SDL.h>
#include "global.hpp"

namespace Global
{
SDL_Window *screen=NULL;
SDL_Renderer *renderer=NULL;

int screen_width=800;
int screen_height=600;

std::vector<cGameState*> state;

}
