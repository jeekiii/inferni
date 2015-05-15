/// *********************16/02/2013***********************///
/* This class manages the display when play enters the game
*/


#ifndef _DISPLAY_MANAGER_HPP_
    #define _DISPLAY_MANAGER_HPP_

#include <SDL2/SDL.h>
#include <vector>
#include "global.hpp"
#include "game_state.hpp"
#include "intro_state.hpp"


class cDisplayManager
{
    private:

    public:
        cDisplayManager();
        ~cDisplayManager();

        int PushScreen();
        int PopScreen();
        int Display();  //game enters here from cGame::Run()


};


#endif
