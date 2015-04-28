/// *********************16/02/2013***********************///


#include "display_manager.hpp"
#include "global.hpp"
#include "intro_state.hpp"
#include <SDL2/SDL.h>

cDisplayManager::cDisplayManager()
{
    Global::screen= SDL_CreateWindow("Our Game",100,100,Global::screen_width, Global::screen_height,SDL_WINDOW_OPENGL);
    Global::renderer=SDL_CreateRenderer(Global::screen,-1,SDL_RENDERER_SOFTWARE);
    
    cIntroState *p_intro=new cIntroState;
    p_intro->OnInit();
    Global::state.push_back(p_intro);
}


cDisplayManager::~cDisplayManager()
{
    SDL_DestroyWindow(Global::screen);
    SDL_DestroyRenderer(Global::renderer);
}


// Iterate through each game states
// don't modify this function
// you should focus on each function in specific states
int cDisplayManager::Display()
{
    while (!Global::state.empty())
    {
            Global::state.back()->OnEvent();
        if (!Global::state.empty())
            Global::state.back()->OnRender();
        if (!Global::state.empty())
            Global::state.back()->OnUpdate();
    }

   return 0;
}


int cDisplayManager::PushScreen()
{

return 0;
}


int cDisplayManager::PopScreen()
{

return 0;
}
