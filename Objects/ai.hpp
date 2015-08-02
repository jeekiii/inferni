#ifndef _AI_HPP_
	#define _AI_HPP_
#include "../Objects/object.hpp"
#include "../Util/command.hpp"
class cAI
{
	protected:
		cObject *target;
	public:
		void GetTarget(cObject *target){this->target = target;}
		virtual std::vector<CommandType> GiveCommands()=0;

};

#endif