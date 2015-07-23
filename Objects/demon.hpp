#ifndef _DEMON_HPP_
	#define _DEMON_HPP_
#include "../Objects/object.hpp"
#include "../Objects/possessable.hpp"
#include "../Util/command.hpp"

class cPlayer;
class cDemon:public cPossessable
{
	private:
		cPossessable* target;
	public:
		cDemon();
		~cDemon();
		void OnInit(int positionX, int positionY);
		void OnRender(coord positionMap);
		void OnMove(std::vector<cObject*> *objects);
		void TakeDamage(int amount){;}
		ReactionType Reaction(cObject *object, bool ground);
		void OnCommand(std::vector<cObject*> *objects, std::vector<CommandType> commands);
		void SetPosition(coord position);
		cPossessable* GetTarget();
};

#endif