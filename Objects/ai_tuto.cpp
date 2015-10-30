#include "ai_tuto.hpp"

std::vector<CommandType> AiTuto::GiveCommands()
{
	std::vector<CommandType> result;
	result.push_back(ATTACK_COMMAND);
	return result;
}
