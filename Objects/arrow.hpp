
#ifndef _ARROW_HPP_
	#define _ARROW_HPP_
#include "../Objects/object.hpp"
#include "../Objects/player.hpp"


class cArrow:public cObject
{
	private:
		coord toMove;
	public:
		cArrow();
		~cArrow();
		void OnInit(int positionX, int positionY);
		void OnRender(coord positionMap);
		void OnMove(std::vector<cObject*> *objects);
		void Launch(coord direction);
		void TakeDamage(int amount);
		ReactionType Reaction(cObject *object, bool ground);
};


#endif