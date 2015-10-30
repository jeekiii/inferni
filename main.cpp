/// *********************16/02/2013***********************///
/* Enters the game main loop, into function Game::Run
Unless otherwise required, normally you will never modify this file
*/


#include <SDL2/SDL.h>
#include "Core/global.hpp"
#include "Core/game.hpp"

int main ( int argc, char** argv )
{
	Game theGame;
	theGame.run();
	return 0;
}
