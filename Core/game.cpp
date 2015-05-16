/// *********************16/02/2013***********************///

#include "game.hpp"
#include "display_manager.hpp"

cGame::cGame()
{
    OnInit();
}

cGame::~cGame()
{
    delete displayManager;
    SDL_Quit();
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "GOOD", "EXIT CLEARLY", NULL);
}


void cGame::OnInit()
{
    SDL_Init( SDL_INIT_VIDEO );
    displayManager = new cDisplayManager;

}


int cGame::Run()
{

    cIntroState *p_intro=new cIntroState;
    p_intro->OnInit();
    Global::state.push_back(p_intro);
	
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



