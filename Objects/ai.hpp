#ifndef AI_HPP
	#define AI_HPP
#include "../Objects/object.hpp"
#include "../Util/command.hpp"
class Ai
{
	protected:
		Object *target_;
	public:
		void GetTarget(Object *target){target_ = target;}
		virtual std::vector<CommandType> GiveCommands()=0;

};

#endif