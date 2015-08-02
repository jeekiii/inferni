#include "ai_tuto.hpp"

std::vector<CommandType> cAITuto::GiveCommands()
{
	std::vector<CommandType> result;
	result.push_back(ATTACK);
	return result;
}
