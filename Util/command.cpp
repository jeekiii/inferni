#include "command.hpp"
#include <algorithm>
cCommand::cCommand()
{
	up = SDLK_z;
	down = SDLK_s;
	left = SDLK_q;
	right = SDLK_d;
	attack = SDLK_e;
	possess = SDLK_SPACE;
}

cCommand::~cCommand()
{

}

std::vector<CommandType> cCommand::GetCommand()
{
	std::vector<CommandType> result = commands;
	for(unsigned int i = 0; i < toRemove.size(); i++)
	{
		if(std::find(commands.begin(), commands.end(), toRemove.at(i)) != commands.end())
			commands.erase(std::find(commands.begin(), commands.end(), toRemove.at(i)));
	}
	toRemove.clear();
	return result;
}

void cCommand::AddCommand(SDL_Keycode key)
{    
	CommandType temp;       
	if(key == up)
		temp = UP;
	if(key == down)
		temp = DOWN;
	if(key == left)
		temp = LEFT;
	if(key == right)
		temp = RIGHT;
	if(key == attack)
		temp = ATTACK;
	if(key == possess)
		temp = SPECIAL;

	if(std::find(commands.begin(), commands.end(), temp) == commands.end())
	{
		commands.push_back(temp);
	}

}

void cCommand::RemoveCommand(SDL_Keycode key)
{
	if(key == up)
		toRemove.push_back(UP);
	if(key == down)
		toRemove.push_back(DOWN);
	if(key == left)
		toRemove.push_back(LEFT);
	if(key == right)
		toRemove.push_back(RIGHT);
	if(key == attack)
		toRemove.push_back(ATTACK);
	if(key == possess)
		toRemove.push_back(SPECIAL);
}