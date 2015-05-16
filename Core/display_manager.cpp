// is it really worth a class?

#include "display_manager.hpp"

cDisplayManager::cDisplayManager()
{
    Global::screen= SDL_CreateWindow("Our Game",100,100,Global::screen_width, Global::screen_height,0);
    Global::renderer=SDL_CreateRenderer(Global::screen,-1,0);

}


cDisplayManager::~cDisplayManager()
{
    SDL_DestroyWindow(Global::screen);
    SDL_DestroyRenderer(Global::renderer);
}