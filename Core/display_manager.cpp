// is it really worth a class?

#include "display_manager.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include "global.hpp"
#include "game_state.hpp"
#include "intro_state.hpp"

DisplayManager::DisplayManager()
{
    Global::screen= SDL_CreateWindow("Our Game",100,100,Global::screenWidth, Global::screenHeight,0);
    Global::renderer=SDL_CreateRenderer(Global::screen,-1,0);

}


DisplayManager::~DisplayManager()
{
    SDL_DestroyWindow(Global::screen);
    SDL_DestroyRenderer(Global::renderer);
}