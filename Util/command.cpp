#include "command.hpp"

cCommand::cCommand()
{
	up = SDLK_z;
	down = SDLK_s;
	left = SDLK_q;
	right = SDLK_d;
}

cCommand::~cCommand()
{

}

CommandType cCommand::getCommand(SDL_Keycode key)
{
	CommandType result;
	if(key == up)
		result = UP;
	if(key == down)
		result = DOWN;
	if(key == left)
		result = LEFT;
	if(key == right)
		result = RIGHT;
	
	return result;
}