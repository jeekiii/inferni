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
		void OnMove(std::vector<cObject*> *objects);
		ReactionType Reaction(cObject *object);
		void OnCommand(std::vector<SDL_Keycode> keys, std::vector<cObject*> *objects);
};


#endif