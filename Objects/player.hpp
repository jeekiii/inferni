#ifndef _PLAYER_HPP_
	#define _PLAYER_HPP_
#include "../Util/command.hpp"
#include "../Objects/possessable.hpp"
#include <SDL2/SDL.h>
#include "../Objects/demon.hpp"

class cPossessable;//solves mutual inclusion

class cPlayer:public cObject
{
	private:
		cPossessable *possessed;
		cDemon *demon;
		cCommand *cmd;
		bool demonForm;
		int specialCD;
		int specialCurrentCD;
	public:
		cPlayer();
		~cPlayer();
		void OnInit(int positionX, int positionY);
		void OnRender(coord positionMap);
		void OnMove(std::vector<cObject*> *objects);
		ReactionType Reaction(cObject *object, bool ground);
		void OnCommand(std::vector<cObject*> *objects, std::vector<CommandType> keys);
		void TakeDamage(int amount);
		void Possess(cPossessable *target);
		void LeaveBody();
};


#endif