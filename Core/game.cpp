/// *********************16/02/2013***********************///

#include "game.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include "global.hpp"
#include "game_state.hpp"
#include "intro_state.hpp"


Game::Game()
{
    SDL_Init( SDL_INIT_VIDEO );
    displayManager_ = new DisplayManager;
}

Game::~Game()
{
    delete displayManager_;
    SDL_Quit();
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "GOOD", "EXIT CLEARLY", NULL);
}




int Game::run()
{

    IntroState *p_intro=new IntroState;
    //p_intro->OnInit();
    Global::state.push_back(p_intro);
	
    while (!Global::state.empty())
    {
            Global::state.back()->onEvent();
        if (!Global::state.empty())
            Global::state.back()->onRender();
        if (!Global::state.empty())
            Global::state.back()->onUpdate();
    }


    return 0;
}



