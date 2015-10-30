/// *********************16/02/2013***********************///
/* The Game core class used to run the game
you can manage the whole game, do cmd stuffs here
*/

#ifndef GAME_HPP
    #define GAME_HPP

#include "display_manager.hpp"

class Game
{
	private:
		DisplayManager *displayManager_;
    public:
        Game();
        ~Game();

        int run();   //NOTE: from main, it enters here


};


#endif
