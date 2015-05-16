/// *********************16/02/2013***********************///
/* The Game core class used to run the game
you can manage the whole game, do cmd stuffs here
*/

#ifndef _GAME_HPP_
    #define _GAME_HPP_
#include <SDL2/SDL.h>
#include <vector>
#include "global.hpp"
#include "game_state.hpp"
#include "intro_state.hpp"
#include "display_manager.hpp"

class cGame
{
	private:
		cDisplayManager *displayManager;
    public:
        cGame();
        ~cGame();

        void OnInit();
        int Run();   //NOTE: from main, it enters here


};


#endif
