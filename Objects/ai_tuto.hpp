#ifndef AITUTO_HPP
	#define AITUTO_HPP
#include "../Objects/ai.hpp"
#include "../Util/command.hpp"

class AiTuto: public Ai
{
	private:
	public:
		std::vector<CommandType> GiveCommands();

};

#endif