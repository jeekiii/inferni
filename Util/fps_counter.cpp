
#include "fps_counter.hpp"
#include <SDL2/SDL.h>


void cFPSCounter::StartCount()
{
m_init_time=SDL_GetTicks();
}


void cFPSCounter::CheckFPS()
{
	m_time_flag=SDL_GetTicks();
	int difference=m_time_flag-m_init_time;

	if(difference<m_time_per_frame)
	    SDL_Delay(m_time_per_frame-difference);

}

void cFPSCounter::GetNewTick()
{
    m_init_time=SDL_GetTicks();
}
