#ifndef _AITUTO_HPP_
	#define _AITUTO_HPP_
#include "../Objects/ai.hpp"
#include "../Util/command.hpp"

class cAITuto: public cAI
{
	private:
	public:
		std::vector<CommandType> GiveCommands();

};

#endif