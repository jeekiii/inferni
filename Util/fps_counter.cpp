
#include "fps_counter.hpp"
#include <SDL2/SDL.h>


void FpsCounter::startCount()
{
	initTime=SDL_GetTicks();
}


void FpsCounter::checkFPS()
{
	timeFlag=SDL_GetTicks();
	int difference=timeFlag-initTime;

	if(difference<timePerFrame)
	    SDL_Delay(timePerFrame-difference);

}

void FpsCounter::getNewTick()
{
    initTime=SDL_GetTicks();
}
