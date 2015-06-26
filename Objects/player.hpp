#ifndef _PLAYER_HPP_
	#define _PLAYER_HPP_
#include "../Objects/object.hpp"

class cPlayer:public cObject
{
	private:
		cObject *possessed;
	public:
		cPlayer();
		~cPlayer();
		void OnInit();
		void OnRender();
		void OnMove();
		void Reaction(cObject *object);
};


#endif