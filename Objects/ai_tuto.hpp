#ifndef AITUTO_HPP
	#define AITUTO_HPP
#include "../Objects/ai.hpp"
#include "../Util/command.hpp"

class AiTuto: public Ai
{
	private:
	public:
		AiTuto(Object *controlled);
		std::vector<CommandType> GiveCommands();

};

#endif