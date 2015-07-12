#include "command.hpp"
#include <algorithm>
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

CommandType cCommand::getCommand(std::vector<SDL_Keycode> keys)
{
	CommandType result;
	if(std::find(keys.begin(), keys.end(), up)!= keys.end())
		result = UP;
	if(std::find(keys.begin(), keys.end(), down)!=keys.end())
		result = DOWN;
	if(std::find(keys.begin(), keys.end(), left)!=keys.end())
		result = LEFT;
	if(std::find(keys.begin(), keys.end(), right)!=keys.end())
		result = RIGHT;
	
	return result;
}