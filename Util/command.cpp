#include "command.hpp"
#include <algorithm>
Command::Command()
{
	up_ = SDLK_z;
	down_ = SDLK_s;
	left_ = SDLK_q;
	right_ = SDLK_d;
	attack_ = SDLK_e;
	possess_ = SDLK_SPACE;
}

Command::~Command()
{

}

std::vector<CommandType> Command::getCommand()
{
	std::vector<CommandType> result = commands_;
	for(unsigned int i = 0; i < toRemove_.size(); i++)
	{
		if(std::find(commands_.begin(), commands_.end(), toRemove_.at(i)) != commands_.end())
			commands_.erase(std::find(commands_.begin(), commands_.end(), toRemove_.at(i)));
	}
	toRemove_.clear();
	return result;
}

void Command::addCommand(SDL_Keycode key)
{    
	CommandType temp;       
	if(key == up_)
		temp = UP_COMMAND;
	if(key == down_)
		temp = DOWN_COMMAND;
	if(key == left_)
		temp = LEFT_COMMAND;
	if(key == right_)
		temp = RIGHT_COMMAND;
	if(key == attack_)
		temp = ATTACK_COMMAND;
	if(key == possess_)
		temp = SPECIAL_COMMAND;

	if(std::find(commands_.begin(), commands_.end(), temp) == commands_.end())
	{
		commands_.push_back(temp);
	}

}

void Command::removeCommand(SDL_Keycode key)
{
	if(key == up_)
		toRemove_.push_back(UP_COMMAND);
	if(key == down_)
		toRemove_.push_back(DOWN_COMMAND);
	if(key == left_)
		toRemove_.push_back(LEFT_COMMAND);
	if(key == right_)
		toRemove_.push_back(RIGHT_COMMAND);
	if(key == attack_)
		toRemove_.push_back(ATTACK_COMMAND);
	if(key == possess_)
		toRemove_.push_back(SPECIAL_COMMAND);
}