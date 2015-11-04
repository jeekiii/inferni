#include "ai_tuto.hpp"

AiTuto::AiTuto(Object *controlled)
{
	controlled_ = controlled;
}

std::vector<CommandType> AiTuto::GiveCommands()
{
	std::vector<CommandType> result;
	if(target_->getPosition().x < controlled_->getPosition().x)
		result.push_back(TURN_RIGHT_COMMAND);
	else
		result.push_back(TURN_LEFT_COMMAND);
	result.push_back(ATTACK_COMMAND);
	return result;
}
