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
		coord GetGroundHitbox();
		coord GetAboveHitbox();
		void OnInit(int positionX, int positionY);
		void OnRender(coord positionMap);
		void OnMove(std::vector<cObject*> *objects);
		ReactionType Reaction(cObject *object);
		void OnCommand(std::vector<SDL_Keycode> keys, std::vector<cObject*> *objects);
};


#endif