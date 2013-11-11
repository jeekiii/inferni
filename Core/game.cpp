/// *********************16/02/2013***********************///

#include "game.hpp"
#include "display_manager.hpp"

cGame::cGame()
{
    SDL_Init( SDL_INIT_VIDEO );
}

cGame::~cGame()
{
    SDL_Quit();
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
                         "GOOD",
                         "EXIT CLEARLY",
                         NULL);}


int cGame::OnInitCmd()
{
return 0;
}


int cGame::OnInitGlobal()
{
return 0;
}


int cGame::Run()
{
    //init, cmd_line stuff

//init other global vari


    //display code
cDisplayManager display_manager;
display_manager.Display();


return 0;
}



