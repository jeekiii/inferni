#ifndef _PLAYER_HPP_
	#define _PLAYER_HPP_
#include "../Util/command.hpp"
#include "../Objects/possessable.hpp"
#include <SDL2/SDL.h>

class cPlayer:public cObject
{
	private:
		cPossessable *possessed;
		cCommand *cmd;
	public:
		cPlayer();
		~cPlayer();
		void OnInit();
		void OnRender();
		void OnMove();
		void Reaction(cObject *object);
		void OnCommand(SDL_Keycode key);
};


#endif